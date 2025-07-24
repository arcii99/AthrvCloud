//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *fortune_list[] = {
    "You will have a wonderful day.\n",
    "Good news is on the horizon.\n",
    "You will meet someone new today.\n",
    "Success is in your future.\n",
    "You will receive unexpected help today.\n",
    "Your hard work will pay off soon.\n",
    "You will have a peaceful day.\n",
    "Be prepared for a change in your routine.\n",
    "A new opportunity will arise today.\n",
    "Today is your lucky day!\n"
};

int main()
{
    srand(time(NULL));
    printf("Welcome to the Automated Fortune Teller!\n");

    int option;
    printf("\nPlease choose an option:\n");
    printf("1. Get your fortune\n");
    printf("2. Exit\n");
    scanf("%d", &option);

    while (option != 2)
    {
        if (option == 1)
        {
            int random_index = rand() % 10;
            printf("\n%s\n", fortune_list[random_index]);
        }
        else
        {
            printf("\nInvalid option. Please choose again.\n");
        }

        printf("\nPlease choose an option:\n");
        printf("1. Get your fortune\n");
        printf("2. Exit\n");
        scanf("%d", &option);
    }

    printf("\nThank you for using the Automated Fortune Teller!\n");
    return 0;
}