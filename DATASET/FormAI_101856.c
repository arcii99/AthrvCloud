//FormAI DATASET v1.0 Category: Data mining ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    int n_samples = atoi(argv[1]);
    int n_features = atoi(argv[2]);

    float data[n_samples][n_features];
    float similarities[n_samples][n_samples];

    // Generate random data
    for (int i = 0; i < n_samples; i++) {
        for (int j = 0; j < n_features; j++) {
            data[i][j] = (float)(rand() % 1000) / 1000.0;
        }
    }

    // Calculate similarities between all samples
    for (int i = 0; i < n_samples; i++) {
        for (int j = i; j < n_samples; j++) {
            float similarity = 0.0;
            for (int k = 0; k < n_features; k++) {
                similarity += (data[i][k] * data[j][k]);
            }
            similarities[i][j] = similarity;
            similarities[j][i] = similarity;
        }
    }

    // Print the similarities between all samples
    printf("Similarities between all samples:\n");
    for (int i = 0; i < n_samples; i++) {
        for (int j = 0; j < n_samples; j++) {
            printf("%.2f ", similarities[i][j]);
        }
        printf("\n");
    }

    return 0;
}