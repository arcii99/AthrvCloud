//FormAI DATASET v1.0 Category: Text processing ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    char *input;
    int length, i, j, k, count = 0;
    printf("Enter a string: ");
    scanf("%[^\n]%*c", input); // reading in input with spaces

    length = strlen(input); // getting length of input string

    for (i = 0; i < length; i++) { // iterating through the string
        if (input[i] == ' ') { // checking for spaces
            count++;
        }
    }

    char **words = (char **)malloc((count+1) * sizeof(char *)); // dynamically allocating memory for words array

    j = 0;
    for (i = 0; i <= length; i++) { // looping through input string
        if (input[i] == ' ' || input[i] == '\0') { // if space or end of string is encountered
            words[j] = (char *)malloc((i-k+1) * sizeof(char)); // allocating memory for the word
            strncpy(words[j], input+k, i-k); // copying the word into the words array
            words[j][i-k] = '\0'; // setting null terminator
            k = i+1; // setting next word starting index
            j++; // incrementing word count
        }
    }

    printf("Words in the string are:\n");
    for (i = 0; i < j; i++) { // displaying the words
        printf("%s\n", words[i]);
    }

    for (i = 0; i < j; i++) { // freeing the dynamically allocated memory for words array
        free(words[i]);
    }
    free(words); // freeing the memory for the array of pointers

    return 0;
}