//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: romantic
// A romantic circuit simulator program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    float voltage;
    float current;
} resistor;

typedef struct{
    char name[10];
    resistor r;
} component;

typedef struct{
    component component1;
    component component2;
} circuit;

float calculate_power(resistor r, float current){
    return r.voltage * current;
}

float calculate_resistance(resistor r){
    return r.voltage / r.current;
}

int main(){
    circuit love_circuit;
    component resistor1, resistor2;
    strcpy(resistor1.name, "Romeo");
    resistor1.r.voltage = 12;
    resistor1.r.current = 2;
    strcpy(resistor2.name, "Juliet");
    resistor2.r.voltage = 12;
    resistor2.r.current = 1;

    love_circuit.component1 = resistor1;
    love_circuit.component2 = resistor2;

    printf("The resistance between Romeo and Juliet is %.2f Ohms\n", calculate_resistance(resistor1.r) + calculate_resistance(resistor2.r));
    printf("The power dissipated by Romeo is %.2f Watts\n", calculate_power(resistor1.r, resistor1.r.current));
    printf("The power dissipated by Juliet is %.2f Watts\n", calculate_power(resistor2.r, resistor2.r.current));

    printf("Romeo and Juliet are connected in series, just like our hearts.\n");
    printf("The voltage flows from Romeo to Juliet, just like my love flows towards you.\n");
    return 0;
}