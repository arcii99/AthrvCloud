//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // seeding random number generator with current time
    srand(time(0));
    
    // welcome message
    printf("Welcome to the automated fortune teller!\n");
    
    // asking for user's name
    char name[20];
    printf("What's your name? ");
    scanf("%s", name);
    
    // generating random number between 1 and 5 to determine the fortune
    int fortune = rand() % 5 + 1;
    
    // outputting the fortune based on the generated number
    switch(fortune) {
        case 1:
            printf("\nHey %s, your future is looking bright! You will achieve your goals and live a happy life.", name);
            break;
        case 2:
            printf("\nHmm, %s, the road ahead may be rocky but if you stay true to yourself, you will come out on top.", name);
            break;
        case 3:
            printf("\nOh wow, %s, you are in for a big surprise! Something amazing is coming your way.", name);
            break;
        case 4:
            printf("\nSorry %s, the future is unclear at the moment. But don't worry, everything happens for a reason.", name);
            break;
        case 5:
            printf("\nBe prepared, %s, for a major change in your life. Embrace it and it will lead to great things.", name);
            break;
        default:
            printf("\nOops, something went wrong. Please try again later.");
    }
    
    return 0;
}