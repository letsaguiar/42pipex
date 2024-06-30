#include "pipex.h"
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

int	pipex(char **args, char **paths, int infd, int outfd)
{
	pid_t			first_pid;
	pid_t			second_pid;
	t_command	*first_command;
	t_command	*second_command;
	int				pipefd[2];

	if (pipe(pipefd) < 0)
		return (ERROR_INTERNAL);
	first_pid = fork();
	first_command = command_create(args[2], infd, pipefd[1]);
	if (first_pid == 0)
	{
		close(pipefd[0]);
		command_execute(first_command, paths);
		close(pipefd[1]);
	}

	second_pid = fork();
	second_command = command_create(args[3], pipefd[0], outfd);
	if (second_pid == 0)
	{
		close(pipefd[1]);
		command_execute(second_command, paths);
		close(pipefd[0]);
	}

	close(pipefd[0]);
	close(pipefd[1]);
	command_destroy(first_command);
	command_destroy(second_command);
	return (0);
}

int main(int argc, char **argv, char **envp)
{
	char			**paths;
	int				infd;
	int				outfd;

  if (argc < 5)
    return (ERROR_TOO_FEW_ARGUMENTS);

	paths = paths_create(envp);
	if (!paths)
		return (ERROR_ENVIRONMENT);

	if (
		(infd = open(argv[1], O_RDONLY)) < 0
		|| (outfd = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644)) < 0
	)
	{
		paths_destroy(paths);
		return (ERROR_FILE);
	}

	pipex(argv, paths, infd, outfd);

	paths_destroy(paths);
	close(infd);
	close(outfd);
}
