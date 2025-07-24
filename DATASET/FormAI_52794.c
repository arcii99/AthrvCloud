//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print out a random fortune
void tellFortune() {
    int num = rand() % 10;
    switch(num) {
        case 0:
            printf("You will find great success in your career.\n");
            break;
        case 1:
            printf("Love is in the air, you'll soon meet someone special.\n");
            break;
        case 2:
            printf("You'll receive unexpected news today, be prepared.\n");
            break;
        case 3:
            printf("You will face a challenge soon, but you will overcome it.\n");
            break;
        case 4:
            printf("Your lucky number is 7.\n");
            break;
        case 5:
            printf("You will go on a great adventure in the near future.\n");
            break;
        case 6:
            printf("Your hard work will pay off soon.\n");
            break;
        case 7:
            printf("Take care of your health, it should be your top priority.\n");
            break;
        case 8:
            printf("Change is coming, embrace it.\n");
            break;
        case 9:
            printf("Money will come your way, but be sure to save it.\n");
            break;
    }
}

int main() {
    time_t t;
    srand((unsigned) time(&t)); // Seed the random number generator with time

    char name[50]; // Buffer for user's name input
    printf("Welcome to the automated fortune teller. Please enter your name: ");
    fgets(name, 50, stdin); // Get user's name input

    printf("Hello, %s. Are you ready to receive your fortune? (Y/N): ", name);
    char answer = getchar(); // Get user's response
    if (answer == 'Y' || answer == 'y') {
        printf("Great! Here is your fortune:\n");
        tellFortune();
    } else {
        printf("That's okay, maybe another time.\n");
    }

    return 0;
}