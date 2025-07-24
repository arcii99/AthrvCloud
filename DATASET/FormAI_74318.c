//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: mathematical
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL)); //Seed the random number generator with the current time
    int random_num = rand() % 1000 + 1; //Generate a random number between 1 and 1000
    int answer;
    int tries = 0;
    printf("Welcome to the Automated Fortune Teller! \n");
    printf("Think of a number between 1 and 1000 and I will try to guess it. \n");

    do {
        printf("Is your number %d?\n", random_num);
        printf("1. Yes\n2. No, my number is higher\n3. No, my number is lower\n");
        printf("Enter your answer: ");
        scanf("%d", &answer);
        printf("\n");

        if (answer == 1) {
            printf("I knew it! Your number was %d and it took me %d tries to guess it.\n", random_num, tries);
            break;
        }
        else if (answer == 2) {
            random_num = rand() % (1000 - random_num) + random_num + 1; //Generate a random number higher than the previous guess
            tries++;
        }
        else if (answer == 3) {
            random_num = rand() % (random_num - 1) + 1; //Generate a random number lower than the previous guess
            tries++;
        }
        else {
            printf("Invalid input. Please enter 1, 2, or 3.\n");
        }
    } while (answer != 1);

    return 0;
}