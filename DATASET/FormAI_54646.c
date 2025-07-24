//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*Defining the Circuit Components*/
struct Resistor
{
    double value;
    double current;
    double voltage;
};

struct Capacitor
{
    double capacitance;
    double voltage;
    double current;
};

struct Inductor
{
    double inductance;
    double voltage;
    double current;
};

/*Function to calculate Capactive Reactance*/
double calcCapacitiveReactance(double freq, double capacitiveValue)
{
    return (1/(2*M_PI*freq*capacitiveValue));
}

/*Function to calculate Inductive Reactance*/
double calcInductiveReactance(double freq, double inductiveValue)
{
    return (2*M_PI*freq*inductiveValue);
}

/*Function to calculate Total Impedance of given Circuit*/
double calcTotalImpedance(struct Resistor r, struct Capacitor c, struct Inductor l, double freq)
{
    double reactance = calcInductiveReactance(freq, l.inductance) - calcCapacitiveReactance(freq, c.capacitance);
    return sqrt(pow(r.value, 2) + pow(reactance, 2));
}

/*Function to calculate Current flowing through the Circuit*/
double calcCurrent(double voltage, double impedance)
{
    return voltage/impedance;
}

/*Main Program*/
int main()
{
    struct Resistor r = {10.0, 0.0, 0.0};
    struct Capacitor c = {1.0e-6, 0.0, 0.0};
    struct Inductor l = {1.0, 0.0, 0.0};
    double frequency, voltage;
    
    printf("Enter Frequency of AC Voltage: ");
    scanf("%lf", &frequency);
    printf("Enter Voltage of AC Voltage: ");
    scanf("%lf", &voltage);

    double impedance = calcTotalImpedance(r, c, l, frequency);
    double current = calcCurrent(voltage, impedance);

    r.current = current;
    r.voltage = r.value * current;

    c.current = current;
    c.voltage = calcCapacitiveReactance(frequency, c.capacitance) * c.current;

    l.current = current;
    l.voltage = calcInductiveReactance(frequency, l.inductance) * l.current;

    printf("\nCIRCUIT COMPONENTS:\n");
    printf("Resistance (Ohm): %.2lf\n", r.value);
    printf("Capacitance (Farad): %.2e\n", c.capacitance);
    printf("Inductance (Henry): %.2lf\n", l.inductance);

    printf("\nVoltage of AC Voltage: %.2lf\n", voltage);
    printf("\nTOTAL IMPEDANCE: %.2lf Ohms\n", impedance);
    printf("TOTAL CURRENT: %.2lf A\n", current);

    printf("\nVOLTAGES ACROSS CIRCUIT COMPONENTS:\n");
    printf("Resistance Voltage: %.2lf V\n", r.voltage);
    printf("Capacitor Voltage: %.2lf V\n", c.voltage);
    printf("Inductor Voltage: %.2lf V\n", l.voltage);

    return 0;
}