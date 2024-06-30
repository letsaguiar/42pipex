#ifndef PIPEX_H

typedef struct s_command
{
	char	*executable;
	char	**arguments;
	int		infd;
	int		outfd;
}	t_command;

t_command	*command_create(char	*raw_command, int infd, int outfd);

void			command_destroy(t_command *command);

char  **paths_create(char **envp);

char  **paths_destroy(char **paths);

int   command_execute(char *command, char **paths, int *infd, int *outfd);

#endif // !PIPEX_H
