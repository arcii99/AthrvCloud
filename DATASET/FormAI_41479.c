//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the Euclidean distance
int euclideanDistance(int a[], int b[], int size) {
    int distance = 0;
    for (int i = 0; i < size; i++) {
        distance += (a[i] - b[i]) * (a[i] - b[i]);
    }
    return distance;
}

// Function to embed a watermark in the image with given key and intensity
void embedWatermark(int image[][100], int key[], int intensity, int size) {
    int watermark[size][size];
    int k = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            watermark[i][j] = key[k];
            k++;
        }
    }
    int n = size * size;
    int distances[n];
    int closest[n];
    for (int i = 0; i < n; i++) {
        distances[i] = 1000000000;
        closest[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int ii = 0; ii < size; ii++) {
                for (int jj = 0; jj < size; jj++) {
                    int distance = euclideanDistance(watermark[ii], watermark[jj], size);
                    if (i == ii && j == jj) {
                        continue;
                    }
                    if (distance < distances[i * size + j]) {
                        distances[i * size + j] = distance;
                        closest[i * size + j] = ii * size + jj;
                    }
                }
            }
        }
    }
    int embedded[size][size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            embedded[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        int ai = closest[i] / size;
        int aj = closest[i] % size;
        int bi = i / size;
        int bj = i % size;
        int intensityDiff = (watermark[ai][aj] - watermark[bi][bj]) * intensity / 100;
        embedded[bi][bj] += intensityDiff;
    }
    printf("The embedded image is:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", embedded[i][j]);
        }
        printf("\n");
    }
}

// Function to extract a watermark from the image with given key and intensity
void extractWatermark(int image[][100], int key[], int intensity, int size) {
    int watermark[size][size];
    int k = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            watermark[i][j] = key[k];
            k++;
        }
    }
    int n = size * size;
    int distances[n];
    int closest[n];
    for (int i = 0; i < n; i++) {
        distances[i] = 1000000000;
        closest[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int ii = 0; ii < size; ii++) {
                for (int jj = 0; jj < size; jj++) {
                    int distance = euclideanDistance(watermark[ii], watermark[jj], size);
                    if (i == ii && j == jj) {
                        continue;
                    }
                    if (distance < distances[i * size + j]) {
                        distances[i * size + j] = distance;
                        closest[i * size + j] = ii * size + jj;
                    }
                }
            }
        }
    }
    int extracted[size][size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            extracted[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        int ai = closest[i] / size;
        int aj = closest[i] % size;
        int bi = i / size;
        int bj = i % size;
        int intensityDiff = (watermark[ai][aj] - watermark[bi][bj]) * intensity / 100;
        extracted[bi][bj] -= intensityDiff;
    }
    printf("The extracted image is:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", extracted[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int size, intensity;
    printf("Enter the size of the image: ");
    scanf("%d", &size);
    printf("Enter the intensity (percentage) of the watermark: ");
    scanf("%d", &intensity);
    int key[size * size];
    printf("Enter the key of the watermark: ");
    for (int i = 0; i < size * size; i++) {
        scanf("%d", &key[i]);
    }
    int image[size][100];
    printf("Enter the image: \n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &image[i][j]);
        }
    }
    embedWatermark(image, key, intensity, size);
    extractWatermark(image, key, intensity, size);
    return 0;
}