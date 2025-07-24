//FormAI DATASET v1.0 Category: System boot optimizer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    printf("\nWelcome to the C System Boot Optimizer Puzzle!\n");
    printf("Are you ready to optimize your boot time?\n");

    char response;
    printf("Enter 'Y' for yes and 'N' for no: ");
    scanf("%c", &response);

    if (response == 'Y') {
        printf("\nGreat! Let's get started.\n");
    }
    else {
        printf("\nNo problem, come back when you're ready.\n");
        return 0;
    }

    printf("\nPlease wait while we scan your system...\n");

    srand(time(NULL));
    int random_num = rand() % 1000 + 1;

    printf("\nScan complete! We have found %d unnecessary processes.\n", random_num);

    printf("To optimize your boot time, we need to kill %d processes.\n", random_num);

    for (int i = 0; i < random_num; i++) {
        printf("Killing process %d of %d\n", i + 1, random_num);
    }

    printf("\nCongratulations! Your system has been optimized for faster boot times.\n");

    return 0;
}