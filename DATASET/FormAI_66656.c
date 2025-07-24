//FormAI DATASET v1.0 Category: Log analysis ; Style: imaginative
/* 
   Title: The Mysterious Log Analyzer
   Purpose: Analyze log files to uncover hidden messages
   Author: Bot Master
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_MESSAGE_LENGTH 500

// Function to analyze log file for hidden messages
void analyzeLogFile(FILE *pFile) {
    // Initialize variables
    char line[MAX_LINE_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    int wordCount = 0, characterCount = 0;
    bool isMessageFound = false;
    
    // Read each line of the file
    while (fgets(line, MAX_LINE_LENGTH, pFile)) {
        // Remove newline character from end of line
        strtok(line, "\n");
        
        // Loop through each character in the line
        for (int i = 0; i < strlen(line); i++) {
            char c = line[i];
            
            // Check if character is a letter or number
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
                wordCount++;
                characterCount++;
                
                // Check if word count has reached 6 (the length of the word "secret")
                if (wordCount == 6) {
                    // Check if the current word is "secret"
                    if (strstr(message, "secret")) {
                        isMessageFound = true;
                        break;
                    } else {
                        // Reset message for next word
                        memset(message, 0, sizeof(message));
                        wordCount = 0;
                    }
                }
                
                // Add character to message
                strncat(message, &c, 1);
            } else {
                characterCount++;
            }
        }
        
        // Check if a message has been found
        if (isMessageFound) {
            printf("The hidden message is: %s\n", message);
            break;
        }
    }
    
    // Check if a message was not found
    if (!isMessageFound) {
        printf("Sorry, no hidden message was found.\n");
    }
}

int main() {
    // Open log file
    FILE *pFile;
    pFile = fopen("log.txt", "r");
    if (pFile == NULL) {
        perror("Error opening file");
        exit(1);
    }
    
    // Analyze log file for hidden messages
    analyzeLogFile(pFile);
    
    // Close log file
    fclose(pFile);
    
    return 0;
}