//FormAI DATASET v1.0 Category: Digital signal processing ; Style: multivariable
#include <stdio.h>

// Function to calculate the mean of a given array
float mean(float arr[], int size)
{
    float sum = 0;
    for(int i=0; i<size; i++)
    {
        sum += arr[i];
    }
    return sum / size;
}

// Function to calculate the variance of a given array
float variance(float arr[], int size)
{
    float sum = 0;
    float avg = mean(arr, size);
    for(int i=0; i<size; i++)
    {
        sum += (arr[i]-avg)*(arr[i]-avg);
    }
    return sum / size;
}

// Function to calculate the covariance of two given arrays
float covariance(float arr1[], float arr2[], int size)
{
    float sum = 0;
    float avg1 = mean(arr1, size);
    float avg2 = mean(arr2, size);
    for(int i=0; i<size; i++)
    {
        sum += (arr1[i]-avg1)*(arr2[i]-avg2);
    }
    return sum / size;
}

// Function to filter a given signal using a moving average filter
// Input parameters: 
// 1. signal: the input signal to be filtered
// 2. size: size of the input signal
// 3. window_size: size of the moving average window
// Output:
// 1. filtered_signal: the filtered signal
void moving_avg_filter(float signal[], int size, int window_size, float filtered_signal[])
{
    for(int i=0; i<size; i++)
    {
        float sum = 0;
        int count = 0;
        for(int j=i; j<i+window_size && j<size; j++)
        {
            sum += signal[j];
            count++;
        }
        filtered_signal[i] = sum / count;
    }
}

int main()
{
    // Example usage: calculate mean, variance and covariance of two signals
    float sig1[] = {1, 3, 2, 4, 3, 5};
    float sig2[] = {2, 4, 1, 5, 2, 6};
    int size = 6;
    float mean1 = mean(sig1, size);
    float var1 = variance(sig1, size);
    float mean2 = mean(sig2, size);
    float var2 = variance(sig2, size);
    float cov = covariance(sig1, sig2, size);
    printf("Mean of signal 1: %f\n", mean1);
    printf("Variance of signal 1: %f\n", var1);
    printf("Mean of signal 2: %f\n", mean2);
    printf("Variance of signal 2: %f\n", var2);
    printf("Covariance of signals 1 and 2: %f\n", cov);

    // Example usage: filter a signal using a moving average filter
    float signal[] = {1, 3, 2, 4, 3, 5, 6, 7, 8, 9};
    int signal_size = 10;
    int window_size = 3;
    float filtered_signal[signal_size];
    moving_avg_filter(signal, signal_size, window_size, filtered_signal);
    printf("Signal after moving average filtering:\n");
    for(int i=0; i<signal_size; i++)
    {
        printf("%f ", filtered_signal[i]);
    }
    printf("\n");

    return 0;
}