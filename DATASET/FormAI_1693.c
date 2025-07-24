//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void welcomeMessage();
void askQuestion();
void generateAnswer(int);

// Main function
int main() {
    // Display welcome message
    welcomeMessage();

    // Ask question and generate answer
    askQuestion();

    return 0;
}

// Function to display welcome message
void welcomeMessage() {
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Think of a question and I will give you the answer.\n");
}

// Function to ask question
void askQuestion() {
    char question[100];
    printf("What is your question?\n");
    fgets(question, 100, stdin);

    // Generate random number for answer selection
    srand(time(NULL));
    int answerIndex = rand() % 10;

    // Display answer
    generateAnswer(answerIndex);
}

// Function to generate answer
void generateAnswer(int index) {
    char *answers[10] = {"Yes", "No", "Maybe", "It is certain", "Cannot predict now",
                         "Most likely", "Better not tell you now", "Don't count on it", 
                         "Outlook not so good", "Ask again later"};
    printf("The answer to your question is: %s\n", answers[index]);
}