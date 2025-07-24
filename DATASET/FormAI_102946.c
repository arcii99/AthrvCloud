//FormAI DATASET v1.0 Category: Text processing ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to convert the text to uppercase
void to_uppercase(char *text) {
    int i = 0;
    while(text[i] != '\0') {
        if(text[i] >= 'a' && text[i] <= 'z') {
            text[i] -= 32;
        }
        i++;
    }
}

// Function to convert the text to lowercase
void to_lowercase(char *text) {
    int i = 0;
    while(text[i] != '\0') {
        if(text[i] >= 'A' && text[i] <= 'Z') {
            text[i] += 32;
        }
        i++;
    }
}

// Function to reverse the text
void reverse_string(char *text) {
    int i = 0;
    int j = strlen(text)-1;
    while(i < j) {
        char temp = text[i];
        text[i] = text[j];
        text[j] = temp;
        i++;
        j--;
    }
}

int main() {
    char text[100];
    printf("Enter a string of maximum length 100 characters: ");
    fgets(text, 100, stdin);
    printf("\nOriginal text:\n%s", text);

    // Convert the text to uppercase
    to_uppercase(text);
    printf("\nText in uppercase:\n%s", text);

    // Convert the text to lowercase
    to_lowercase(text);
    printf("\nText in lowercase:\n%s", text);

    // Reverse the text
    reverse_string(text);
    printf("\nText in reversed order:\n%s", text);

    return 0;
}