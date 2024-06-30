#include "libft.h"

char  **paths_create(char **envp)
{
  int i;

  i = 0;
  while (envp[i] && !(ft_strnstr(envp[i], "PATH=", 5)))
    i += 1;
  return (ft_split(envp[i] + 5, ':'));
}
