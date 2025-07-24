//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: standalone
#include<stdio.h>
#include<stdlib.h>

void clear() {
    // Clear the console
    system("@cls||clear");
}

int main() {
    
    int n, a = 0, b = 1, c = 0, i = 0, j = 0;
    
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    
    clear();  // Clear the console
    
    printf("The Fibonacci Sequence of %d terms:\n\n", n);
    printf("%d, %d", a, b);
    
    c = a + b;
    
    // Print the sequence
    for(i = 3; i <= n; i++){
        printf(", %d", c);
        
        a = b;
        b = c;
        c = a + b;
        
        // Add visualizer
        printf("\n");
        for(j = 0; j < c; j++) {
            if(j < b && j >= a) {
                printf("  *");
            } else {
                printf("   ");
            }
        }   
        printf("\n");
    }
    
    return 0;
}