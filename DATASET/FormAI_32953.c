//FormAI DATASET v1.0 Category: Text processing ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Retro-style text processing program
    
    char message[1000];   // declare an array for storing user input
    printf("Enter your message: ");
    fgets(message, 1000, stdin);    // read user input
    
    // Character manipulation
    for(int i=0; i < strlen(message); i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            message[i] = 'Z' - (message[i] - 'a');
        }
        else if(message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = 'z' - (message[i] - 'A');
        }
    }
    
    // Word reversal
    char reversed[1000];    // declare an array for storing reversed message
    char *word = strtok(message, " \n");  // split message by spaces and newlines
    while(word != NULL) {
        int length = strlen(word);
        for(int j=length-1; j >= 0; j--) {
            reversed[length-1-j] = word[j];
        }
        strcat(reversed, " ");   // add space between words
        word = strtok(NULL, " \n");
    }
    
    printf("\nRetro-style message:\n %s\n", reversed);
    
    return 0;
}