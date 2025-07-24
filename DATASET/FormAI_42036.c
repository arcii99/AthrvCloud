//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between 1 to 10
int generateRandomNumber() {
    srand(time(NULL));

    // Generate random number between 1 to 10
    int random_number = rand() % 10 + 1;

    return random_number;
}

// Function to display the fortune based on the random number generated
void displayFortune(int number) {
    switch(number) {
        case 1:
            printf("You will find success in unexpected places.\n");
            break;
        case 2:
            printf("A new opportunity is headed your way.\n");
            break;
        case 3:
            printf("You will be showered with love and affection.\n");
            break;
        case 4:
            printf("Your hard work will pay off soon.\n");
            break;
        case 5:
            printf("A financial windfall is on the horizon.\n");
            break;
        case 6:
            printf("A long-lost friend will re-enter your life.\n");
            break;
        case 7:
            printf("Travel plans will be successful and memorable.\n");
            break;
        case 8:
            printf("You will receive unexpected help from a stranger.\n");
            break;
        case 9:
            printf("You will find happiness in simple things.\n");
            break;
        case 10:
            printf("You will overcome a difficult obstacle soon.\n");
            break;
        default:
            printf("Error: Something went wrong.\n");
            break;    
    }
}

// Main function that runs the program
int main() {
    printf("Welcome to the Shape Shifting Fortune Teller Program!\n");

    // Call the function to generate random number between 1 to 10
    int random_number = generateRandomNumber();

    // Call the function to display the fortune based on the random number generated
    printf("Your fortune for today is:\n\n");
    displayFortune(random_number);

    printf("\nThank you for using the Shape Shifting Fortune Teller Program!\n");

    return 0;
}