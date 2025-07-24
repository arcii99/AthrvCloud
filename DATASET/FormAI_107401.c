//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seeding randomization with time
    
    char answers[14][50] = { "It is certain", "It is decidedly so", "Without a doubt", 
                             "Yes – definitely", "You may rely on it", "As I see it, yes", 
                             "Most likely", "Outlook good", "Yes", "Signs point to yes", 
                             "Reply hazy, try again", "Ask again later", "Better not tell you now", 
                             "Don't count on it" };
                             
    printf("== Automated Fortune Teller ==\n\n");
    
    // loop until user wants to stop asking for fortunes
    while (1) {
        printf("Ask anything! (type 'quit' to end)\n");
        
        // read user input
        char input[50];
        scanf(" %[^\n]", input);
        
        // check if user wants to quit
        if (strcmp(input, "quit") == 0) {
            printf("Goodbye!\n");
            break;
        }
        
        // randomize and print the answer
        int random_index = rand() % 14;
        printf("Answer: %s\n\n", answers[random_index]);
    }
    
    return 0;
}