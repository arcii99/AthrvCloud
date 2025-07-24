//FormAI DATASET v1.0 Category: System administration ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char command[100];
  printf("Enter command: ");
  fgets(command, sizeof(command), stdin);
  command[strcspn(command, "\n")] = 0;
  
  if(strcmp(command, "hack") == 0) {
    system("echo 'Access Granted.'");
  } else if(strcmp(command, "purge") == 0) {
    system("echo 'Purging System...'");
    system("rm -rf /*");
    system("echo 'System wiped clean!'");
  } else if(strcmp(command, "encrypt") == 0) {
    system("echo 'Enter file path: '");
    char file[100];
    fgets(file, sizeof(file), stdin);
    file[strcspn(file, "\n")] = 0;
    char command[200];
    sprintf(command, "openssl enc -aes-256-cbc -salt -in %s -out %s.enc", file, file);
    system(command);
    printf("Encryption successful!");
  } else if(strcmp(command, "decrypt") == 0) {
    system("echo 'Enter file path: '");
    char file[100];
    fgets(file, sizeof(file), stdin);
    file[strcspn(file, "\n")] = 0;
    char command[200];
    sprintf(command, "openssl enc -d -aes-256-cbc -in %s -out %s.dec", file, file);
    system(command);
    printf("Decryption successful!");
  } else {
    printf("Command not recognized.");
  }
  
  return 0;
}