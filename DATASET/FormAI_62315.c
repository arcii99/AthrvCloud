//FormAI DATASET v1.0 Category: File Encyptor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char data[1000];
  FILE *file_ptr, *enc_file;
  file_ptr = fopen("secret.txt","r");
  enc_file = fopen("secret.enc","w");
  int key = 5;
  if(file_ptr == NULL) {
    printf("Error opening file!");
    exit(1);
  } else {
    while(fgets(data, 1000, file_ptr)) {
      for(int i = 0; i < strlen(data); i++) {
        data[i] ^= key;
      }
      fputs(data,enc_file);
    }
    printf("The file has been encrypted!\n");
  }
  fclose(file_ptr);
  fclose(enc_file);

  return 0;
}