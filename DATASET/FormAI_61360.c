//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: thoughtful
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* Function to remove unwanted characters from user input */
void sanitizeInput(char *input) {

    int i, j=0, n = strlen(input);
    char *temp = (char*)malloc(sizeof(char)*(n+1));
    temp[n] = '\0';

    /* Loop through the input string, copying over only allowed characters */
    for(i=0;i<n;i++) {
        if((input[i]>='a' && input[i]<='z') || (input[i]>='A' && input[i]<='Z') || (input[i]>='0' && input[i]<='9') || input[i] == '\n') {
            temp[j] = input[i];
            j++;
        }
    }

    /* Copy the sanitized input string back to original input */
    strcpy(input, temp);
    free(temp);
}

int main() {

    char input[100];

    printf("Enter some text that needs to be sanitized:\n");
    fgets(input, 100, stdin);

    /* Call the sanitizeInput function to remove unwanted characters */
    sanitizeInput(input);

    printf("\nSanitized input is:\n%s\n", input);

    return 0;

}