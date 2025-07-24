//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: surrealist
#include <stdio.h>
#include <ctype.h>

int main() {
    char input[100];
    printf("Input some text to sanitize: ");
    fgets(input, 100, stdin);
    
    printf("Your sanitized input is: ");
    for(int i = 0; i < 100; i++) {
        if(input[i] == '\n') {
            break;
        } else if(isalpha(input[i])) {
            putchar(tolower(input[i]));
        } else {
            putchar('X');
        }
        
        if(i % 3 == 0) {
            putchar('#');
        }
    }
    putchar('\n');
    
    return 0;
}