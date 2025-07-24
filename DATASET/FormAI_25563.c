//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize random seed
    srand(time(NULL));
    
    char name[30], question[1000]; // variables to store user's name and question
    int fortune; // variable to store randomly generated fortune
    
    // Get user's name
    printf("Hello! What is your name? ");
    scanf("%s", name);
    
    // Greet user and ask for their question
    printf("Hello %s! Ask me a question, and I will tell your fortune.\n", name);
    printf("What is your question?\n");
    scanf(" %[^\n]s", question);
    
    // Generate a random number between 1 and 5
    fortune = rand() % 5 + 1;
    
    // Determine fortune based on randomly generated number
    if (fortune == 1) {
        printf("Your fortune is: It is certain.\n");
    } else if (fortune == 2) {
        printf("Your fortune is: Without a doubt.\n");
    } else if (fortune == 3) {
        printf("Your fortune is: Reply hazy, try again.\n");
    } else if (fortune == 4) {
        printf("Your fortune is: Don't count on it.\n");
    } else if (fortune == 5) {
        printf("Your fortune is: Very doubtful.\n");
    }
    
    return 0;
}