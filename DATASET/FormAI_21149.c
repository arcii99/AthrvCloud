//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    printf("\n\nWelcome to the Typing Speed Test in a Post-Apocalyptic World!\n");
    printf("\nType each word and hit enter to continue.\n\n");

    char* words[10] = {"radiation", "mutation", "wasteland", "survivor", "zombie", "apocalypse", "scavenger", "desolate", "post-apocalyptic", "hazard"};
    int count = 0;
    int correct = 0;
    char word[20];

    while(count < 10) {
        srand(time(NULL));
        int index = rand() % 10;
        printf("%s: ", words[index]);
        scanf("%s", word);
        if(strcmp(word, words[index]) == 0) {
            printf("Correct!\n\n");
            correct++;
        } else {
            printf("Incorrect, the correct word was %s.\n\n", words[index]);
        }
        count++;
    }

    printf("\n\nYou typed %d words correctly in the Typing Speed Test in a Post-Apocalyptic World!\n", correct);
    printf("Good job surviving in this hazardous environment.\n");

    return 0;
}