//FormAI DATASET v1.0 Category: Text processing ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 1000

void readInput(char *input) {
    printf("Enter some text: ");
    fgets(input, MAX_LENGTH, stdin);
}

void printOutput(char *output) {
    printf("\nProcessed text: %s\n", output);
}

void preprocessText(char *input, char *output) {
    char temp[MAX_LENGTH] = "";
    int index = 0;
    for(int i=0; input[i]!='\0'; i++) {
        if(isalpha(input[i])) {
            temp[index] = tolower(input[i]);
            index++;
        } else if(input[i] == ' ') {
            temp[index] = '_';
            index++;
        }
    }
    temp[index] = '\0';
    strcpy(output, temp);
}

int main() {
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];
    readInput(input);
    preprocessText(input, output);
    printOutput(output);
    return 0;
}