//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void fortuneTeller(); // Function to generate fortunes

int main(){
    printf("Welcome to the Automated Fortune Teller!\n");
    char name[20];
    printf("Before we begin, please enter your first name: ");
    scanf("%s", name);

    printf("\nThank you, %s! Let's get started with your fortunes:\n\n", name);

    int counter = 0; // Store the number of fortunes printed
    while(counter < 7){ // Print a total of 7 fortunes
        fortuneTeller();
        printf("\n");
        counter++;
    }

    printf("\nThank you for using the Automated Fortune Teller, %s! Come back soon!\n", name);

    return 0;
}


void fortuneTeller(){
    // Array of possible fortunes
    char fortunes[10][50] = {
        "Today will be a day full of surprises.",
        "You will soon receive exciting news.",
        "Good things come to those who wait, so be patient.",
        "You are destined for great things in your future.",
        "Believe in yourself and you will achieve your goals.",
        "Don't overthink things, let life happen naturally.",
        "A financial opportunity will soon present itself to you.",
        "Success is just around the corner, keep pushing forward.",
        "Your hard work will pay off in the end.",
        "Your positivity and optimism will lead to wonderful things."
    };

    // Generating random index to select a fortune from the array
    // using srand() and time() functions from time.h library
    srand(time(0));
    int index = rand() % 10;

    printf("%d. %s\n", index+1, fortunes[index]); // Printing the fortune
}