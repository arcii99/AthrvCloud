//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INPUT_LENGTH 100

bool detect_intrusion(char *input) {
    int length = strlen(input);
    int count = 0;

    for (int i = 0; i < length; i++) {
        if (input[i] == '(') {
            count++;
        } else if (input[i] == ')') {
            count--;
        }

        if (count < 0) {
            return true;
        }
    }

    return false;
}

int main() {
    printf("Welcome to our Intrusion Detection System!\n\n");

    char input[MAX_INPUT_LENGTH];
    printf("Please enter your input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    if (detect_intrusion(input)) {
        printf("Intrusion detected!\n");
    } else {
        printf("No intrusion detected.\n");
    }

    return 0;
}