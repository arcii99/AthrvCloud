//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main()
{
  char buffer[BUFFER_SIZE];
  FILE* pipe = popen("free", "r");
  if (pipe == NULL) 
  {
       printf("Error: Failed to open pipe\n");
       return 1;
  }

  while (fgets(buffer, BUFFER_SIZE, pipe))
  {
       printf("%s", buffer);
  }
  pclose(pipe);

  return 0;
}