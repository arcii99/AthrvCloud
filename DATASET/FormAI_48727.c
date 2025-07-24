//FormAI DATASET v1.0 Category: String manipulation ; Style: Alan Touring
//Program to manipulate C strings in Alan Turing Style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char message[50] = "Hello, World!"; //Initial message
    int choice, length = strlen(message);
    char temp[50]; //Temporary string to store manipulated strings
    
    printf("Original Message: %s\n", message);
    
    printf("\nChoose an option:\n");
    printf("1. Reverse the message\n");
    printf("2. Remove vowels\n");
    printf("3. Replace characters\n");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1: //Reverse the message
            for(int i=0; i<length/2; i++) {
                temp[i] = message[i];
                message[i] = message[length-1-i];
                message[length-1-i] = temp[i];
            }
            printf("Reversed Message: %s\n", message);
            break;
        
        case 2: //Remove vowels
            for(int i=0, j=0; i<length; i++) {
                if(message[i] != 'a' && message[i] != 'e' && message[i] != 'i' && message[i] != 'o' && message[i] != 'u' &&
                   message[i] != 'A' && message[i] != 'E' && message[i] != 'I' && message[i] != 'O' && message[i] != 'U') {
                    temp[j] = message[i];
                    j++;
                }
            }
            temp[length] = '\0';
            strcpy(message, temp);
            printf("Message without vowels: %s\n", message);
            break;
        
        case 3: //Replace characters
            char c1, c2;
            printf("Enter the character to replace: ");
            scanf(" %c", &c1);
            printf("Enter the new character: ");
            scanf(" %c", &c2);
            for(int i=0; i<length; i++) {
                if(message[i] == c1) {
                    message[i] = c2;
                }
            }
            printf("Modified Message: %s\n", message);
            break;
        
        default: //Invalid option
            printf("Invalid Choice!\n");
            break;
    }
    
    return 0;
}