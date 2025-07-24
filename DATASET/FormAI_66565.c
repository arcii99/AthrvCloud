//FormAI DATASET v1.0 Category: Digital signal processing ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//define the length of the input sequence
#define N 8

int main()
{
    //initialize the input sequence with random integer values between -128 and 127
    int x[N];
    for(int i=0; i<N; i++){
        x[i] = rand()%256-128;
        printf("%d ",x[i]);
    }
    printf("\n");

    //define the filter coefficients
    int b[3] = {1,2,1};
    int a[3] = {1,-1,0};

    //initialize the buffer registers
    int x_reg[3] = {0};
    int y_reg[3] = {0};

    //perform the digital filtering
    for(int n=0; n<N; n++){
        //shift the register values
        x_reg[2] = x_reg[1];
        x_reg[1] = x_reg[0];
        x_reg[0] = x[n];

        y_reg[2] = y_reg[1];
        y_reg[1] = y_reg[0];

        //calculate the new output value
        y_reg[0] = b[0]*x_reg[0] + b[1]*x_reg[1] +b[2]*x_reg[2]
                 - a[1]*y_reg[1] - a[2]*y_reg[2];

        //print the output value
        printf("%d ",y_reg[0]);
    }
    printf("\n");

    return 0;
}