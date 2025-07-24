//FormAI DATASET v1.0 Category: String manipulation ; Style: secure
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_LEN 100

void manipulate_string(char* input_string) {
    int str_len = strlen(input_string);

    /* Check if input string is within length limit */
    if(str_len > MAX_LEN) {
        printf("Error: Input string too long!\n");
        exit(1);
    }

    /* Allocate memory for manipulated string */
    char* manipulated_string = (char*) malloc(MAX_LEN * sizeof(char));
    if(manipulated_string == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }

    /* Copy string to manipulated_string */
    strcpy(manipulated_string, input_string);

    /* Convert all uppercase letters to lowercase */
    for(int i = 0; i < str_len; i++) {
        if(input_string[i] >= 'A' && input_string[i] <= 'Z') {
            manipulated_string[i] = input_string[i] + 32;
        }
    }

    /* Replace all spaces with dashes */
    for(int i = 0; i < str_len; i++) {
        if(manipulated_string[i] == ' ') {
            manipulated_string[i] = '-';
        }
    }

    printf("Input string: %s\n", input_string);
    printf("Manipulated string: %s\n", manipulated_string);

    /* Free allocated memory */
    free(manipulated_string);
}

int main() {
    char input_string[MAX_LEN];

    printf("Enter string: ");
    fgets(input_string, MAX_LEN, stdin);
    input_string[strcspn(input_string, "\n")] = 0; /* Remove newline character */

    manipulate_string(input_string);

    return 0;
}