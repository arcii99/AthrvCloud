//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_NODES 100
#define MAX_INPUTS 10

typedef struct{
    int in[MAX_INPUTS];
    int out;
} Gate;

typedef struct{
    Gate gates[MAX_NODES];
    int inputCount;
    int outputCount;
    int gateCount;
} Circuit;

bool evalGate(Circuit* circuit, int i, bool values[MAX_NODES], bool cache[MAX_NODES]){
    if(circuit->gates[i].in[0] == -1){
        return values[circuit->gates[i].out];
    }
    else if(cache[i] == true){
        return values[circuit->gates[i].out];
    }
    else{
        bool result;
        switch(circuit->gates[i].in[0]){
            case -2:
                result = evalGate(circuit, i-1, values, cache);
                break;
            case -3:
                result = !evalGate(circuit, i-1, values, cache);
                break;
            default:
                result = evalGate(circuit, circuit->gates[i].in[0], values, cache);
        }

        for(int j = 1; j < MAX_INPUTS && circuit->gates[i].in[j] != -1; j++){
            switch(circuit->gates[i].in[j]){
                case -2:
                    result = result && evalGate(circuit, i-j-1, values, cache);
                    break;
                case -3:
                    result = result && !evalGate(circuit, i-j-1, values, cache);
                    break;
                default:
                    result = result && evalGate(circuit, circuit->gates[i].in[j], values, cache);
            }
        }

        cache[i] = true;
        values[circuit->gates[i].out] = result;
        return result;
    }
}

bool eval(Circuit* circuit, bool values[MAX_NODES]){
    bool cache[MAX_NODES];
    for(int i = 0; i < MAX_NODES; i++){
        cache[i] = false;
    }

    bool result = evalGate(circuit, circuit->gateCount-1, values, cache);

    for(int i = 0; i < circuit->inputCount; i++){
        values[i] = false;
    }

    return result;
}

int main(){
    Circuit circuit;
    circuit.inputCount = 2;
    circuit.outputCount = 1;
    circuit.gateCount = 5;

    circuit.gates[0].in[0] = 0;
    circuit.gates[0].in[1] = 1;
    circuit.gates[0].out = 2;

    circuit.gates[1].in[0] = -2;
    circuit.gates[1].in[1] = 2;
    circuit.gates[1].out = 3;

    circuit.gates[2].in[0] = 0;
    circuit.gates[2].in[1] = -3;
    circuit.gates[2].out = 4;

    circuit.gates[3].in[0] = 1;
    circuit.gates[3].in[1] = 4;
    circuit.gates[3].out = 5;

    circuit.gates[4].in[0] = 3;
    circuit.gates[4].in[1] = 5;
    circuit.gates[4].out = 6;

    bool truthTable[4][3] = {{false, false, false},
                             {false, true, true},
                             {true, false, true},
                             {true, true, false}};

    printf("Input A\tInput B\tOutput\n");
    for(int i = 0; i < 4; i++){
        bool values[MAX_NODES];
        values[0] = truthTable[i][0];
        values[1] = truthTable[i][1];
        printf("%d\t%d\t%d\n", values[0], values[1], eval(&circuit, values));
    }

    return 0;
}