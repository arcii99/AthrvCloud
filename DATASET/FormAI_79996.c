//FormAI DATASET v1.0 Category: Digital signal processing ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
 
int main()
{
    int signal[6] = {1, -2, 3, -4, 5, -6};    // Input signal
    int n = sizeof(signal)/sizeof(int);      // Length of signal
 
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",signal[i]);              // Print input signal
    }
 
    printf("\n\n");
 
    // Start signal processing here
    int j;
    for(j=0;j<3;j++)
    {
        int temp = signal[j];
        signal[j] = signal[n-j-1];
        signal[n-j-1] = temp;                 // Invert signal
    }
 
    for(i=0;i<n;i++)
    {
        printf("%d ",signal[i]);              // Print output signal
    }
 
    printf("\n");
  
    return 0;
}