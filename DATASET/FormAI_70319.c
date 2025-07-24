//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: random
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to detect intrusion
int detect_intrusion(char *command) {
    int flag = 0;
    char *commands[] = {"cat", "ls", "mkdir", "rm", "mv", "cp", "kill", "wget", "curl", "ssh"};
    int len = sizeof(commands) / sizeof(commands[0]);
    for(int i=0; i<len; i++) {
        if(strcmp(command, commands[i]) == 0) {
            flag = 1;
            break;
        }
    }
    return flag;
}

int main() {
    char command[50];
    printf("Please enter a command: ");
    scanf("%s", command);
    int flag = detect_intrusion(command);
    if(flag == 0) {
        printf("Command %s is safe to execute!\n", command);
    }
    else {
        printf("WARNING: Intrusion detected for command %s\n", command);
        printf("Exiting\n");
        exit(0);
    }
    return 0;
}