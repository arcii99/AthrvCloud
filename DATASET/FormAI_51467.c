//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int rand_num;
    srand(time(NULL)); //initialize random seed

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Ask me a question and I will give you an answer.\n");
    
    char question[100];
    printf("Ask your question:\n");
    fgets(question, 100, stdin); //get user input
    
    rand_num = rand() % 5; //generate random number between 0 to 4

    switch(rand_num){
        case 0:
            printf("It is certain.\n");
            break;
        case 1:
            printf("It is decidedly so.\n");
            break;
        case 2:
            printf("Reply hazy, try again.\n");
            break;
        case 3:
            printf("Don't count on it.\n");
            break;
        case 4:
            printf("Outlook not so good.\n");
            break;
        default:
            printf("Invalid number.\n");
    }
    return 0;
}