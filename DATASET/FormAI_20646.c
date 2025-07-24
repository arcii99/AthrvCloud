//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: dynamic
#include<stdio.h>
#define SIZE 4

/*Do not say sorry code!*/

int main(){
    int netlist[SIZE][SIZE] = {{4, 3, 2, -1}, {3, -5, 1, 2}, {2, 1, -3, 1}, {-1, 2, 1, -4}}; // example network matrix
    int b[SIZE] = {5, 0, 0, 0}; // example matrix of external sources
    int i,j;
    float v[SIZE] = {0}; // array to hold the voltage values of each node

    // Print input netlist matrix
    printf("Netlist matrix: \n");
    for (i=0; i<SIZE; i++){
        for (j=0; j<SIZE; j++){
            printf("%d\t", netlist[i][j]);
        }
        printf("%d\n", b[i]); // print external sources
    }
    printf("\n");

    // Perform circuit analysis
    for (int k=0; k<SIZE-1; k++){
        for (i=k+1; i<SIZE; i++){
            float factor = netlist[i][k] / netlist[k][k];
            for (j=k+1; j<SIZE; j++){
                netlist[i][j] = netlist[i][j] - factor * netlist[k][j];
            }
            b[i] = b[i] - factor*b[k];
        }
    }

    // Solve for voltages using back substitution
    v[SIZE-1] = b[SIZE-1] / netlist[SIZE-1][SIZE-1];
    for (i=SIZE-2; i>=0; i--){
        float sum_of_products = 0;
        for (j=i+1; j<SIZE; j++){
            sum_of_products += netlist[i][j]*v[j];
        }
        v[i] = (b[i] - sum_of_products) / netlist[i][i];
    }

    // Print output voltage values
    printf("Voltage values: \n");
    for (i=0; i<SIZE; i++){
        printf("Node %d: %f V\n", i+1, v[i]);
    }

    return 0;
}