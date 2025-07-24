//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random fortunes
char* fortune_teller() {
    // Array of possible fortunes to choose from
    char* fortunes[] = {"You will have great success in your future endeavors.", 
                        "Good things come to those who wait, so be patient.",
                        "An unexpected opportunity will come your way soon.",
                        "You will find love in the most unexpected place.",
                        "Your hard work will pay off in the near future.",
                        "A friend will offer you advice that will change your life.",
                        "Believe in yourself and you will achieve great things.",
                        "You will travel to a far-off land in the near future.",
                        "Your creativity will lead to an exciting new project.",
                        "You will receive good news in the next few days."};

    // Generate a random index to choose from the array
    srand(time(NULL));
    int index = rand() % 10;

    return fortunes[index];
}

// Main function to run the fortune teller program
int main() {
    printf("Welcome to the Automated Fortune Teller Program!\n\n");

    // Ask the user for their name and store it
    char name[50];
    printf("What is your name? ");
    fgets(name, 50, stdin);

    // Generate a random fortune and print it to the screen
    char* fortune = fortune_teller();
    printf("\n%s, your fortune for today is: %s\n", name, fortune);

    return 0;
}