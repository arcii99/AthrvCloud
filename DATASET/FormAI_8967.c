//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: realistic
#include<stdio.h>
#include<math.h>

#define R1 1000  //Value of resistor 1
#define R2 2200  //Value of resistor 2
#define C1 0.00022  //Value of capacitor

void simulate_circuit(double v_in[], double v_out[], int len);

int main(){
    //Input waveform (5V peak-to-peak)
    double v_in[] = {0, 2.5, 5, 2.5, 0, -2.5, -5, -2.5, 0, 2.5, 5};
    int len = sizeof(v_in)/sizeof(v_in[0]);
    
    //Output waveform (initially zero)
    double v_out[len];
    for(int i=0; i<len; i++){
        v_out[i] = 0;
    }
    
    //Simulate circuit
    simulate_circuit(v_in, v_out, len);
    
    //Print output waveform
    printf("Output waveform:\n");
    for(int i=0; i<len; i++){
        printf("%f\n", v_out[i]);
    }
    
    return 0;
}

void simulate_circuit(double v_in[], double v_out[], int len){
    double dt = 0.0001;  //Time step
    double rc = R1*C1;
    double alpha = dt/(rc+dt);
    
    for(int i=1; i<len; i++){
        v_out[i] = alpha*v_in[i] + (1-alpha)*v_out[i-1];
    }
}