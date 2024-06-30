#include "libft.h"
#include "pipex.h"
#include <unistd.h>

int command_execute(t_command *command, char **paths)
{
  char  *cmd;

  if (command->infd != STDIN_FILENO)
    dup2(command->infd, STDIN_FILENO);
  if (command->outfd != STDOUT_FILENO)
    dup2(command->outfd, STDOUT_FILENO);
  while (*paths)
  {
    cmd = ft_strjoin(*paths, command->executable);
    execv(cmd, command->arguments);
    free(cmd);
    paths++;
  }
  return (-1);
}
