//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove whitespaces in a string
void removeWhitespaces(char *str) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] != ' ') {
            str[count++] = str[i];
        }
    }
    str[count] = '\0';
}

// Function to translate C Alien Language into human-readable text
void alienTranslate(char *sentence, int len) {
    char *words[100] = {NULL};
    int numOfWords;
    char *pointer, *rest = sentence;
    
    // Splitting sentence into individual words
    for (numOfWords = 0; numOfWords < 100 && (pointer = strtok_r(rest, "|", &rest)); numOfWords++) {
        words[numOfWords] = pointer;
    }

    // Looping through each word and translating to human-readable text
    for (int i = 0; i < numOfWords; i++) {
        int length = strlen(words[i]);
        char *temp = (char *) malloc((length + 1) * sizeof(char));
        temp[length] = '\0';
        for (int j = 0; j < length; j += 2) {
            temp[j/2] = (char) strtol(&words[i][j], NULL, 16);
        }
        printf("%s ", temp);
        free(temp);
    }
}

// Main function
int main() {
    char sentence[1000];
    printf("Enter C Alien Language sentence:\n");
    fgets(sentence, 1000, stdin);
    removeWhitespaces(sentence);
    alienTranslate(sentence, strlen(sentence));
    return 0;
}