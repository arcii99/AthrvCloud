//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 100

int main() {

    char command[BUFFER_SIZE];
    FILE *fp;
    char result[BUFFER_SIZE];

    while (1) {
        //Run Shell Command to Check RAM Usage
        sprintf(command, "free -m | awk 'NR==2{printf \"Used: %sMB\", $3 }  NR==2{printf \"Total: %sMB\", $2 }'");
        fp = popen(command, "r");

        if (fp == NULL) {
            printf("Failed to run command\n");
            exit(1);
        }

        //Print RAM Usage Result
        while (fgets(result, sizeof(result), fp) != NULL) {
            printf("%s\n", result);
        }

        //Close File Pointer
        pclose(fp);

        //Sleep for 3 Seconds
        sleep(3);
    }

    return 0;
}