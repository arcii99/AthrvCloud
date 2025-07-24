//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: introspective
#include <stdio.h>

/* function to calculate the value of resistor */
double calcResistor(double volt, double curr){
    return volt / curr;
}

/* function to calculate the value of current */
double calcCurrent(double volt, double resistor){
    return volt / resistor;
}

/* function to calculate the value of voltage */
double calcVoltage(double curr, double resistor){
    return curr * resistor;
}

int main(){
    double volt = 12.0;
    double curr = 2.0;
    double resistor = calcResistor(volt, curr);
    printf("The value of the resistor is %.2f ohms.\n", resistor);

    volt = 10.0;
    resistor = 220.0;
    curr = calcCurrent(volt, resistor);
    printf("The value of the current is %.2f amps.\n", curr);

    curr = 0.5;
    resistor = 1000.0;
    volt = calcVoltage(curr, resistor);
    printf("The value of the voltage is %.4f volts.\n", volt);

    return 0;
}