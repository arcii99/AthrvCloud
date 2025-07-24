//FormAI DATASET v1.0 Category: Spam Detection System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[100];
    int i, j, flag;
    
    // Define spam keywords
    char keywords[3][20] = {"free", "offer", "limited time"};
    
    while(1) {
        printf("\nEnter your message: ");
        fgets(input, 100, stdin);
        
        flag = 0;
        
        for(i = 0; i < strlen(input) - 1; i++) {
            if(input[i] == ' ') {
                char temp[20];
                memset(temp, 0, sizeof(temp)); // Clear temp array
                
                // Get the word before the space
                for(j = 0; j < i; j++) {
                    temp[j] = input[j];
                }
                
                // Check if the word is a spam keyword
                for(j = 0; j < 3; j++) {
                    if(strncmp(temp, keywords[j], strlen(keywords[j])) == 0) {
                        flag = 1;
                        break;
                    }
                }
                
                memset(temp, 0, sizeof(temp)); // Clear temp array
            }
        }
        
        if(flag == 1) {
            printf("Warning: Spam detected!\n");
        }
        else {
            printf("Message sent successfully.\n");
        }
    }
    
    return 0;
}