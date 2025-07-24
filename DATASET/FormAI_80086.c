//FormAI DATASET v1.0 Category: Error handling ; Style: Romeo and Juliet
#include <stdio.h>

int main()
{
    int romeo_age = 20;
    int juliet_age = 16;
    
    printf("Enter Romeo's age: ");
    scanf("%d", &romeo_age);
    printf("Enter Juliet's age: ");
    scanf("%d", &juliet_age);
    
    if (romeo_age < 18 || juliet_age < 18) {
        printf("Error: Romeo and Juliet must be of legal age.\n");
        return 1; // exit program with error code
    }
    
    printf("Romeo and Juliet's ages are %d and %d respectively.\n", romeo_age, juliet_age);
    
    return 0;
}