//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[256];
    int count = 0;

    printf("Welcome to the Intrusion Detection System.\n");

    while (1) {
        printf("Enter a command: ");
        fgets(input, 256, stdin);

        if (strncmp(input, "exit", 4) == 0) {
            printf("Exiting...\n");
            break;
        }

        count++;

        if (count > 10) {
            printf("Possible intrusion detected!\n");
            printf("Too many commands entered within a short time period.\n");
            printf("Locking system...\n");
            exit(0);
        }
    }
    
    return 0;
}