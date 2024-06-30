#include "libft.h"
#include "pipex.h"
#include <stdlib.h>

t_command	*command_create(char *raw_command, int infd, int outfd)
{
	t_command	*command;
	char			**arguments;
	char			*executable;

	command = malloc(sizeof (t_command));
	if (!command)
		return (NULL);
	arguments = ft_split(raw_command, ' ');
	if (!arguments)
	{
		command_destroy(command);
		return (NULL);
	}
	executable = ft_strjoin("/", arguments[0]);
	if (!executable)
	{
		command_destroy(command);
		return (NULL);
	}
	command->executable = executable;
	command->arguments = arguments;
	command->infd = infd;
	command->outfd = outfd;
	return (command);
}
