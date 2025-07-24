//FormAI DATASET v1.0 Category: System administration ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // check if user has root privileges
    if (getuid() != 0) {
        printf("This program must be run as root.\n");
        exit(EXIT_FAILURE);
    }

    // declare variables for system calls
    char* username = "user1"; // change to desired username
    char* password = "password1"; // change to desired password
    char* home_dir = "/home/user1"; // change to desired home directory
    char* shell = "/bin/bash"; // change to desired default shell
    char* user_add_cmd = (char*) malloc(500 * sizeof(char));
    char* passwd_cmd = (char*) malloc(500 * sizeof(char));
    char* chown_cmd = (char*) malloc(500 * sizeof(char));
    char* chmod_cmd = (char*) malloc(500 * sizeof(char));

    // create user
    sprintf(user_add_cmd, "useradd -d %s -s %s %s", home_dir, shell, username);
    system(user_add_cmd);

    // set password
    sprintf(passwd_cmd, "echo \"%s:%s\" | chpasswd", username, password);
    system(passwd_cmd);

    // change ownership of home directory to new user
    sprintf(chown_cmd, "chown %s:%s %s", username, username, home_dir);
    system(chown_cmd);

    // set permissions on home directory
    sprintf(chmod_cmd, "chmod 700 %s", home_dir);
    system(chmod_cmd);

    // free memory from heap
    free(user_add_cmd);
    free(passwd_cmd);
    free(chown_cmd);
    free(chmod_cmd);
    
    return 0;
}