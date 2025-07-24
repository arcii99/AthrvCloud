//FormAI DATASET v1.0 Category: File Encyptor ; Style: funny
#include <stdio.h>

int main() {
  char key[] = "ilovecorgis"; // secret key
  char fileName[100]; // stores the file name given by the user
  
  printf("Welcome to the C-File Encryptor!\n");
  printf("Please enter the name of the file to be encrypted: ");
  scanf("%s", fileName);
  
  FILE* file = fopen(fileName, "r"); // open the file in read mode

  if (file == NULL) {
    printf("Error opening file. Exiting...\n");
    return 1; // exit with error code 1
  }

  int c;
  int i = 0;
  while ((c = fgetc(file)) != EOF) {  
    c = c ^ key[i++ % (sizeof(key)/sizeof(char))]; // XOR operation between the key and the file data
    printf("%c", c); // printing the encrypted character
  }
  
  fclose(file); // closing the file
  printf("\nEncryption complete! Have a barky day!\n");
  return 0; // exit with success code 0
}