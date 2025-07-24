//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// Function to generate random integers
int randInt(int min, int max) {
    return (rand() % (max - min + 1) + min);
}

// Function to calculate the mean of array
float calcMean(int data[], int len) {
    float sum = 0;
    for(int i = 0; i < len; i++) {
        sum += data[i];
    }
    return sum / len;
}

// Function to calculate the standard deviation of array
float calcSD(int data[], int len, float mean) {
    float sum = 0;
    for(int i = 0; i < len; i++) {
        sum += (data[i] - mean) * (data[i] - mean);
    }
    return sqrt(sum / len);
}

int main() {
    // Randomly generate original data
    int data[10];
    printf("Original data: [");
    for(int i = 0; i < 10; i++) {
        data[i] = randInt(0, 100);
        printf("%d, ", data[i]);
    }
    printf("]\n");

    // Calculate statistics of original data
    float mean = calcMean(data, 10);
    float sd = calcSD(data, 10, mean);

    // Embed watermarks into original data
    int wm_data[10];
    printf("Watermarked data: [");
    for(int i = 0; i < 10; i++) {
        wm_data[i] = data[i] + randInt((int)(-sd), (int)sd);
        printf("%d, ", wm_data[i]);
    }
    printf("]\n");

    // Extract watermarks from watermarked data
    int extracted_wm[10];
    printf("Extracted watermarks: [");
    for(int i = 0; i < 10; i++) {
        extracted_wm[i] = wm_data[i] - data[i];
        printf("%d, ", extracted_wm[i]);
    }
    printf("]\n");

    // Check if extracted watermarks match original watermarks
    printf("Watermarks match: ");
    for(int i = 0; i < 10; i++) {
        if(extracted_wm[i] < (int)(-sd) || extracted_wm[i] > (int)sd) {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}