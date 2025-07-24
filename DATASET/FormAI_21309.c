//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: happy
#include<stdio.h>
#include<string.h>

int main(){

    char input[50];
    int score = 0;
    int len = 0;

    printf("Welcome to the Happy Sentiment Analysis Tool!\n\n");

    printf("Enter your text here: ");
    fgets(input, sizeof(input), stdin);

    len = strlen(input);

    for(int i=0; i<len; i++){

        if(input[i] == 'h' || input[i] == 'H'){
            if(input[i+1] == 'a' || input[i+1] == 'A'){
                if(input[i+2] == 'p' || input[i+2] == 'P'){
                    if(input[i+3] == 'p' || input[i+3] == 'P'){
                        if(input[i+4] == 'y' || input[i+4] == 'Y'){
                            score++;
                        }
                    }
                }
            }
        }

        if(input[i] == ':' || input[i] == ')' || input[i] == 'D'){
            score++;
        }

        if(input[i] == '!' || input[i] == '❤' || input[i] == '💯'){
            score++;
        }

        if(input[i] == '?' || input[i] == '😕'){
            score--;
        }

        if(input[i] == '!' || input[i] == '😍'){
            score++;
        }

    }

    printf("\n\nThe sentiment score for your text is: %d\n", score);

    if(score >= 3){
        printf("Wow, your text is full of happiness! Keep spreading the positivity!\n");
    } else if (score > 0){
        printf("Your text is somewhat happy, but could use a little more cheer!\n");
    } else if (score == 0){
        printf("Your text doesn't seem to have any specific sentiment.\n");
    } else {
        printf("Oh no, your text seems unhappy! Try to add some happiness to your day!\n");
    }

    return 0;
}