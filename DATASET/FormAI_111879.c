//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() 
{
    srand(time(NULL)); // set seed for randomization

    int fortuneNum = rand() % 10 + 1; // generates random number between 1-10
    
    printf("Welcome to the Automated Fortune Teller! Think of a question and I will reveal your fate...\n");
    printf("Press Enter to continue...\n");

    while(getchar() != '\n'); // waits for user to press enter

    switch(fortuneNum) // selects random fortune based on random number generated
    {
        case 1:
            printf("Your future looks bright! The stars are aligned in your favor.\n");
            break;
        case 2:
            printf("Be careful with the decisions you make. Your fate rests on them.\n");
            break;
        case 3:
            printf("You will experience a great opportunity soon. Seize it!\n");
            break;
        case 4:
            printf("Take some time to meditate and reflect on your goals. The answer you seek lies within.\n");
            break;
        case 5:
            printf("Your hard work will soon pay off. Keep pushing forward!\n");
            break;
        case 6:
            printf("Be wary of those who may try to take advantage of you. Trust your gut.\n");
            break;
        case 7:
            printf("Your determination and persistence will lead to great success.\n");
            break;
        case 8:
            printf("Don't be afraid to try new things. Innovation is key to your success.\n");
            break;
        case 9:
            printf("Your passions will guide you to great things. Follow them.\n");
            break;
        case 10:
            printf("Your time of struggle will soon come to an end. Stay strong.\n");
            break;
    }

    printf("\nThank you for using the Automated Fortune Teller!");

    return 0;
}