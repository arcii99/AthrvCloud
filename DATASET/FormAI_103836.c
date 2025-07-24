//FormAI DATASET v1.0 Category: Temperature Converter ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

float celsius = 0;
float fahrenheit = 0;

void *celsius_to_fahrenheit(void *arg) {
    // Convert Celsius to Fahrenheit
    fahrenheit = (celsius * 9 / 5) + 32;

    printf("Temperature in Fahrenheit: %.2f°F\n", fahrenheit);  
    pthread_exit(NULL);
}

void *fahrenheit_to_celsius(void *arg) {
    // Convert Fahrenheit to Celsius
    celsius = (fahrenheit - 32) * 5 / 9;

    printf("Temperature in Celsius: %.2f°C\n", celsius);  
    pthread_exit(NULL);
}

int main() {
    pthread_t thread_c2f, thread_f2c;

    // Input temperature in Celsius
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    // Create threads for conversion
    pthread_create(&thread_c2f, NULL, celsius_to_fahrenheit, NULL);
    pthread_create(&thread_f2c, NULL, fahrenheit_to_celsius, NULL);

    // Wait for threads to finish
    pthread_join(thread_c2f, NULL);
    pthread_join(thread_f2c, NULL);

    return 0;
}