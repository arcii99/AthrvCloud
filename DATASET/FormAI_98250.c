//FormAI DATASET v1.0 Category: Computer Biology ; Style: excited
#include <stdio.h>

// Welcome to my exciting Computer Biology program! 
// In this program, we will be calculating the GC content of a DNA sequence.

int main() {

    // First, let's input the DNA sequence
    printf("Enter the DNA sequence: ");
    char dnaSeq[1000];
    fgets(dnaSeq, 1000, stdin);
    
    // Let's count the number of GC bases in the sequence
    int gcCount = 0;
    for (int i = 0; dnaSeq[i] != '\0'; i++) {
        if (dnaSeq[i] == 'G' || dnaSeq[i] == 'C') {
            gcCount++;
        }
    }
    
    // Now let's calculate the GC content as a percentage
    float gcContent = (float) gcCount / strlen(dnaSeq) * 100;
    
    // Finally, let's output the GC content to the user
    printf("GC content: %.2f%%\n", gcContent);
    
    return 0;
}