//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct TrafficSignal{
    int signal_id;
    int duration;
    int next_green_signal_id;
};

void printSignalStatus(struct TrafficSignal ts[], int no_of_signals, int time_elapsed){
    printf("\nTime Elapsed: %d\n", time_elapsed);
    for(int i=0; i<no_of_signals; i++){
        if(time_elapsed % ts[i].duration < ts[i].duration/2){
            printf("\nSignal %d: Green", ts[i].signal_id);
        }else{
            printf("\nSignal %d: Red", ts[i].signal_id);
        }
    }
}

int main(){
    srand(time(NULL)); // Seed for random generation

    int no_of_signals = 4;
    struct TrafficSignal ts[4];
    ts[0].signal_id = 1;
    ts[0].duration = 30;
    ts[0].next_green_signal_id = 2;
    ts[1].signal_id = 2;
    ts[1].duration = 20;
    ts[1].next_green_signal_id = 3;
    ts[2].signal_id = 3;
    ts[2].duration = 40;
    ts[2].next_green_signal_id = 4;
    ts[3].signal_id = 4;
    ts[3].duration = 25;
    ts[3].next_green_signal_id = 1;

    int time_elapsed = 0;
    int total_simulation_time = 300;

    while(time_elapsed < total_simulation_time){
        printSignalStatus(ts, no_of_signals, time_elapsed);
        time_elapsed++;

        // Check if light has changed at any signal
        for(int i=0; i<no_of_signals; i++){
            if(time_elapsed % ts[i].duration == ts[i].duration/2){
                printf("\nSignal %d changed to RED", ts[i].signal_id);
                printf("\nSignal %d changed to GREEN\n", ts[i].next_green_signal_id);
            }
        }
        // Randomly add a delay of 1-5 seconds
        int delay = rand() % 5 + 1;
        time_elapsed += delay;

    }
    return 0;
}