//FormAI DATASET v1.0 Category: Pattern printing ; Style: satisfied
#include <stdio.h>

int main() {
    
    // Displaying a unique C pattern
    printf("\n\n");
    printf("\t    C C C C\n");
    printf("\t  C        \n");
    printf("\t C         \n");
    printf("\tC          \n");
    printf("\tC          \n");
    printf("\tC          \n");
    printf("\tC          \n");
    printf("\tC          \n");
    printf("\t C         \n");
    printf("\t  C        \n");
    printf("\t    C C C C\n");
    printf("\n\n");
    
    // Now we will display the same pattern using for loops
    
    int i, j;
    int rows = 10;
    int spaces = 2;
    
    // Top rows
    for(i=1; i<=rows/2; i++) {
        for(j=1; j<=spaces; j++) {
            printf(" ");
        }
        printf("C");
        for(j=spaces+1; j<=(rows/2-i)*2; j++) {
            printf(" ");
        }
        if(i==1) { // First row exception
            printf(" C C C C");
        }
        else {
            printf(" ");
        }
        for(j=1; j<=(i-1)*4; j++) {
            printf(" ");
        }
        printf("C");
        for(j=1; j<=spaces; j++) {
            printf(" ");
        }
        printf("\n");
        spaces += 2;
    }
    
    // Middle row
    for(i=1; i<=2; i++) {
        for(j=1; j<=spaces; j++) {
            printf(" ");
        }
        printf("C C C C C C C\n");
    }
    
    // Bottom rows
    spaces -= 2;
    for(i=rows/2; i>=1; i--) {
        spaces -= 2;
        for(j=1; j<=spaces; j++) {
            printf(" ");
        }
        printf("C");
        for(j=1; j<=(i-1)*4; j++) {
            printf(" ");
        }
        if(i==1) { // Last row exception
            printf(" C C C C");
        }
        else {
            printf(" ");
        }
        for(j=spaces+1; j<=(rows/2-i)*2; j++) {
            printf(" ");
        }
        printf("C");
        for(j=1; j<=spaces; j++) {
            printf(" ");
        }
        printf("\n");
    }
    
    printf("\n\n");
    
    return 0;
}