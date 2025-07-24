//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: thoughtful
//Classical Circuit Simulator example program

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Define MAX 500 since we can't have more than 500 gates and wires
#define MAX 500 

//Structure to represent a gate
typedef struct gate{
    char type; //AND, OR, NOT, XOR etc.
    int inputs[2]; //Index of input wires
    int output; //Index of output wire
}Gate;

//Structure to represent a wire
typedef struct wire{
    bool value; //Binary value of the wire (0 or 1)
    int numDrivers; //Number of gates driving the wire
    int drivers[MAX]; //Index of gates driving the wire
}Wire;

//Global variables
int numGates = 0;
int numWires = 0;
Gate gates[MAX];
Wire wires[MAX];

//Function to add a gate to the system
void addGate(char type, int input1, int input2, int output){
    gates[numGates].type = type;
    gates[numGates].inputs[0] = input1;
    gates[numGates].inputs[1] = input2;
    gates[numGates].output = output;
    numGates++;
}

//Function to add a wire to the system
void addWire(bool value){
    wires[numWires].value = value;
    wires[numWires].numDrivers = 0;
    numWires++;
}

//Function to calculate the output of a gate given its inputs
bool calculateGateOutput(Gate gate){
    bool input1 = wires[gate.inputs[0]].value;
    bool input2 = wires[gate.inputs[1]].value;
    if(gate.type == 'A'){ return input1 && input2; } //AND gate
    else if(gate.type == 'O'){ return input1 || input2; } //OR gate
    else if(gate.type == 'N'){ return !input1; } //NOT gate
    else{ return input1 != input2; } //XOR gate
}

//Function to simulate the circuit for one step (propagate inputs through gates)
void simulateStep(){
    for(int i=0; i<numGates; i++){
        gates[i].output = calculateGateOutput(gates[i]);
        wires[gates[i].output].value = gates[i].output;
        wires[gates[i].output].drivers[wires[gates[i].output].numDrivers] = i;
        wires[gates[i].output].numDrivers++;
    }
}

//Function to print the state of the wires
void printWires(){
    for(int i=0; i<numWires; i++){
        printf("Wire %d: %d (Drives %d gates)", i, wires[i].value, wires[i].numDrivers);
        for(int j=0; j<wires[i].numDrivers; j++){ printf(" %d", wires[i].drivers[j]); }
        printf("\n");
    }
}

int main(){
    //Create wires
    addWire(false); //Wire 0
    addWire(true); //Wire 1
    addWire(false); //Wire 2

    //Create gates
    addGate('N', 0, 0, 3); //NOT gate with input from wire 0 and output to wire 3
    addGate('O', 1, 3, 4); //OR gate with inputs from wires 1 and 3, and output to wire 4
    addGate('X', 3, 4, 2); //XOR gate with inputs from wires 3 and 4, and output to wire 2

    //Simulate one step of the circuit
    simulateStep();

    //Print the state of the wires
    printWires();

    return 0;
}