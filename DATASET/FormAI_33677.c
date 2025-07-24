//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    int answer;

    printf("Greetings! I am the Automated Fortune Teller. \n\n");

    srand(time(NULL));

    printf("Enter your question (press ENTER): ");
    getchar();

    answer = rand() % 10;

    switch(answer){
        case 0:
            printf("Yes!\n");
            break;
        case 1:
            printf("No.\n");
            break;
        case 2:
            printf("It is possible.\n");
            break;
        case 3:
            printf("I see it happening in the near future.\n");
            break;
        case 4:
            printf("I'm not quite sure, try again later.\n");
            break;
        case 5:
            printf("Focus on yourself more, and the answer will become clear.\n");
            break;
        case 6:
            printf("The stars are aligning for you, good things are coming.\n");
            break;
        case 7:
            printf("I'm getting a feeling that the answer is no.\n");
            break;
        case 8:
            printf("Definitely, yes.\n");
            break;
        case 9:
            printf("This question is too complex for a simple yes or no answer.\n");
            break;
    }

    return 0;
}