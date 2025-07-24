//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL)); //initialize random seed
    char question[50];
    int rand_num = rand() % 10; //generate random number between 0-9
    printf("Welcome to the Automated Fortune Teller. Ask me any yes or no question and I will tell you your fate.\n");
    printf("What is your question?\n");
    fgets(question, sizeof(question), stdin); //get user question input
    printf("\nThinking...\n\n");
    //use switch statement to give a random answer based on random number generated
    switch(rand_num){
        case 0:
            printf("Yes, definitely.\n");
            break;
        case 1:
            printf("It is decidedly so.\n");
            break;
        case 2:
            printf("Without a doubt.\n");
            break;
        case 3:
            printf("Reply hazy, try again.\n");
            break;
        case 4:
            printf("Ask again later.\n");
            break;
        case 5:
            printf("Better not tell you now.\n");
            break;
        case 6:
            printf("Don't count on it.\n");
            break;
        case 7:
            printf("Outlook not so good.\n");
            break;
        case 8:
            printf("Very doubtful.\n");
            break;
        case 9:
            printf("My sources say no.\n");
            break;
    }
    return 0;
}