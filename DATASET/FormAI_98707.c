//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char questions[5][50] = {"What is my future career?", "Will I find true love?", "Will I be rich?", "Will I be successful?", "Where will I live in the future?"};
    char answers[10][50] = {"It is certain", "Without a doubt", "You may rely on it", "Yes definitely", "It is decidedly so", "As I see it, yes", "Most likely", "Outlook good", "Yes", "Signs point to yes"};
    int input_choice;
    time_t t;
    srand((unsigned) time(&t));
    
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter a number between 1-5 corresponding to your question:\n1) What is my future career?\n2) Will I find true love?\n3) Will I be rich?\n4) Will I be successful?\n5) Where will I live in the future?\n");
    scanf("%d", &input_choice);
    
    if(input_choice < 1 || input_choice > 5) {
        printf("Invalid input. Please try again.\n");
    } else {
        int random_answer = rand() % 10; 
        printf("Your answer to '%s': %s\n", questions[input_choice - 1], answers[random_answer]);
    }
    
    return 0;
}