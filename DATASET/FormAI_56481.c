//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int fortune;
    char question[100];

    printf("Welcome to the Automated Fortune Teller.\n");
    printf("Please ask a yes or no question: ");
    scanf("%[^\n]", question);

    //Seed random number generator
    srand(time(NULL));
    fortune = rand() % 10 + 1;

    if(fortune == 1){
        printf("Without a doubt.\n");
    }
    else if(fortune == 2){
        printf("Yes - definitely.\n");
    }
    else if(fortune == 3){
        printf("You may rely on it.\n");
    }
    else if(fortune == 4){
        printf("As I see it, yes.\n");
    }
    else if(fortune == 5){
        printf("Most likely.\n");
    }
    else if(fortune == 6){
        printf("Outlook good.\n");
    }
    else if(fortune == 7){
        printf("Yes.\n");
    }
    else if(fortune == 8){
        printf("Signs point to yes.\n");
    }
    else if(fortune == 9){
        printf("Reply hazy, try again.\n");
    }
    else{
        printf("Better not tell you now.\n");
    }

    return 0;
}