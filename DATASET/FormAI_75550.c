//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

int main() {
    char alien_language[] = "kaqoz uqofz arrax zulox laqun sakiz wupix toqyx noqaj";
    char english[] = "abcdefghijklmnopqrstuvwxyz";
    char input[100];
    int i, j;

    printf("Enter a phrase in the alien language: ");
    gets(input);

    for(i = 0; i < strlen(input); i++) {
        if(input[i] == ' ') {
            printf(" ");
        }
        else {
            for(j = 0; j < strlen(alien_language); j++) {
                if(input[i] == alien_language[j]) {
                    printf("%c", english[j]);
                }
            }
        }
    }

    return 0;
}