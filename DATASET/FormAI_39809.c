//FormAI DATASET v1.0 Category: Spam Detection System ; Style: creative
#include <stdio.h>
#include <string.h>

int main() {
    char message[1000];
    int count = 0;
    
    printf("Enter a message:\n");
    fgets(message, 1000, stdin);
    
    char *spamKeywords[] = {"free", "money", "prize", "deal", "offer"};
    int numKeywords = 5;
    
    char *token = strtok(message, " (),.-!?\n");
    
    while(token) {
        for(int i = 0; i < numKeywords; i++) {
            if(strcasecmp(token, spamKeywords[i]) == 0) {
                count++;
            }
        }
        token = strtok(NULL, " (),.-!?\n");
    }
    
    if(count > 2) {
        printf("\nThis message is tagged as spam.\n");
    } else {
        printf("\nThis message is not spam.\n");
    }
    
    return 0;
}