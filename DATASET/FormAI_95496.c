//FormAI DATASET v1.0 Category: Digital signal processing ; Style: protected
#include<stdio.h>

#define N 50

int main(){

    int input_signal[N], output_signal[N];
    int signal_sum = 0;

    for(int i = 0; i < N; i++){
        scanf("%d", &input_signal[i]);
    }

    //Moving average filter
    for(int i = 0; i < N; i++){
        if(i < 4){
            output_signal[i] = 0;
            continue;
        }
        signal_sum = input_signal[i] + input_signal[i-1] + input_signal[i-2] + input_signal[i-3] + input_signal[i-4];
        output_signal[i] = signal_sum/5;
    }

    //Printing the output signal
    printf("The output signal is: \n");
    for(int i = 0; i < N; i++){
        printf("%d\n", output_signal[i]);
    }
    
    return 0;
}