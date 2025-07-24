//FormAI DATASET v1.0 Category: String manipulation ; Style: romantic
#include <stdio.h>
#include <string.h>

int main() {
    char name[50];
    printf("Hello, my love! What is your name?\n");
    scanf("%s", name);

    char phrase[100] = "You are my only one, ";
    strcat(phrase, name);
    strcat(phrase, ".\n");

    printf("%s", phrase);

    printf("I want to show you how much I love you.\n");
    printf("Please enter a sentence that describes your love for me:\n");

    char sentence[100];
    getchar();
    fgets(sentence, 100, stdin);

    printf("Your sentence is: %s\n", sentence);

    int sentenceLength = strlen(sentence);

    printf("Now I will add your love to mine:\n");

    char myLove[] = "I love you more than anything in this world.\n";

    for (int i = 0; i < sentenceLength; i++) {
        if (sentence[i] == ' ') {
            printf(" ");
        } else {
            printf("%c", myLove[i % strlen(myLove)]);
        }
    }

    printf("I hope you liked my love manipulation, my sweet %s.\n", name);

    return 0;
}