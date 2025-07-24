//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: recursive
#include<stdio.h>

void calc_voltage(float, float);

int main()
{
    float voltage, resistance;

    printf("Enter the voltage value: ");
    scanf("%f", &voltage);

    printf("Enter the resistance value: ");
    scanf("%f", &resistance);

    calc_voltage(voltage, resistance);

    return 0;
}

void calc_voltage(float v, float r)
{
    if(r <= 0)
    {
        printf("Invalid resistance value!\n");
        return;
    }

    float current = v / r;
    float power = v * current;

    printf("Current: %f A\n", current);
    printf("Power: %f W\n", power);

    printf("Enter another resistance value (or negative value to quit): ");
    scanf("%f", &r);

    if(r < 0)
    {
        printf("Goodbye!\n");
        return;
    }

    calc_voltage(v, r);
}