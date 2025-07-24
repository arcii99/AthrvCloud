//FormAI DATASET v1.0 Category: Spam Detection System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(){
    char message[1000]; // setting a maximum message size of 1000 characters
    int spam = 0; // initializing a spam counter
 
    // Get user input
    printf("Enter your message: ");
    fgets(message, 1000, stdin); // using fgets to get user input
 
    // Check for spam words
    if (strstr(message, "buy now") || strstr(message, "discount") || strstr(message, "limited time offer")){
        spam++;
    }
 
    // Additional spam checks can be added here
 
    // Print results
    if (spam > 0){
        printf("This message has been identified as spam.\n");
    }
    else{
        printf("This message is not spam.\n");
    }
 
    return 0;
}