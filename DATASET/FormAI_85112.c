//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL)); // Initialize random seed
    
    char questions[5][50] = {"What is my future?", "Will I be successful?", "What career path should I choose?", "Will I find love?", "Am I on the right path?"};
    
    int rand_num = rand() % 5; // Generate random number from 0 to 4
    
    printf("Welcome to the Automated Fortune Teller! \n\n");
    printf("You may ask one question and I will provide you with an answer. \n");
    printf("Your question is: %s \n\n", questions[rand_num]);
    
    char fortunes[10][100] = {"It is certain.", "Without a doubt.", "You may rely on it.", "Yes, definitely.", "It is decidedly so.",
                             "As I see it, yes.", "Most likely.", "Outlook good.", "Yes.", "Signs point to yes."};
    
    rand_num = rand() % 10; // Generate random number from 0 to 9
    
    printf("The answer to your question is: %s \n", fortunes[rand_num]);
    
    return 0;
}