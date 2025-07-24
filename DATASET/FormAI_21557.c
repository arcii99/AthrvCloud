//FormAI DATASET v1.0 Category: Pattern printing ; Style: imaginative
#include <stdio.h>
#include <stdbool.h>

int main() {
    int i, j, lines;
    bool is_forward;
    
    printf("How many lines would you like to print? ");
    scanf("%d", &lines);
    
    // Ensure lines is an odd number
    if (lines % 2 == 0) {
        lines += 1;
    }
    
    // Set initial direction to forward
    is_forward = true;
    
    // Loop through each line
    for (i = 1; i <= lines; i++) {
        // Calculate number of spaces to print before pattern
        int num_spaces = abs(lines/2 - i + 1);
        for (j = 1; j <= num_spaces; j++) {
            printf(" ");
        }
        
        // Print pattern
        for (j = 1; j <= lines - 2*num_spaces; j++) {
            printf("*");
        }
        
        // Change direction if necessary
        if (i == lines/2 + 1) {
            is_forward = false;
        }
        if (is_forward) {
            printf("\n");
        }
        else {
            printf("\r");
        }
    }
    
    return 0;
}