//FormAI DATASET v1.0 Category: System administration ; Style: shape shifting
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void) {
    char command[100];
    char ch;
    int count = 0;
    printf("Enter the command to execute: ");

    while ((ch = getchar()) != '\n') {
        command[count++] = ch;
    }
    command[count] = '\0';

    if (strcmp(command, "system-info") == 0) {
        // Display system information
        printf("\nSystem Information:\n\n");
        system("uname -a");
        printf("\n\nCPU Information:\n\n");
        system("cat /proc/cpuinfo");
    } else if (strcmp(command, "disk-usage") == 0) {
        // Display disk usage
        printf("\nDisk Usage:\n\n");
        system("df -h");
    } else if (strcmp(command, "memory-usage") == 0) {
        // Display memory usage
        printf("\nMemory Usage:\n\n");
        system("free -h");
    } else {
        // Command not recognized
        printf("\nError: Command not recognized.\n");
    }

    return 0;
}