//FormAI DATASET v1.0 Category: Pattern printing ; Style: scalable
#include <stdio.h>
int main() {

    // Set pattern size
    int size = 10;
    
    // Iterate through each row
    for(int i = 0; i < size; i++) {
        
        // Print leading spaces
        for(int j = 0; j < i; j++) {
            printf(" ");
        }
        
        // Print alternating pattern
        for(int j = 0; j < size - i; j++) {
            if(j % 2 == 0) {
                printf("/");
            } else {
                printf("\\");
            }
        }
        
        // Print trailing spaces
        for(int j = 0; j < i; j++) {
            printf(" ");
        }
        
        // Add new line
        printf("\n");
    }
    
    // Iterate through each row
    for(int i = size-1; i >= 0; i--) {
        
        // Print leading spaces
        for(int j = 0; j < i; j++) {
            printf(" ");
        }
        
        // Print alternating pattern
        for(int j = 0; j < size - i; j++) {
            if(j % 2 == 0) {
                printf("\\");
            } else {
                printf("/");
            }
        }
        
        // Print trailing spaces
        for(int j = 0; j < i; j++) {
            printf(" ");
        }
        
        // Add new line
        printf("\n");
    }
    
    return 0;
}