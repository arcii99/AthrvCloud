//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the possible answers
char *answers[] = {
    "Yes",
    "No",
    "Maybe",
    "Outlook uncertain",
    "Ask again later",
    "Cannot predict now",
    "Don't count on it",
    "Better not tell you now"
};

// Main function
int main() {

    // Initiate the random seed
    srand(time(NULL));
    
    // Get the user's question
    char question[100];
    printf("Welcome to the Automated Fortune Teller! Ask me a yes or no question: ");
    fgets(question, sizeof(question), stdin);
    printf("You asked: %s\n", question);
    
    // Generate the answer
    int answer_index = rand() % (sizeof(answers)/sizeof(answers[0]));
    char *answer = answers[answer_index];
    
    // Print the answer
    printf("The answer to your question is: %s\n", answer);
    
    return 0;
}