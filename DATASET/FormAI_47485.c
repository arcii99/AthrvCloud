//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

int main() {
    int happy = 0;
    int sad = 0;
    int angry = 0;
    int neutral = 0;

    char input[100];

    printf("Enter your text to be analyzed: ");
    fgets(input, 100, stdin);

    for(int i = 0; i < strlen(input); i++) {
        switch(input[i]) {
            case ':':
                if(input[i+1] == ')' || input[i+1] == 'D') {
                    happy++;
                } else if(input[i+1] == '(' || input[i+1] == ')') {
                    sad++;
                } else if(input[i+1] == '/' || input[i+1] == '\\' || input[i+1] == '|') {
                    angry++;
                }
                break;
            case ';':
                if(input[i+1] == ')' || input[i+1] == 'D') {
                    happy++;
                }
                break;
            case '-':
                if(input[i+1] == '.' || input[i+1] == '_') {
                    neutral++;
                }
                break;
        }
    }

    if(happy > sad && happy > angry && happy > neutral) {
        printf("Your text is mostly HAPPY!\n");
    } else if(sad > happy && sad > angry && sad > neutral) {
        printf("Your text is mostly SAD.\n");
    } else if(angry > happy && angry > sad && angry > neutral) {
        printf("Your text is mostly ANGRY!\n");
    } else {
        printf("Your text is mostly NEUTRAL.\n");
    }

    return 0;
}