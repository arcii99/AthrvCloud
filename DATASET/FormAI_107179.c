//FormAI DATASET v1.0 Category: Spam Detection System ; Style: surprised
#include <stdio.h>
#include <string.h>

int main() {
    char message[100];
    int count = 0;
    int len = 0;
    
    printf("Enter a message: ");
    fgets(message, 100, stdin); // gets the user input
    
    len = strlen(message); // get the length of the message
    
    for(int i=0; i<len; i++) {
        if(message[i] == 's' && message[i+1] == 'p' && message[i+2] == 'a' && message[i+3] == 'm') { // check if the pattern spam is found
            count++;
        }
    }
    
    if(count > 0) {
        printf("SPAM DETECTED: %d occurrences of 'spam' found in the message.\n", count);
    } else {
        printf("No spam detected in the message.\n");
    }
    
    return 0;
}