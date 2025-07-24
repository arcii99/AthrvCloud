//FormAI DATASET v1.0 Category: Bitwise operations ; Style: futuristic
#include <stdio.h>

int main() {
    int a = 12;
    int b = 9;

    printf("The bitwise AND of %d and %d is %d\n", a, b, a & b);
    printf("The bitwise OR of %d and %d is %d\n", a, b, a | b);
    printf("The bitwise XOR of %d and %d is %d\n", a, b, a ^ b);
    printf("The bitwise complement of %d is %d\n", a, ~a);
    printf("The left shift of %d by 2 bits is %d\n", a, a << 2);
    printf("The right shift of %d by 2 bits is %d\n", a, a >> 2);

    printf("\nWelcome to the future. This program demonstrates the power of\nbitwise operations in controlling advanced technologies.\n");

    int power_management_system = 0b1111; // represents four power sources, all activated
    int temperature_sensor = 0b10101010; // represents temperature values from sensors
    int humidity_sensor = 0b11001100; // represents humidity values from sensors

    // Turning off power sources using bitwise AND operator
    power_management_system &= ~(0b0001); // Turning off power source 1
    power_management_system &= ~(0b0100); // Turning off power source 3

    printf("\nPower sources are updated according to the commands...\n");
    printf("Power management system: %d\n", power_management_system);

    // Extracting temperature and humidity values using bitwise AND operator
    int temp_value = temperature_sensor & 0b11110000; // Extracting the first 4 bits
    int hum_value = humidity_sensor & 0b00001111; // Extracting the last 4 bits

    printf("\nTemperature value from the sensors: %d\n", temp_value);
    printf("Humidity value from the sensors: %d\n", hum_value);

    // Setting the 3rd bit of temperature value to 1 using bitwise OR operator
    temp_value |= 0b00000100;

    printf("\nNew temperature value after the update: %d\n", temp_value);

    return 0;
}