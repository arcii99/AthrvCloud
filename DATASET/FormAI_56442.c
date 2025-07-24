//FormAI DATASET v1.0 Category: Compression algorithms ; Style: immersive
#include<stdio.h>
#include<stdlib.h>

// Structure to store the unique compressed data
struct Compressed {
   char letter;
   int count;
};

void compression(char str[]) {

// An array of structures to store the compressed string
  struct Compressed arr[strlen(str)];
  int i = 0, j = 0, k = 0;

// Count the frequency of individual characters in the input string
  while (str[i] != '\0') {
    int count = 1;
    char ch = str[i];

    while (str[i + 1] == ch) {
        count++;
        i++;
    }

    arr[j].letter = ch;
    arr[j].count = count;
    j++;
    i++;
  }

// Print the compressed string
  printf("\nCompressed String:\n");
 
  for (k = 0; k < j; k++)
     printf("%d%c", arr[k].count, arr[k].letter);

  printf("\n");
}

int main() {
    char str[100];
    printf("Enter a string to compress:\n");
    scanf("%s", str);

    compression(str);

    return 0;
}