//FormAI DATASET v1.0 Category: Digital signal processing ; Style: paranoid
#include <stdio.h> 

/* Paranoid Digital Signal Processing Program */
int main() 
{ 
    int signal[10] = {1, -1, 2, -2, 3, -3, 4, -4, 5, -5};  /* Input signal */
    int filtered_signal[10] = {0};  /* Filtered output signal */

    /* Apply filter */ 
    for(int i=0; i<10; i++) {
        for(int j=-1; j<=1; j++) {
            if(i+j >= 0 && i+j <= 9) {
                filtered_signal[i] += signal[i+j];  /* Add adjacent signal values */
            }
        }
        filtered_signal[i] /= 3;  /* Average of adjacent signal values */
    }

    /* Print original signal */ 
    printf("Original Signal: ");
    for(int i=0; i<10; i++) {
        printf("%d ", signal[i]);
    }
    printf("\n");

    /* Print filtered signal */ 
    printf("Filtered Signal: ");
    for(int i=0; i<10; i++) {
        printf("%d ", filtered_signal[i]);  
    }
    printf("\n");

    /* Check for anomalies */
    for(int i=0; i<10; i++) {
        if(filtered_signal[i] < 0) {
            printf("Warning! Negative value detected in filtered signal!\n");  /* Alert for negative values */
        }
        if(filtered_signal[i] > signal[i]) {
            printf("Warning! Filtered signal exceeds original signal at index %d!\n", i);  /* Alert for magnitude increase */
        }
        if(filtered_signal[i] == signal[i]) {
            printf("Warning! Filtered signal is identical to original signal at index %d!\n", i);  /* Alert for identical values */
        }
    }
  
    return 0; 
}