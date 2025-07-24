//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
 
int main() {
    char message[1000];
    printf("Enter your message in C Cat Language: ");
    fgets(message, 1000, stdin);
    
    // Cyberpunk translation
    for (int i = 0; i < strlen(message); i++) {
        if (message[i] == 'c') {
            message[i] = '5';
        } else if (message[i] == 'a') {
            message[i] = '@';
        } else if (message[i] == 't') {
            message[i] = '7';
        } else if (message[i] == 's') {
            message[i] = '$';
        } else if (message[i] == 'o') {
            message[i] = '0';
        }
    }
    
    printf("Cyberpunk Translation: %s", message);
 
    return 0;
}