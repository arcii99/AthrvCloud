//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXNODES 1000

struct element
{
    char name[10];
    char type;
    int node1;
    int node2;
    double value;
};

struct node
{
    double voltage;
    double prevVoltage;
};

struct element circuit[MAXNODES];
struct node nodes[MAXNODES];
int numElements = 0;
int numNodes = 0;

void addElement(char name[], char type, int node1, int node2, double value)
{
    struct element e;
    strcpy(e.name, name);
    e.type = type;
    e.node1 = node1;
    e.node2 = node2;
    e.value = value;
    circuit[numElements++] = e;
}

void stamp(char type, int node1, int node2, double value)
{
    switch (type)
    {
        case 'R':
            nodes[node1].voltage -= value;
            nodes[node2].voltage += value;
            break;
        case 'C':
            nodes[node1].voltage -= value;
            nodes[node2].voltage += value;
            break;
        case 'L':
            nodes[node1].voltage -= value;
            nodes[node2].voltage += value;
            break;
        case 'V':
            break;
        case 'I':
            break;
        default:
            break;
    }
}

void printCircuit()
{
    int i;

    printf("\n\nCIRCUIT:\n\n");

    for (i = 0; i < numElements; ++i)
    {
        printf("%s %d %d %lf\n", circuit[i].name, circuit[i].node1, circuit[i].node2, circuit[i].value);
    }
}

void printNodes()
{
    int i;

    printf("\n\nNODES:\n\n");

    for (i = 1; i <= numNodes; ++i)
    {
        printf("%d: %lf\n", i, nodes[i].voltage);
    }
}

void simulate(double timeStep, double finalTime)
{
    double time;
    int i, j;

    for (time = 0.0; time <= finalTime; time += timeStep)
    {
        for (i = 0; i < numElements; ++i)
        {
            stamp(circuit[i].type, circuit[i].node1, circuit[i].node2, circuit[i].value);
        }

        for (i = 0; i < numElements; ++i)
        {
            switch (circuit[i].type)
            {
                case 'V':
                    nodes[circuit[i].node1].voltage = circuit[i].value;
                    break;
                case 'I':
                    nodes[circuit[i].node1].voltage += circuit[i].value;
                    break;
                case 'R':
                    circuit[i].value = (nodes[circuit[i].node1].voltage - nodes[circuit[i].node2].voltage) / circuit[i].value;
                    break;
                case 'C':
                    circuit[i].value = (nodes[circuit[i].node1].voltage - nodes[circuit[i].node2].voltage) / circuit[i].value;
                    break;
                case 'L':
                    circuit[i].value = (nodes[circuit[i].node1].voltage - nodes[circuit[i].node2].voltage) / circuit[i].value;
                    break;
                default:
                    break;
            }
        }

        for (i = 0; i < numElements; ++i)
        {
            switch (circuit[i].type)
            {
                case 'V':
                    break;
                case 'I':
                    break;
                case 'R':
                    stamp(circuit[i].type, circuit[i].node1, circuit[i].node2, circuit[i].value);
                    break;
                case 'C':
                    circuit[i].value = (nodes[circuit[i].node1].voltage - nodes[circuit[i].node2].voltage) / circuit[i].value;
                    stamp(circuit[i].type, circuit[i].node1, circuit[i].node2, circuit[i].value * timeStep);
                    break;
                case 'L':
                    circuit[i].value = (nodes[circuit[i].node1].voltage - nodes[circuit[i].node2].voltage) / circuit[i].value;
                    stamp(circuit[i].type, circuit[i].node1, circuit[i].node2, circuit[i].value * timeStep);
                    break;
                default:
                    break;
            }
        }

        for (i = 1; i <= numNodes; ++i)
        {
            nodes[i].voltage = nodes[i].voltage / 2.0 + nodes[i].prevVoltage / 2.0;
            nodes[i].prevVoltage = nodes[i].voltage;
        }

        printNodes();
    }
}

int main()
{
    addElement("V1", 'V', 1, 0, 5.0);
    addElement("R1", 'R', 1, 2, 1000.0);
    addElement("C1", 'C', 2, 0, 1.0e-6);

    numNodes = 2;

    printCircuit();

    simulate(1e-6, 1e-3);

    return 0;
}