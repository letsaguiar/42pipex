#include <stdlib.h>

void  paths_destroy(char **paths)
{
  int i;

  i = 0;
  while (paths[i])
  {
    free(paths[i]);
    i += 1;
  }
  free(paths);
}
