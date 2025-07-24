//FormAI DATASET v1.0 Category: Image Classification system ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int image[28][28]; // Image matrix
    int i = 0, j = 0; // Loop variables
    int sum = 0; // Sum of intensities

    // Filling the image with random intensity values between 0 and 255
    for(i = 0; i < 28; i++) {
        for(j = 0; j < 28; j++) {
            image[i][j] = rand()%256;
            sum += image[i][j];
        }
    }

    // Calculating average intensity
    float avg_intensity = (float) sum / (28*28);

    // Classifying the image based on average intensity
    if(avg_intensity < 100) {
        printf("Image belongs to Class A\n");
    } else if(avg_intensity < 200) {
        printf("Image belongs to Class B\n");
    } else {
        printf("Image belongs to Class C\n");
    }

    return 0;
}