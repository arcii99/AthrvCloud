//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    // Define variables
    int num;
    srand(time(NULL)); // Seed srand with current time

    // Opening message and instructions
    printf("Welcome to the Automated Fortune Teller!\n\n");
    printf("Please think of a number between 1 and 10 and press enter when ready.\n");
    getchar();
    printf("\n");

    // Generate random fortune based on user input
    num = rand() % 10 + 1; // Generate random number between 1 and 10

    switch(num) {
        case 1:
            printf("Your future is looking bright. Keep up the positive energy!\n");
            break;
        case 2:
            printf("Be cautious of the decisions you make in the near future. Think things through.\n");
            break;
        case 3:
            printf("Good luck will come your way soon. Keep your eyes and heart open.\n");
            break;
        case 4:
            printf("You will face challenges in the future, but with determination you will overcome them.\n");
            break;
        case 5:
            printf("Look out for opportunities that will present themselves in the near future.\n");
            break;
        case 6:
            printf("A new relationship or friendship will blossom in the near future. Embrace it!\n");
            break;
        case 7:
            printf("The universe is aligning for you. Trust the journey and enjoy the ride.\n");
            break;
        case 8:
            printf("Don't be afraid to take risks in the near future. They may lead to great rewards.\n");
            break;
        case 9:
            printf("Your hard work will pay off in the near future. Keep pushing forward.\n");
            break;
        case 10:
            printf("You may face a setback in the near future, but don't let it discourage you. Keep moving forward.\n");
            break;
        default:
            printf("Error: Number is not within range.\n"); // Error message if generated number is not within range
            break;
    }

    // Closing message
    printf("\nThank you for using the Automated Fortune Teller!");
    
    return 0;
}