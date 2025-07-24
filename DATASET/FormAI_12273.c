//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char message[100];
  char watermark[] = "mywatermark";
  char result[200];
  int i, j;

  printf("Enter message to be watermarked: ");
  fgets(message, 100, stdin);

  strcat(message, watermark); // add watermark to message

  // loop to add random characters to message
  for(i = strlen(message); i < 200; i++)
  {
    message[i] = (rand() % 26) + 'a';
  }

  // loop to shuffle message
  for(i = 0; i < strlen(message); i++)
  {
    j = rand() % strlen(message);
    char temp = message[i];
    message[i] = message[j];
    message[j] = temp;
  }

  strcpy(result, message); // copy message to result

  printf("\nWatermarked message: %s\n", result);
  return 0;
}