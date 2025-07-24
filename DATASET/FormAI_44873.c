//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num; // store the user's chosen number

    printf("\nGreetings! I am your automated fortune teller.\n\n");

    // Ask user to choose a number between 1 and 10.
    printf("Please choose a number between 1 and 10: ");
    scanf("%d", &num);

    // Generate a random number between 1 and 10.
    srand(time(NULL)); // seed the random number generator with the current time
    int rand_num = rand() % 10 + 1; // generate random number between 1 and 10

    // Determine fortune based on user's chosen number and random number.
    if (num == rand_num) {
        printf("\nCongratulations! You are destined for great things!\n");
    }
    else if (num < rand_num) {
        printf("\nYour future looks bright, but you may encounter some obstacles along the way.\n");
    }
    else {
        printf("\nBe careful! Your future is uncertain and you may face difficult challenges.\n");
    }

    // Say goodbye!
    printf("\nThank you for consulting with me. Goodbye!\n");

    return 0;
}