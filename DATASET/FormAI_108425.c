//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the array of fortunes
char *fortunes[] = {
    "You will soon embark on a great adventure!",
    "Good news is coming your way!",
    "You will meet someone special in the near future.",
    "Don't let fear hold you back, take a leap of faith.",
    "Your hard work will pay off soon!",
    "Opportunities will present themselves to you, be ready!"
};

// Define the length of the fortunes array
const int num_fortunes = sizeof(fortunes) / sizeof(fortunes[0]);

// Function to generate a random number between 0 and (n-1)
int random_num(int n) {
    srand(time(NULL));
    return rand() % n;
}

// Main function
int main() {
    int i;
    char name[50];

    // Prompt the user for their name
    printf("Welcome to the Automated Fortune Teller! What is your name?\n");
    scanf("%s", name);

    // Print a greeting with the user's name
    printf("Hello, %s! Are you ready to receive your fortune?\n", name);

    // Wait for the user to press enter
    getchar();

    // Clear the console
    system("clear");

    // Generate a random number and print the corresponding fortune
    printf("Your fortune for today is:\n\n%s\n\n", fortunes[random_num(num_fortunes)]);

    // Print a closing message
    printf("Thank you for using the Automated Fortune Teller. Have a great day!");

    return 0;
}