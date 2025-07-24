//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: shape shifting
#include <stdio.h>
#include <string.h>

int main() {
    char input[100], output[100]; // input and output string
    int i, j, flag = 0;
    printf("Enter the text in Cat Language: ");
    gets(input); //taking input from user

    for (i = 0, j = 0; i < strlen(input); i++, j++) {
        if (input[i] == 'm' && input[i+1] == 'e' && input[i+2] == 'o' && input[i+3] == 'w') { //if the word "meow" is found
            strcat(output, "Woof"); //replace with "Woof"
            j += 3; //shift index to avoid adding "o" to output again
            flag = 1; //flag to indicate word was found
        } else {
            output[j] = input[i]; //if word not found, add letter to output
        }
    }
    output[j] = '\0'; //add null character at the end to terminate the string

    if (flag) { //if word "meow" was found
        printf("The text in Dog language is: %s\n", output); //output the translated sentence
    } else {
        printf("Sorry, no Cat language detected. Please try again with Cat language.\n"); //if no "meow" found, output error message
    }

    return 0;
}