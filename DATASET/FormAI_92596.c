//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    char question[100];
    int response;
    srand(time(NULL));

    printf("Welcome to the automated Fortune Teller. Ask me a yes or no question and I will predict the answer!\n");
    
    do{
        printf("What is your question? (Enter 'quit' to exit)\n");
        fgets(question, 100, stdin);

        if(question[0] != '\n' && strcmp(question, "quit\n") != 0){
            response = rand() % 10;
            printf("The answer to your question is: ");

            switch(response){
                case 0:
                    printf("Yes.\n");
                    break;
                case 1:
                    printf("No.\n");
                    break;
                case 2:
                    printf("It is certain.\n");
                    break;
                case 3:
                    printf("Don't count on it.\n");
                    break;
                case 4:
                    printf("Most likely.\n");
                    break;
                case 5:
                    printf("Outlook good.\n");
                    break;
                case 6:
                    printf("Reply hazy, try again.\n");
                    break;
                case 7:
                    printf("Cannot predict now.\n");
                    break;
                case 8:
                    printf("Better not tell you now.\n");
                    break;
                case 9:
                    printf("Concentrate and ask again.\n");
                    break;
            }
        }
    }while(strcmp(question, "quit\n") != 0);

    printf("Thank you for using our Automated Fortune Teller!\n");

    return 0;
}