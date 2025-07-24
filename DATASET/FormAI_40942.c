//FormAI DATASET v1.0 Category: Unit converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function to convert Celsius to Fahrenheit
void *celsiusToFahrenheit(void* arg) {
    float celsius = *((float*) arg); // Extracting the Celsius value
    float fahrenheit = (celsius * 9/5) + 32;
    printf("%.2f Celsius = %.2f Fahrenheit \n", celsius, fahrenheit);
    return NULL;
}

// Function to convert Fahrenheit to Celsius
void *fahrenheitToCelsius(void* arg) {
    float fahrenheit = *((float*) arg); // Extracting the Fahrenheit value
    float celsius = (fahrenheit - 32) * 5/9;
    printf("%.2f Fahrenheit = %.2f Celsius \n", fahrenheit, celsius);
    return NULL;
}

// Driver code
int main() {
    pthread_t thread1, thread2; // Creating 2 threads
    
    float input;
    printf("Enter the temperature value: ");
    scanf("%f", &input);
    
    // Converting Celsius to Fahrenheit using thread 1
    if(pthread_create(&thread1, NULL, celsiusToFahrenheit, &input)) {
        printf("Error creating thread 1");
        exit(1);
    }
    
    // Converting Fahrenheit to Celsius using thread 2
    if(pthread_create(&thread2, NULL, fahrenheitToCelsius, &input)) {
        printf("Error creating thread 2");
        exit(1);
    }
    
    // Joining the threads so that main waits for them to complete
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    return 0;
}