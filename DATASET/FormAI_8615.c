//FormAI DATASET v1.0 Category: Spam Detection System ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

void investigate(char input[100]) {
    int length = strlen(input);
    char last_char = input[length-1];
    char second_last_char = input[length-2];
    
    if (last_char == 'C' && second_last_char == 'M') {
        printf("This looks like a spam message!\n");
    } else {
        printf("This message seems to be legitimate.\n");
    }
}

int main() {
    printf("Welcome to the C Spam Detection System.\n");
    printf("Please enter your message: ");
    
    char input[100];
    fgets(input, 100, stdin);
    
    // Remove the newline character from the input
    input[strcspn(input, "\n")] = 0;
    
    printf("We will now investigate the message...\n");
    investigate(input);
    
    return 0;
}