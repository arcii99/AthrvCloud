//FormAI DATASET v1.0 Category: Digital signal processing ; Style: surrealist
#include <stdio.h>

/* Surrealist Digital Signal Processing Example */
int main() {
    /* Define array of surreal numbers */
    float surreal_numbers[10] = {5.2, 4.1, 7.3, -2.4, 0.0, 8.7, -6.1, 9.9, -3.6, 1.8};

    /* Print original array */
    printf("Original array: [");
    for (int i=0; i<10; i++) {
        printf("%.1f", surreal_numbers[i]);
        if (i != 9) printf(", ");
        else printf("]\n");
    }

    /* Find average of surreal numbers */
    float sum = 0.0, average;
    for (int i=0; i<10; i++) {
        sum += surreal_numbers[i];
    }
    average = sum / 10;

    /* Subtract average from each surreal number */
    for (int i=0; i<10; i++) {
        surreal_numbers[i] -= average;
    }

    /* Print transformed array */
    printf("Transformed array: [");
    for (int i=0; i<10; i++) {
        printf("%.1f", surreal_numbers[i]);
        if (i != 9) printf(", ");
        else printf("]\n");
    }

    /* Apply surreal filter to array */
    for (int i=1; i<9; i++) {
        surreal_numbers[i] = surreal_numbers[i-1] + surreal_numbers[i] + surreal_numbers[i+1] * 1.2;
    }

    /* Print filtered array */
    printf("Filtered array: [");
    for (int i=0; i<10; i++) {
        printf("%.1f", surreal_numbers[i]);
        if (i != 9) printf(", ");
        else printf("]\n");
    }

    return 0;
}