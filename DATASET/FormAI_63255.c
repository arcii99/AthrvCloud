//FormAI DATASET v1.0 Category: Text processing ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char message[1000]; // Create a character array to store input message
    printf("Enter your message: "); // Display message prompt
    fgets(message, 1000, stdin); // Take input message from user
    
    int i, j, k, length, count;
    char temp[1000]; // Create a temporary character array
    
    length = strlen(message); // Calculate length of input message
    
    for (i = 0, j = 0; i < length; i++) {
        // Check if current character is an alphabet or a space
        if ((message[i] >= 'a' && message[i] <= 'z') || (message[i] >= 'A' && message[i] <= 'Z') || message[i] == ' ') {
            temp[j] = message[i]; // If yes, copy it to temporary array
            j++;
        }
    }
    temp[j] = '\0'; // Add terminating character to temporary array
    
    length = strlen(temp); // Calculate length of temporary array
    
    // Convert all characters to lowercase
    for (i = 0; i < length; i++) {
        if (temp[i] >= 'A' && temp[i] <= 'Z') {
            temp[i] = temp[i] + 32;
        }
    }
    
    // Count the frequency of each word
    for (i = 0; i < length; i++) {
        count = 1;
        if (temp[i] != ' ') {
            for (j = i + 1; j < length; j++) {
                if (temp[i] == temp[j]) {
                    count++;
                    temp[j] = ' ';
                }
            }
            printf("%c - %d\n", temp[i], count);
        }
    }
    
    return 0;
}