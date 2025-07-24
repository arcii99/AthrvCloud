//FormAI DATASET v1.0 Category: Data validation ; Style: complex
#include<stdio.h>
#include<string.h>

int validateInput(char *input) {
    int isValid = 1;
    int len = strlen(input);
    for(int i = 0; i < len; i++) {
        if((input[i] >= 65 && input[i] <= 90) 
            || (input[i] >= 97 && input[i] <= 122)
            || input[i] == 32) {
            continue;
        } else {
            isValid = 0;
            break;
        }
    }
    return isValid;
}

int main() {
    char input[100];
    printf("Enter your name: ");
    scanf("%[^\n]s", input);
    if(validateInput(input)) {
        printf("Valid Input!\n");
        printf("Welcome, %s.", input);
    }
    else {
        printf("Invalid Input! Please enter letters and spaces only.\n");
    }
    return 0;
}