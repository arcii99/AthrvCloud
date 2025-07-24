//FormAI DATASET v1.0 Category: Text processing ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* shift(char* text, int shiftAmount) {

    int length = strlen(text);
    char* newText = (char*) malloc(sizeof(char) * length);

    for(int i=0; i < length; i++){
        int newIndex = (i + shiftAmount) % length;
        newText[newIndex] = text[i];
    }

    return newText;
}

int main() {
    char text[100];
    int shiftAmount;

    printf("Enter some text: ");
    fgets(text, 100, stdin);

    printf("Enter the shift amount: ");
    scanf("%d", &shiftAmount);

    char* shiftedText = shift(text, shiftAmount);

    printf("Original Text: %s\n", text);
    printf("Shifted Text: %s\n", shiftedText);

    free(shiftedText);

    return 0;
}