//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));  // seed random number generator with current time
    int fortune_num = rand() % 5;  // generate a random number between 0 and 4

    // use switch statement to select a fortune based on the random number
    switch (fortune_num) {
        case 0:
            printf("Your future is looking bright!\n");
            break;
        case 1:
            printf("You will face a challenge in the near future, but you will overcome it.\n");
            break;
        case 2:
            printf("You will receive some unexpected good news very soon.\n");
            break;
        case 3:
            printf("Your hard work will pay off and you will achieve your goals.\n");
            break;
        case 4:
            printf("Be cautious in your actions, as they may have consequences you didn't foresee.\n");
            break;
        default:
            printf("Oops, something went wrong. Try again later.\n");
    }
    
    return 0;
}