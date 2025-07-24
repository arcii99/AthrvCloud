//FormAI DATASET v1.0 Category: Spam Detection System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Declare and initialize variables
    char input[100];
    int count = 0;
    
    // Get input from user
    printf("Enter a message: ");
    fgets(input, 100, stdin);
    
    // Check input for spam keywords
    if(strstr(input, "money")) {
        count++;
    }
    if(strstr(input, "free")) {
        count++;
    }
    if(strstr(input, "buy")) {
        count++;
    }
    
    // Display spam level
    if(count == 0) {
        printf("This message is not spam.\n");
    } else if(count == 1) {
        printf("This message is slightly spammy.\n");
    } else if(count == 2) {
        printf("This message is moderately spammy.\n");
    } else {
        printf("This message is highly spammy.\n");
    }
    
    return 0;
}