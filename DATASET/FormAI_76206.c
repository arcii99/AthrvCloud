//FormAI DATASET v1.0 Category: Spam Detection System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SPAM_THRESHOLD 0.7 // Set spam threshold to 70%

int main() {
    char message[1000];
    int i, j, len;
    int count_lowercase = 0, count_uppercase = 0, count_digits = 0, count_spaces = 0;
    float spam_score;
    
    printf("Enter your message: ");
    fgets(message, 1000, stdin); // Read message from user
    
    len = strlen(message);
    for(i=0; i<len; i++) {
        if(message[i] >= 'a' && message[i] <= 'z') { // Count lowercase characters
            count_lowercase++;
        }
        else if(message[i] >= 'A' && message[i] <= 'Z') { // Count uppercase characters
            count_uppercase++;
        }
        else if(message[i] >= '0' && message[i] <= '9') { // Count digits
            count_digits++;
        }
        else if(message[i] == ' ') { // Count spaces
            count_spaces++;
        }
    }
    
    spam_score = (count_lowercase / (float) len) + (count_uppercase / (float) len) + (count_digits / (float) len) + (count_spaces / (float) len);
    if(spam_score >= SPAM_THRESHOLD) {
        printf("WARNING: This message may be spam!\n");
    }
    else {
        printf("This message is not spam.\n");
    }
    
    return 0;
}