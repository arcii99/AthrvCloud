//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_FORTUNES 32
// Define an array of possible fortunes
char *fortunes[MAX_FORTUNES] = {"A solution to a problem will soon be found.",
                                "A journey of a thousand miles begins with a single step.",
                                "All your hard work will soon pay off.",
                                "Change is coming, be prepared.",
                                "Everything will turn out okay in the end.",
                                "Good things come to those who wait.",
                                "Happiness is just around the corner.",
                                "The future is yours for the taking.",
                                "The future looks bright.",
                                "Your best days are yet to come.",
                                "Your future is looking very bright.",
                                "Success is just around the corner.",
                                "Your dreams will come true.",
                                "You will soon embark on a great journey.",
                                "Believe in yourself and anything is possible.",
                                "Patience is a virtue that will be rewarded.",
                                "Tomorrow holds great promise for you.",
                                "The future is yours to create.",
                                "Your goals will soon be realized.",
                                "Great things are coming your way.",
                                "Soon you will experience great joy in your life.",
                                "Today's preparation can prevent tomorrow's failure.",
                                "You will make a positive impact on the world.",
                                "A great opportunity is coming your way.",
                                "You will soon achieve your dreams.",
                                "A new door will soon open for you.",
                                "You have the ability to achieve anything you set your mind to.",
                                "A bright future is in store for you.",
                                "Your future is looking very promising.",
                                "Soon you will find success in all areas of your life.",
                                "You will soon experience a significant change in life."
                                };
int main() {
    srand(time(NULL)); // Seed the random number generator
    printf("Welcome to the Automated Fortune Teller.\n\n");
    printf("Ask me a question and I will predict your future.\n");
    printf("(Type 'quit' to exit the program.)\n\n");
    char question[1000]; // Declare a char array to hold the user's question
    do {
        printf("What is your question? ");
        fgets(question, sizeof(question), stdin); // Read the user's question from standard input
        if (strcmp(question, "quit\n") != 0) { // If the user did not enter "quit", generate and print a fortune
            int index = rand() % MAX_FORTUNES; // Generate a random index to select a fortune from the array
            printf("\nYour fortune is:\n\n%s\n\n", fortunes[index]); // Print the fortune to the console
        }
    } while (strcmp(question, "quit\n") != 0); // Continue looping until the user enters "quit"
    printf("Thank you for using the Automated Fortune Teller.\n");
    return 0;
}