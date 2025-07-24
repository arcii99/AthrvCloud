//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: relaxed
#include <stdio.h>

int main() {
    // Declare variables
    int i, sum = 0;
    char s[100];
    
    // Get user input
    printf("Enter an input string: ");
    fgets(s, 100, stdin);
    
    // Calculate checksum
    for(i = 0; s[i] != '\0'; i++) {
        sum += (int) s[i];
    }
    
    // Print checksum
    printf("Checksum: %d\n", sum);
    
    return 0;
}