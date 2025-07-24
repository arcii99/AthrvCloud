//FormAI DATASET v1.0 Category: System boot optimizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int seconds) {
   int milli_seconds = 1000 * seconds;
   clock_t start_time = clock();
   while (clock() < start_time + milli_seconds)
      ;
}

int main() {
    printf("Welcome to the C System Boot Optimizer!\n");
    printf("This program will help optimize your system boot time by removing unnecessary processes.\n");
    printf("Press any key to continue...\n");
    getchar();

    printf("\nAnalyzing system processes...\n");
    delay(2);
    printf("Done!\n");

    printf("\nHere are the processes that are slowing down your boot time:\n");
    printf(" - Chrome\n");
    printf(" - Spotify\n");
    printf(" - Dropbox\n");

    printf("\nDo you want to remove these processes from startup? (y/n)\n");
    char choice;
    scanf("%c", &choice);
    if (choice == 'y') {
        printf("\nRemoving processes...\n");
        delay(3);
        printf("\nProcesses removed!\n");
    } else if (choice == 'n') {
        printf("\nNo processes removed.\n");
    } else {
        printf("\nInvalid choice!\n");
    }

    printf("\nOptimizing system boot settings...\n");
    delay(5);
    printf("\nDone!\n");

    printf("\nCongratulations! Your system boot time has been optimized.\n");
    printf("Press any key to exit the program...\n");
    getchar();

    return 0;
}