//FormAI DATASET v1.0 Category: Spam Detection System ; Style: careful
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
  
#define MAX_SIZE 1000 
  
int main() 
{ 
    char data[MAX_SIZE] = "Hello, how are you? Buy cheap pills now!"; 
    int j, spam_count = 0; 
    char* spam_words[] = {"buy", "cheap", "pills"}; 
  
    // Tokenize data string 
    char* token = strtok(data, " "); 
  
    // Loop through all tokens 
    while (token != NULL) 
    { 
        // Check if token matches any spam words 
        for (j = 0; j < 3; j++) 
        { 
            if (strcmp(token, spam_words[j]) == 0) 
            { 
                spam_count++; 
                break; 
            } 
        } 
  
        // Get next token 
        token = strtok(NULL, " "); 
    } 
  
    // Print result 
    printf("Spam count: %d\n", spam_count); 
  
    return 0; 
}