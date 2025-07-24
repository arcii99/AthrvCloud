//FormAI DATASET v1.0 Category: Spell checking ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <math.h>

double compute_shannon_entropy(char *str) {
    int len = strlen(str);
    int freq[256] = {0};
    double entropy = 0.0;
    int i;

    // compute frequency of each character
    for (i = 0; i < len; i++) {
        freq[str[i]]++;
    }

    // compute probability of each character
    for (i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            double p = (double)freq[i] / (double)len;
            entropy += p * log2(p);
        }
    }

    return -entropy;
}

int main() {
    char word[] = "misspelled";
    double entropy = compute_shannon_entropy(word);
    printf("Entropy of '%s' = %.2f bits\n", word, entropy);
    return 0;
}