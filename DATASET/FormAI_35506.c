//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    // Initializing variables
    int fortune;
    time_t t;
    srand((unsigned) time(&t)); // Setting seed for rand() function
    
    // Looping for continuous predictions
    while (1) {
        printf("Please think about your question and press ENTER to see your fortune!\n");
        getchar(); // Waiting for user input
        
        // Generating a random number from 1 to 10
        fortune = rand() % 10 + 1;

        // Using switch case to predict fortune based on random number
        switch (fortune) {
            case 1: printf("I see good things happening for you.\n"); break;
            case 2: printf("You will meet someone special soon.\n"); break;
            case 3: printf("Your hard work will pay off soon.\n"); break;
            case 4: printf("You may face some obstacles, but you will overcome them.\n"); break;
            case 5: printf("You will receive unexpected news soon.\n"); break;
            case 6: printf("You will have a pleasant surprise in the near future.\n"); break;
            case 7: printf("Your dreams are about to come true.\n"); break;
            case 8: printf("You need to beware of a potential danger.\n"); break;
            case 9: printf("Your patience will be rewarded soon.\n"); break;
            case 10: printf("You will have a life-changing experience soon.\n"); break;
        }
    }
    return 0;
}