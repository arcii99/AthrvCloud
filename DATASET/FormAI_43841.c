//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: random
#include<stdio.h>
#include<stdlib.h>

struct Element
{
    char name[10];
    char type;
    float value;
};

int main()
{
    int num_elements;
    printf("Enter the number of elements in the circuit: ");
    scanf("%d", &num_elements);

    struct Element circuit[num_elements];
    for(int i=0; i<num_elements; i++)
    {
        printf("Enter the details for element %d:\n", i+1);
        printf("Name: ");
        scanf("%s", circuit[i].name);
        printf("Type (R/L/C): ");
        scanf(" %c", &circuit[i].type);
        printf("Value: ");
        scanf("%f", &circuit[i].value);
    }

    float frequency, impedance;
    printf("\nEnter the frequency of the circuit: ");
    scanf("%f", &frequency);
    printf("Enter the impedance of the circuit: ");
    scanf("%f", &impedance);

    float total_impedance = 0.0;
    for(int i=0; i<num_elements; i++)
    {
        if(circuit[i].type == 'R')
            total_impedance += circuit[i].value;
        else if(circuit[i].type == 'L')
            total_impedance += 2 * 3.14 * frequency * circuit[i].value * 1i;
        else if(circuit[i].type == 'C')
            total_impedance += -1i / (2 * 3.14 * frequency * circuit[i].value);
    }

    float circuit_current = impedance / total_impedance;
    printf("\nThe circuit current is: %f\n", circuit_current);

    return 0;
}