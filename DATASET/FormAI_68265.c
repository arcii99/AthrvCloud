//FormAI DATASET v1.0 Category: Recursive ; Style: complex
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

void recursive_function(int count);

int main(int argc, char** argv) {
  
  recursive_function(0);

  return 0;
}

void recursive_function(int count) {
  
  int i;
  char buffer[20];
  memset(buffer, 0, sizeof(buffer));

  printf("Recursive Function Call Number: %d\n", count);

  if (count <= 5) {
    
    for (i = 0; i < count; i++) {
        printf(" ");   
    }
    
    printf("Enter a string: ");
    scanf("%s", buffer);

    // Recursive call
    recursive_function(count + 1);
  }
  
  return;
}