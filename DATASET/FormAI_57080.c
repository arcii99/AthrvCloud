//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {

    printf("Starting CPU Usage Monitor...\n");

    while (1) {
        
        FILE *fp;
        char c;
        int status;

        fp = popen("ps -eo pcpu,command | sort -k1 -n -r", "r");

        if (fp == NULL) {
            printf("There was an error opening the command pipe.\n");
            exit(EXIT_FAILURE);
        }

        printf("Current CPU usage:\n");
        
        while ((c = fgetc(fp)) != EOF) {
            printf("%c", c);
        }

        status = pclose(fp);

        if (status == -1) {
            printf("There was an error closing the command pipe.\n");
            exit(EXIT_FAILURE);
        } else if (WIFEXITED(status)) {
            if (WEXITSTATUS(status) != 0) {
                printf("There was an error with the command\n");
            }
        } else {
            printf("The command terminated abnormally\n");
        }
        
        // Sleep for 5 seconds before checking CPU usage again
        sleep(5);
    }

    return 0;
}