//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void sanitize(char *str) { // function to sanitize user input
    char *temp = str;
    char *new_str = (char*)malloc(strlen(str) + 1); // allocate memory for new string

    if (new_str == NULL) { // check if memory allocation is successful
        printf("Error allocating memory");
        return;
    }

    int i = 0;
    while (*temp) { // loop through each character of the string
        if (((*temp >= 'a' && *temp <= 'z') || (*temp >= 'A' && *temp <= 'Z')) || (*temp >= '0' && *temp <= '9')) { // check if it's an alphanumeric character
            new_str[i] = *temp; // if yes, store it in new string
            i++;
        }
        temp++;
    }

    new_str[i] = '\0'; // add null terminator at the end

    strcpy(str, new_str); // copy the sanitized string back into original string
    free(new_str); // free the allocated memory    
}

int main() {
    char input[100];

    printf("Enter a string: ");
    fgets(input, 100, stdin); // read user input

    sanitize(input); // sanitize user input

    printf("Sanitized input: %s", input);

    return 0;
}