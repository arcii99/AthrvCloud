//FormAI DATASET v1.0 Category: Text processing ; Style: shape shifting
#include <stdio.h>
#include <ctype.h>

int main() {
    printf("Welcome to the Shape Shifting Text Processor!\n\n");

    char input[100];
    char output[100];
    int length;
    int i;

    printf("Enter some text (max 100 characters): ");
    fgets(input, 100, stdin);

    // Shapeshift 1
    length = 0;
    while(input[length] != '\0') {
        if(islower(input[length])) {
            output[length] = toupper(input[length]);
        } else if(isupper(input[length])) {
            output[length] = tolower(input[length]);
        } else {
            output[length] = input[length];
        }
        length++;
    }
    output[length] = '\0';

    printf("\nShapeshift 1: %s\n", output);

    // Shapeshift 2
    length = 0;
    i = 0;
    while(input[length] != '\0') {
        if(isalpha(input[length])) {
            if(i % 2 == 0) {
                output[length] = toupper(input[length]);
            } else {
                output[length] = tolower(input[length]);
            }
            i++;
        } else {
            output[length] = input[length];
        }
        length++;
    }
    output[length] = '\0';

    printf("\nShapeshift 2: %s\n", output);

    // Shapeshift 3
    length = 0;
    i = 0;
    while(input[length] != '\0') {
        if(isalpha(input[length])) {
            if(i % 3 == 0) {
                output[length] = toupper(input[length]);
            } else if (i % 3 == 1) {
                output[length] = tolower(input[length]);
            } else {
                output[length] = toupper(input[length]);
            }
            i++;
        } else {
            output[length] = input[length];
        }
        length++;
    }
    output[length] = '\0';

    printf("\nShapeshift 3: %s\n", output);

    return 0;
}