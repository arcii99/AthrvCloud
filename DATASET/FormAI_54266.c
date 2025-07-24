//FormAI DATASET v1.0 Category: Syntax parsing ; Style: cheerful
#include<stdio.h>

//Welcome message
void welcome() {
    printf("Hello there! Let's parse some C syntax and have fun!\n");
}

int main() {
    // call the welcome message
    welcome();

    //ask for user input
    printf("\nEnter a C syntax code snippet: ");
    char codeSnippet[100];
    fgets(codeSnippet, 100, stdin);

    //parse the C Syntax
    int count = 0;
    for(int i = 0; i < strlen(codeSnippet); i++) {
        if(codeSnippet[i] == '{') {
            count++;
        } else if(codeSnippet[i] == '}') {
            count--;
        }
    }

    //check if the syntax is correct
    if(count == 0) {
        printf("\nCongratulations!! The syntax is correct.");

        //offer solution to improve code
        char answer;
        printf("\nDo you want to know how to make this code better?\n");
        printf("Type 'y' for yes or 'n' for no: ");
        scanf("%c", &answer);

        if(answer == 'y') {
            printf("\nTo improve this code, you can add a comment to explain its purpose and make it more readable.\n");
        } 
        else {
            printf("\nOkay, have a nice day!");
        }
    } 
    else {
        printf("\nOops! The syntax is incorrect. Please check your code again.");
    }

    return 0;
}