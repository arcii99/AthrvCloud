//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int random_number;
    char question[100];

    printf("Welcome to the Automated Fortune Teller! \n");

    printf("Please ask a yes/no question: ");
    fgets(question, sizeof question, stdin);

    srand(time(NULL));
    random_number = rand() % 10;

    if (random_number == 0){
        printf("Outlook not so good. \n");
    } else if (random_number == 1){
        printf("It is certain. \n");
    } else if (random_number == 2){
        printf("My sources say no. \n");
    } else if (random_number == 3){
        printf("Yes. \n");
    } else if (random_number == 4){
        printf("Don't count on it. \n");
    } else if (random_number == 5){
        printf("Most likely. \n");
    } else if (random_number == 6){
        printf("My reply is no. \n");
    } else if (random_number == 7){
        printf("Signs point to yes. \n");
    } else if (random_number == 8){
        printf("Cannot predict now. \n");
    } else if (random_number == 9){
        printf("Better not tell you now. \n");
    }

    return 0;
}