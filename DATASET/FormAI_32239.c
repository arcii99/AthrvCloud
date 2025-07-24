//FormAI DATASET v1.0 Category: Text processing ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

// This program demonstrates how the concept of entropy 
// can be applied to text processing

int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = '\0'; // remove newline character

    int frequency[256] = {0}; // initialize frequency array to 0
    int i;
    for (i = 0; i < strlen(input); i++) {
        char c = input[i];
        frequency[c]++;
    }

    double entropy = 0;
    int total = strlen(input);
    for (i = 0; i < 256; i++) {
        if (frequency[i] > 0) {
            double p = (double) frequency[i] / total;
            entropy -= p * log2(p); // Shannon entropy formula
        }
    }

    printf("Entropy of the input string is %.2f\n", entropy);

    return 0;
}