//FormAI DATASET v1.0 Category: Temperature Converter ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

double celsius;
double fahrenheit;

void *CelsiusToFahrenheit(void *arg) {
   double celsius = *((double*) arg);
   fahrenheit = (celsius * 1.8) + 32;
   printf("Temperature in Fahrenheit: %lf\n", fahrenheit);
}

void *FahrenheitToCelsius(void *arg) {
   double fahrenheit = *((double*) arg);
   celsius = (fahrenheit - 32) / 1.8;
   printf("Temperature in Celsius: %lf\n", celsius);
}

int main() {

   pthread_t c2fThread, f2cThread;
   double temperature;

   printf("Enter temperature in Celsius: ");
   scanf("%lf", &temperature);

   // Creating threads for Celsius to Fahrenheit conversion and Fahrenheit to Celsius conversion
   pthread_create(&c2fThread, NULL, CelsiusToFahrenheit, &temperature);
   pthread_create(&f2cThread, NULL, FahrenheitToCelsius, &fahrenheit);

   // Joining threads
   pthread_join(c2fThread, NULL);
   pthread_join(f2cThread, NULL);

   return 0;
}