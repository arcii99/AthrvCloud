//FormAI DATASET v1.0 Category: Temperature monitor ; Style: innovative
#include <stdio.h>

int main() {
    float temperature;
    printf("Enter temperature:\n");
    scanf("%f", &temperature);

    if(temperature <= 0) {
        printf("Freezing");
    } else if(temperature > 0 && temperature <= 10) {
        printf("Very cold");
    } else if(temperature > 10 && temperature <= 20) {
        printf("Cold");
    } else if(temperature > 20 && temperature <= 30) {
        printf("Normal");
    } else if(temperature > 30 && temperature <= 40) {
        printf("Hot");
    } else if(temperature > 40 && temperature <= 50) {
        printf("Very hot");
    } else {
        printf("Extremely hot");
    }

    return 0;
}