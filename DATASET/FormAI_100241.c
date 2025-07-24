//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initializing variables
    
    char questions[20][100] = {"What does the future hold for me?", "Will my dreams come true?", "Is success on my horizon?", "Am I making the right decisions?", "What should I focus on right now?", "How can I improve myself?", "Will I find love soon?", "What does fate have in store for me?", "What should I avoid in the future?", "How can I achieve my goals?", "What will be my greatest challenge?", "Will I be financially stable?", "Am I on the right path?", "What is my purpose in life?", "How can I overcome my obstacles?", "What can I learn from my past?", "Will I be able to travel in the near future?", "Should I take risks or play it safe?", "What advice do my spirit guides have for me?", "How can I find inner peace?"};
    char answers[10][100] = {"It is certain", "Without a doubt", "You may rely on it", "Yes definitely", "It is decidedly so", "As I see it, yes", "Most likely", "Yes", "Outlook good", "Signs point to yes"};
    char negative[10][100] = {"Don't count on it", "Outlook not so good", "Very doubtful", "My sources say no", "Better not tell you now", "Reply hazy, try again", "Cannot predict now", "My reply is no", "Ask again later", "Concentrate and ask again"};
    
    int rand_num, i;
    char question[100];
    
    
    // Starting the program
    
    printf("Welcome to the Automated Fortune Teller Program!\n");
    printf("Ask the program a question and it will provide an answer.\n\n");
    
    // Asking the user for input
    
    printf("What question do you have for me today?\n");
    fgets(question, 100, stdin);
    
    // Generating random number and providing answer
    srand(time(NULL));
    rand_num = rand() % 2; // Randomly picking a positive or negative answer
    
    printf("\nThinking...\n\n");
    
    if (rand_num == 0) { // Positive answer
        rand_num = rand() % 20; // Randomly picking a positive response
        printf("The answer to your question \"%s\" is: %s\n", question, answers[rand_num]);
    }
    else { // Negative answer
        rand_num = rand() % 10; // Randomly picking a negative response
        printf("The answer to your question \"%s\" is: %s\n", question, negative[rand_num]);
    }
    
    printf("\nThank you for using the Automated Fortune Teller Program!\n");
    
    return 0;
}