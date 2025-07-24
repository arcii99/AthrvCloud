//FormAI DATASET v1.0 Category: Pattern printing ; Style: expert-level
#include <stdio.h> 

int main() { 
    int n, i, j, k; 
    printf("Enter the number of rows to be printed: "); 
    scanf("%d", &n); 
    
    // First half of the pattern 
    for (i = 1; i <= n; i++) { 
        for (j = i; j < n; j++) { 
            printf(" "); // Print spaces before the pattern 
        } 
        for (k = 1; k <= (2*i-1); k++) { 
            if (k == 1 || k == (2*i-1)) { // Print asterisk at the start and end of the row
                printf("*"); 
            } else { // Print spaces between asterisks
                printf(" "); 
            } 
        } 
        printf("\n"); // Move to the next row 
    }
    
    // Second half of the pattern 
    for (i = n-1; i >= 1; i--) { 
        for (j = n-1; j >= i; j--) { 
            printf(" "); // Print spaces before the pattern 
        } 
        for (k = 1; k <= (2*i-1); k++) { 
            if (k == 1 || k == (2*i-1)) { // Print asterisk at the start and end of the row
                printf("*"); 
            } else { // Print spaces between asterisks
                printf(" "); 
            } 
        } 
        printf("\n"); // Move to the next row 
    }
    
    return 0; 
}