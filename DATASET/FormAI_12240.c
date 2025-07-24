//FormAI DATASET v1.0 Category: Text processing ; Style: peaceful
#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

int main() {
    char input_text[MAX_LEN];
    printf("Enter some text (max 1000 characters):\n");
    fgets(input_text, MAX_LEN, stdin);  // read input text from console
    
    int len = strlen(input_text);
    for (int i = 0; i < len; i++) {
        char c = input_text[i];
        if (c >= 'a' && c <= 'z') {
            c = (((c - 'a') + 13) % 26) + 'a'; // ROT13 cipher
        } else if (c >= 'A' && c <= 'Z') {
            c = (((c - 'A') + 13) % 26) + 'A';
        }
        printf("%c", c); // print the processed character
    }
    printf("\n"); // print a newline at the end
    return 0;
}