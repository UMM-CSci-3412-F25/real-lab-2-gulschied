#include <stdio.h>
#include <stdlib.h>

#include "disemvowel.h"

int main(int argc, char *argv[]) {
  char *line;
  size_t size;
  
  size = 100;
  line = (char*) malloc (size + 1);

  while (getline(&line, &size, stdin) > 0) {
    char *ans = disemvowel(line);
    printf("Is the string <%s> disemvoweled? %s\n", line, ans);
    free(ans);
  }

  free(line);
  return 0;
}
