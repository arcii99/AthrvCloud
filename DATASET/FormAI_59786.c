//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: mind-bending
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

int main(){
    char input[100], output[100];
    int i, j, len;

    printf("Please enter a string: ");
    fgets(input, 100, stdin);
    len = strlen(input);

    srand(time(NULL));
    for(i=0; i<len; i++){
        int r = rand() % len;
        char temp = input[i];
        input[i] = input[r];
        input[r] = temp;
    }

    printf("The randomized string is: %s", input);

    for(i=0, j=0; input[i]!='\0'; i++){
        if(isalpha(input[i]) || isdigit(input[i]))
            output[j++] = input[i];
    }
    output[j] = '\0';

    printf("The sanitized string is: %s", output);
    return 0;
}