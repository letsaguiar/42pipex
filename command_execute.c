#include "libft.h"
#include "pipex.h"
#include <unistd.h>

int command_execute(char *command, char **paths, int *infd, int *outfd)
{
  char  *cmd;
  char  *cc;
  char  **args;

  if (infd)
    dup2(*infd, STDIN_FILENO);
  if (outfd)
    dup2(*outfd, STDOUT_FILENO);
  args = ft_split(command, ' ');
  cc = ft_strjoin("/", args[0]);
  while (*paths)
  {
    cmd = ft_strjoin(*paths, cc);
    execv(cmd, args);
    free(cmd);
    paths++;
  }

  free(cc);
  paths_destroy(args);
  return (-1);
}
