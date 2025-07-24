//FormAI DATASET v1.0 Category: Data mining ; Style: real-life
#include <stdio.h>

// Function to find maximum value in an array
int max(int arr[], int n) {
    int maxVal = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// Function to find minimum value in an array
int min(int arr[], int n) {
    int minVal = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

int main() {
    // Sample dataset of monthly temperatures in Celcius
    int temps[] = {20, 25, 30, 35, 40, 45};
    int n = sizeof(temps) / sizeof(temps[0]);
    
    // Find max and min temperatures
    int maxTemp = max(temps, n);
    int minTemp = min(temps, n);
    
    // Find average temperature
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += temps[i];
    }
    float avgTemp = (float) sum / n;
    
    // Print data mining results
    printf("Max Temperature: %d°C\n", maxTemp);
    printf("Min Temperature: %d°C\n", minTemp);
    printf("Average Temperature: %.2f°C\n", avgTemp);
    
    return 0;
}