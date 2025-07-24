//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: detailed
#include<stdio.h>
#include<ctype.h>
int main(){

    char input[100];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    int i=0, j=0;
    char sanitized[100];
    while(input[i] != '\0'){

        // Remove non-alphanumeric characters from input
        if(isalnum(input[i])){
            sanitized[j] = input[i];
            j++;
        }

        i++;
    }
    sanitized[j] = '\0'; // Adding null character manually

    printf("Sanitized input: %s\n", sanitized);

    return 0;
}