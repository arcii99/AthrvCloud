//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Array of fortune messages
char* fortunes[] = {
    "A beautiful, smart, and loving person will be coming into your life.",
    "All your hard work will soon pay off.",
    "An unexpected event will soon make your life more exciting.",
    "Your luck is about to change!",
    "Be prepared to receive a gift from an unexpected source.",
    "Keep your eyes open for new opportunities and experiences."
};

// Function to retrieve a random fortune
char* getFortune() {
    srand(time(NULL)); // Seed the random number generator
    int index = rand() % 6; // Get a random integer between 0 and 5
    return fortunes[index];
}

// Main function
int main() {
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Press Enter to receive your fortune...\n");
    getchar(); // Wait for user to press Enter
    printf("\n%s\n", getFortune()); // Print the fortune
    printf("\nThank you for using the Automated Fortune Teller!\n");
    return 0;
}