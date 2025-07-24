//FormAI DATASET v1.0 Category: String manipulation ; Style: medieval
#include <stdio.h>
#include <string.h>

int main() {
    char message[] = "A fair maiden sat atop her tower, waiting for her knight in shining armor to come to her aid.";
    char pattern[] = "knight";
    
    int len_message = strlen(message);
    int len_pattern = strlen(pattern);
    
    for(int i = 0; i <= len_message - len_pattern; i++) {
        int j;
        
        for(j = 0; j < len_pattern; j++) {
            if(message[i + j] != pattern[j]) {
                break;
            }
        }
        
        if(j == len_pattern) {
            printf("The fair maiden's knight has arrived!\n");
            printf("Original message: %s\n", message);
            printf("Modified message: ");
            
            for(int k = 0; k < i; k++) {
                printf("%c", message[k]);
            }
            
            printf("brave knight");
            
            for(int k = i + len_pattern; k < len_message; k++) {
                printf("%c", message[k]);
            }
            
            break;
        }
    }
    
    return 0;
}