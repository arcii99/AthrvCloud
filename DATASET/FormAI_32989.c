//FormAI DATASET v1.0 Category: Recursive ; Style: peaceful
#include <stdio.h>

void peacefulRecursion(int count) {
    if(count <= 0) return; // Recursive exit condition
    
    int i = 0;
    for(i=0; i<10; ++i) {
        printf("%d\n", i); // Print the current counter value
        peacefulRecursion(count - 1); // Recursive call
    }
}

int main() {
    peacefulRecursion(5); // Start the recursion with the value 5
    return 0;
}