//FormAI DATASET v1.0 Category: Temperature Converter ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

double fahrenheit_value = 0;
double celsius_value = 0;

void *fahrenheit_to_celsius(void *args)
{
    fahrenheit_value = *(double*)args;
    celsius_value = (fahrenheit_value - 32) * 5 / 9;
    printf("%.2lf Fahrenheit = %.2lf Celsius\n", fahrenheit_value, celsius_value);
    pthread_exit(NULL);
}

void *celsius_to_fahrenheit(void *args)
{
    celsius_value = *(double*)args;
    fahrenheit_value = (celsius_value * 9 / 5) + 32;
    printf("%.2lf Celsius = %.2lf Fahrenheit\n", celsius_value, fahrenheit_value);
    pthread_exit(NULL);
}

int main()
{
    pthread_t f_thread, c_thread;

    double f_temp = 100;
    pthread_create(&f_thread, NULL, fahrenheit_to_celsius, &f_temp);

    double c_temp = 25;
    pthread_create(&c_thread, NULL, celsius_to_fahrenheit, &c_temp);

    pthread_join(f_thread, NULL);
    pthread_join(c_thread, NULL);

    return 0;
}