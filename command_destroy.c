#include "pipex.h"
#include <stdlib.h>
#include <unistd.h>

void	command_destroy(t_command *command)
{
	int	i;

	if (command->infd != STDIN_FILENO)
		close(command->infd);
	if (command->outfd != STDOUT_FILENO)
		close(command->outfd);
	if (command->executable)
		free(command->executable);
	if (command->arguments)
	{
		i = 0;
		while (command->arguments[i])
		{
			free(command->arguments[i]);
			i += 1;
		}

		free(command->arguments);
	}
	
}
