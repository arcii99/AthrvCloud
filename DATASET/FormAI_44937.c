//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: mathematical
#include<stdio.h> 

/* Function to generate ASCII art pattern */
void generateAsciiPattern(int n) {
    int i, j; 
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n-i; j++) {
            printf("   "); 
        }
        for(j = 1; j <= i; j++) {
            printf(" * "); 
        }
        for(j = 1; j <= n-i; j++) {
            printf("   "); 
        }
        for(j = 1; j <= i; j++) {
            printf(" * "); 
        }
        printf("\n"); 
    }
    for(i = n-1; i >= 1; i--) {
        for(j = 1; j <= n-i; j++) {
            printf("   "); 
        }
        for(j = 1; j <= i; j++) {
            printf(" * "); 
        }
        for(j = 1; j <= n-i; j++) {
            printf("   "); 
        }
        for(j = 1; j <= i; j++) {
            printf(" * "); 
        }
        printf("\n"); 
    }
}

/* Main function to read input and call ASCII art generator function */
int main() { 
    int n; 
    printf("Enter the value of n: "); 
    scanf("%d", &n);
    generateAsciiPattern(n); 
    return 0; 
}