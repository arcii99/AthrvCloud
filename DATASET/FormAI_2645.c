//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(0)); //using time as seed for random generator
    int signal = rand() % 3 + 1; //randomising initial signal
    printf("Signal: %d\n", signal);

    while(1){
        switch(signal){
            case 1:
                printf("Red signal, stop\n");
                sleep(5); //wait for 5 sec
                signal = 2; //change signal to yellow
                printf("Signal: %d\n",signal);
                break;
            case 2:
                printf("Yellow signal, get ready\n");
                sleep(3); //wait for 3 sec
                signal = 3; //change signal to green
                printf("Signal: %d\n",signal);
                break;
            case 3:
                printf("Green signal, go\n");
                sleep(10); //wait for 10 sec
                signal = 1; //change signal to red
                printf("Signal: %d\n",signal);
                break;
        }
    }
    return 0;
}