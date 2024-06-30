#ifndef PIPEX_H
# define PIPEX_H

# define ERROR_TOO_FEW_ARGUMENTS 1
# define ERROR_ENVIRONMENT 2
# define ERROR_FILE 3
# define ERROR_INTERNAL 4

typedef struct s_command
{
	char	*executable;
	char	**arguments;
	int		infd;
	int		outfd;
}	t_command;

t_command	*command_create(char	*raw_command, int infd, int outfd);

void			command_destroy(t_command *command);

int				command_execute(t_command *command, char **paths);

int				command_fork(t_command *command, char **paths);

char			**paths_create(char **envp);

char			**paths_destroy(char **paths);

#endif
