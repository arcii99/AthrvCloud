//FormAI DATASET v1.0 Category: System boot optimizer ; Style: mathematical
#include <stdio.h> 
#include <stdlib.h>

int main() 
{
    int i, j, k; 
    int N = 100; // number of boot processes
    int boot_times[N]; // array of boot process times
    
    // initialize boot_times array with random values between 1 and 30
    for (i=0; i<N; i++) 
    {
        boot_times[i] = rand() % 30 + 1;
    }
    
    // sort boot_times array in ascending order using bubble sort algorithm
    for (i=0; i<N-1; i++) 
    {
        for (j=0; j<N-i-1; j++) 
        {
            if (boot_times[j] > boot_times[j+1]) 
            {
                // swap boot_times[j] and boot_times[j+1]
                k = boot_times[j];
                boot_times[j] = boot_times[j+1];
                boot_times[j+1] = k;
            }
        }
    }
    
    // calculate average boot time
    int sum = 0;
    float avg;
    for (i=0; i<N; i++) 
    {
        sum += boot_times[i];
    }
    avg = (float)sum / N;
    
    // calculate standard deviation of boot time
    float std_dev = 0;
    for (i=0; i<N; i++) 
    {
        std_dev += (boot_times[i] - avg) * (boot_times[i] - avg);
    }
    std_dev = sqrt(std_dev / N);
    
    // print boot_times array, average boot time and standard deviation of boot time
    printf("Boot process times:\n");
    for (i=0; i<N; i++) 
    {
        printf("%d ", boot_times[i]);
    }
    printf("\n");
    printf("Average boot time: %.2f\n", avg);
    printf("Standard deviation of boot time: %.2f\n", std_dev);
    
    return 0; 
}