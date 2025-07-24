//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int ram, usage;
    srand(time(NULL));

    printf("Welcome to the Medieval RAM Usage Monitor!\n");
    printf("Your computer has a limited amount of RAM (Random Access Memory).\n");
    printf("If too many programs are running and using up too much RAM, your computer may slow down or even crash!\n");
    printf("We will monitor your RAM usage and warn you if it gets too high.\n");

    while (1) {
        ram = rand() % 100 + 1;
        usage = rand() % 100 + 1;

        printf("\nYour computer currently has %dMB of RAM and is using %d%% of it.\n", ram, usage);

        if (usage >= 80) {
            printf("WARNING: Your RAM usage is getting dangerously high! Please close some programs.\n");
        }
        else if (usage >= 60) {
            printf("CAUTION: Your RAM usage is getting high. Consider closing some programs.\n");
        }

        printf("Press ENTER to check RAM usage again. Or type 'exit' to quit the program.\n");
        char input[10];
        fgets(input, 10, stdin);

        if (strcmp(input, "exit\n") == 0) {
            printf("Thank you for using the Medieval RAM Usage Monitor!\n");
            break;
        }
    }

    return 0;
}