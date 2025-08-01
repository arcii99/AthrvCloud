//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: happy
#include<stdio.h>

int main(){
    printf("Welcome to the Happy Circuit Simulator!\n");
    printf("Let's create a circuit that will make you smile!\n");

    int voltageInputs, currentInputs;
    printf("How many voltage inputs does your circuit have?\n");
    scanf("%d", &voltageInputs);
    printf("How many current inputs does your circuit have?\n");
    scanf("%d", &currentInputs);

    int voltageValues[voltageInputs];
    int currentValues[currentInputs];

    printf("Great! Let's now input the values of the voltage inputs.\n");
    for(int i = 0; i < voltageInputs; i++){
        printf("Enter the value of voltage input %d: ", i+1);
        scanf("%d", &voltageValues[i]);
    }

    printf("Awesome! Let's now input the values of the current inputs.\n");
    for(int i = 0; i < currentInputs; i++){
        printf("Enter the value of current input %d: ", i+1);
        scanf("%d", &currentValues[i]);
    }

    printf("Now, let's connect these inputs to some resistors and create our circuit!\n");
    printf("Enter the number of resistors you want to connect: ");
    int numberOfResistors;
    scanf("%d", &numberOfResistors);

    int resistorValues[numberOfResistors];
    int resistorNodes[numberOfResistors][2];

    printf("Enter the values of the resistors and their connecting nodes.\n");
    for(int i = 0; i < numberOfResistors; i++){
        printf("Enter the value of resistor %d: ", i+1);
        scanf("%d", &resistorValues[i]);
        printf("Enter the nodes it connects: ");
        scanf("%d %d", &resistorNodes[i][0], &resistorNodes[i][1]);
    }

    printf("Amazing! We've created our circuit with %d resistors.\n", numberOfResistors);

    printf("Let's now simulate the circuit!\n");

    int totalVoltage = 0, totalCurrent = 0;
    for(int i = 0; i < voltageInputs; i++){
        totalVoltage += voltageValues[i];
    }
    for(int i = 0; i < currentInputs; i++){
        totalCurrent += currentValues[i];
    }

    printf("The total voltage in the circuit is %d Volts.\n", totalVoltage);
    printf("The total current in the circuit is %d Amperes.\n", totalCurrent);

    int totalResistance = 0;
    for(int i = 0; i < numberOfResistors; i++){
        totalResistance += resistorValues[i];
    }
    double totalPower = (double)(totalVoltage*totalCurrent)/totalResistance;

    printf("The total resistance of the circuit is %d Ohms.\n", totalResistance);
    printf("The total power generated by the circuit is %lf Watts.\n", totalPower);

    printf("Our circuit is complete! Thank you for using the Happy Circuit Simulator.\n");
    return 0;
}