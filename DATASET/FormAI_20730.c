//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: synchronous
#include <stdio.h>
#include <string.h>

void morse(char ch) {
    switch(tolower(ch)) {
        case 'a':
            printf(".- ");
            break;
        case 'b':
            printf("-... ");
            break;
        // more cases for letters and numbers, symbols
        default:
            printf("? ");
            break;
    }
}

int main() {
    char message[100];
    printf("Enter message to convert to Morse code: ");
    scanf("%[^\n]%*c", message);
    
    // iterate over each character in the message
    for(int i = 0; i < strlen(message); i++) {
        // skip spaces
        if(message[i] == ' ') {
            printf("  ");
        }
        else {
            morse(message[i]);
        }
    }
    
    return 0;
}