//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Romeo and Juliet
/* Romeo and Juliet's Fibonacci Sequence Visualizer */

#include <stdio.h>

int main() {
    int n, i, t1 = 0, t2 = 1, nextTerm;
    
    printf("Oh Juliet, let's visualize the Fibonacci sequence,\n");
    printf("The sequence is a magical wonder I believe?\n");
    printf("Pray, tell me what number we should take up to,\n");
    printf("And I shall make this wonder for us to view.\n");
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    
    printf("The Fibonacci Sequence till %d terms is as follows:\n", n);
    
    for (i = 1; i <= n; i++) {
        if(i == 1) {
            printf("%d, ", t1);
            continue;
        }
        if(i == 2) {
            printf("%d, ", t2);
            continue;
        }
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        printf("%d, ", nextTerm);
    }
    printf("\n\nAlas! This is such a beautiful sequence,\n");
    printf("What lovely patterns and rhythms we can perceive.\n");
    printf("Truly, a marvel of nature and mathematics,\n");
    printf("Thank you, dearest Romeo, for this lovely visual treat.\n");  
    
    return 0;
}