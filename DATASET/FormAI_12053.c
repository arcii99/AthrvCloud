//FormAI DATASET v1.0 Category: Data mining ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Define arrays to store data
    float height[10] = {1.65, 1.78, 1.69, 1.72, 1.80, 1.62, 1.75, 1.68, 1.79, 1.85};
    float weight[10] = {68.5, 82.0, 73.2, 75.6, 88.2, 63.7, 81.3, 72.8, 84.5, 92.0};

    // Calculate mean height and weight
    float sum_h = 0;
    float sum_w = 0;
    for(int i=0; i<10; i++){
        sum_h += height[i];
        sum_w += weight[i];
    }
    float mean_h = sum_h/10;
    float mean_w = sum_w/10;

    // Calculate standard deviation of height and weight
    float s_h = 0;
    float s_w = 0;
    for(int i=0; i<10; i++){
        s_h += pow(height[i]-mean_h, 2);
        s_w += pow(weight[i]-mean_w, 2);
    }
    s_h = sqrt(s_h/10);
    s_w = sqrt(s_w/10);

    // Print output
    printf("Mean height: %.2f\n", mean_h);
    printf("Mean weight: %.2f\n", mean_w);
    printf("Standard deviation of height: %.2f\n", s_h);
    printf("Standard deviation of weight: %.2f\n", s_w);

    return 0;
}