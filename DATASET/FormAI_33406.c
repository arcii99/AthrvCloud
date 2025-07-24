//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num;

    srand(time(NULL)); // seed the random number generator

    puts("Welcome to the Automated Fortune Teller!");
    puts("Enter a number between 1 and 6:");

    scanf("%d", &num);

    switch(num)
    {
        case 1:
            puts("You will come into a large sum of money soon.");
            break;
        case 2:
            puts("A long-lost friend will contact you in the near future.");
            break;
        case 3:
            puts("Your creative energies will be renewed.");
            break;
        case 4:
            puts("You will embark on a romantic journey.");
            break;
        case 5:
            puts("Your hard work will lead to great success.");
            break;
        case 6:
            puts("You will make a new friend who will change your life.");
            break;
        default:
            puts("Please enter a number between 1 and 6.");
    }

    return 0;
}