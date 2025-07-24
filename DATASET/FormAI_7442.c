//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[100];
    int sum = 0;
    int i = 0;
    
    printf("Enter input:");
    scanf("%s", input);
    
    while (input[i] != '\0') {  // Loop through the input characters
        sum += input[i];        // Add each character's ASCII code to the running total
        i++;
    }
    
    printf("Checksum: %d\n", sum);  // Output the calculated checksum
    
    return 0;
}