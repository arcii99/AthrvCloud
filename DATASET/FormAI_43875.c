//FormAI DATASET v1.0 Category: Text processing ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>

void count_chars(char* string) {
    int count = 0;
    for(int i=0; i<strlen(string); i++) {
        if(string[i] != ' ' && string[i] != '\n') {
            count++;
        }
    }
    printf("Number of characters: %d\n", count);
}

void count_words(char* string) {
    int count = 0;
    for(int i=0; i<strlen(string); i++) {
        if(string[i] == ' ' || string[i] == '\n') {
            count++;
        }
    }
    printf("Number of words: %d\n", count+1);
}

void reverse_string(char* string) {
    int length = strlen(string);
    char temp;
    for(int i=0; i<length/2; i++) {
        temp = string[i];
        string[i] = string[length-i-1];
        string[length-i-1] = temp;
    }
    printf("Reversed string: %s\n", string);
}

int main() {
    char input[1000];

    printf("Enter a string:\n");
    fgets(input, 1000, stdin);

    count_chars(input);
    count_words(input);
    reverse_string(input);

    return 0;
}