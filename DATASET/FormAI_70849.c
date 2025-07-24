//FormAI DATASET v1.0 Category: Text processing ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

// Function to calculate the entropy of a given string
double calcEntropy(char* str) {
    int len = strlen(str);
    int freq[256] = {0};
    
    // Count the frequency of each character
    for(int i = 0; i < len; i++) {
        freq[str[i]]++;
    }
    
    // Calculate the entropy
    double entropy = 0.0;
    for(int i = 0; i < 256; i++) {
        if(freq[i] > 0) {
            double p = (double) freq[i] / len;
            entropy += -p * log2(p);
        }
    }
    
    return entropy;
}

int main() {
    char input[100];
    
    // Take input from the user
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    
    // Calculate the entropy and display the result
    double entropy = calcEntropy(input);
    printf("Entropy of the string '%s' is %.2f bits/byte\n", input, entropy);
    
    return 0;
}