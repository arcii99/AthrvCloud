//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

//welcome message
printf("Welcome to the automated fortune teller! \n");

//initialize random number generator
srand(time(NULL));

//array of fortunes
char fortunes[10][100] = {
    "The future looks bright!",
    "You will take a trip in the near future.",
    "The answer you are looking for is yes.",
    "Be prepared for a big change.",
    "Take a chance on something new.",
    "Your hard work will pay off soon.",
    "Good things come to those who wait.",
    "You will meet someone special.",
    "Take a risk and be rewarded.",
    "The future is yours for the taking."
};

//get user input
printf("Please enter your question: ");
char question[100];
fgets(question, 100, stdin);

//calculate random index of a fortune
int index = rand() % 10;

//output fortune to user
printf("The answer to your question, '%s', is: \n %s", question, fortunes[index]);

return 0;
}