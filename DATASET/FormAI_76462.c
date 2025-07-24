//FormAI DATASET v1.0 Category: System administration ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char** argv) {
  int uid = getuid();
  if (uid != 0) {
    printf("Insufficient privileges - root access required!\n");
    exit(EXIT_FAILURE);
  }

  printf("Welcome to the Cryptic System Administration Program!\n");

  printf("Please specify the name of the system user you would like to add:\n");
  char username[64];
  fgets(username, 64, stdin);
  strtok(username, "\n");

  printf("Creating user '%s'...\n", username);
  char command[256];
  snprintf(command, 256, "useradd -m %s", username);
  system(command);
  printf("User '%s' created successfully!\n", username);

  printf("Please specify the port number you would like to allow incoming traffic on:\n");
  char port[8];
  fgets(port, 8, stdin);
  strtok(port, "\n");

  printf("Opening port '%s'...\n", port);
  snprintf(command, 256, "iptables -A INPUT -p tcp --dport %s -j ACCEPT", port);
  system(command);
  printf("Port '%s' opened successfully!\n", port);

  printf("Please specify the name of the file you would like to encrypt:\n");
  char filename[64];
  fgets(filename, 64, stdin);
  strtok(filename, "\n");

  printf("Encrypting file '%s'...\n", filename);
  snprintf(command, 256, "gpg --symmetric %s", filename);
  system(command);
  printf("File '%s' encrypted successfully!\n", filename);

  printf("Thank you for using the Cryptic System Administration Program!\n");
  return 0;
}