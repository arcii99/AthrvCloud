//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void generate_sequence(int n, int* sequence) {
    if (n == 1) {
        sequence[0] = rand() % 4;
    } else {
        generate_sequence(n - 1, sequence);
        int last = sequence[n - 2];
        int current = rand() % 3;
        if (current >= last) {
            current++;
        }
        sequence[n - 1] = current;
    }
}

int main() {
    int n;
    printf("Enter the length of the sequence: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid sequence length.\n");
        return 1;
    }
    int* sequence = malloc(sizeof(int) * n);
    generate_sequence(n, sequence);
    printf("Generated sequence: ");
    for (int i = 0; i < n; i++) {
        printf("%d", sequence[i]);
    }
    printf("\n");
    free(sequence);
    return 0;
}