//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: cheerful
#include <stdio.h>

int main() {
    int numTerms;
    
    printf("Welcome to the Fibonacci Sequence Visualizer! Let's brighten up your day with some joyful numbers :)\n");
    
    printf("Please enter the number of terms you would like to see: ");
    scanf("%d", &numTerms);
    
    int n1 = 0, n2 = 1, nextTerm;
    
    printf("\n");
    printf("Here's your Fibonacci Sequence visualized with smileys:\n");
    
    printf(":) ");
    for (int i = 1; i <= numTerms; ++i) {
        printf("%d", n1);
        
        for (int j = 0; j < n1; ++j) {
            printf(" :)");
        }
        
        nextTerm = n1 + n2;
        n1 = n2;
        n2 = nextTerm;
        
        printf("\n");
        printf(":) ");
    }
    
    return 0;
}