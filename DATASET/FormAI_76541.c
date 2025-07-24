//FormAI DATASET v1.0 Category: String manipulation ; Style: grateful
#include <stdio.h>
#include <string.h>

int main() {
    char msg[] = "Thank you for using my program!";
    char new_msg[50];
    
    printf("Original Message: %s\n", msg);
    printf("Modified Message: ");
    
    for(int i = 0; i < strlen(msg); i++) {
        if(msg[i] == ' ') {
            new_msg[i] = '_';
        } else {
            new_msg[i] = msg[i];
        }
        printf("%c", new_msg[i]);
    }
    
    printf("\nThank you for testing my program!\n");
    
    return 0;
}