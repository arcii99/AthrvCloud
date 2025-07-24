//FormAI DATASET v1.0 Category: Temperature monitor ; Style: energetic
#include <stdio.h>

int main() {
    float temperature;
    int hours;
    printf("Welcome to the Temperature Monitor Program!\n");
    printf("Please enter the current temperature in Celsius: ");
    scanf("%f", &temperature);
    printf("Please enter the number of hours for which you wish to monitor the temperature: ");
    scanf("%d", &hours);
    printf("\n\n");
    printf("==============Monitoring Temperature for %d Hours==============\n", hours);
    for(int i = 1; i <= hours; i++) {
        printf("Hour %d:\t%.2f Celsius\n", i, temperature);
        temperature += 0.10; //Simulating random temperature fluctuations
        if(temperature >= 30) {
            printf("Temperature Alert: High Temperature Detected\n");
            break;
        }
        else if(temperature <= 5) {
            printf("Temperature Alert: Low Temperature Detected\n");
            break;
        }
        else if(i == hours) {
            printf("Temperature Monitor Complete!\n");
        }
    }
    return 0;
}