#include "pipex.h"
#include "libft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

int pipex(char **args, char **paths, int *infd, int *outfd)
{
  pid_t pid;
  int   pipefd[2];

  if (pipe(pipefd) < 0)
    return (-1);
  pid = fork();
  if (pid < 0)
    return (-1);
  else if (pid == 0)
  {
    close(pipefd[0]);
    command_execute(args[2], paths, infd, &pipefd[1]);
    close(pipefd[1]);
  }
  else
  {
    close(pipefd[1]);
    command_execute(args[3], paths, &pipefd[0], outfd);
    close(pipefd[0]);
  }

  return (-1);
}

int main(int argc, char **argv, char **envp)
{
  if (argc < 5)
    return (-1);

  char **paths = paths_create(envp);
  int  infd = open(argv[1], O_RDONLY);
  int  outfd = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);

  if (!pipex(argv, paths, &infd, &outfd))
  {
    paths_destroy(paths);
    close(infd);
    close(outfd);
    return (1);
  }

  return (0);
}
