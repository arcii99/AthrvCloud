//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

float speedTest(){
    float random_time = 0;
    time_t start, end;
    
    // generate random amount of data to transfer
    int data_amount = (rand() % (1000 - 100 + 1)) + 100;
    
    // record the start time
    time(&start);
    
    // simulate data transfer
    for (int i=0; i<data_amount; i++){
        for (int j=0; j<100000; j++){
            int temp = i*j;
        }
    }
    
    // record the end time
    time(&end);
    
    // calculate the time elapsed during transfer
    random_time = difftime(end, start);
    
    // calculate transfer speed in Mbits/sec
    float data_size = data_amount/1000;
    float transfer_speed = (data_size/random_time)*8;
    
    return transfer_speed;
}

int main(){
    float avg_speed = 0;
    
    // run the speed test 5 times and calculate average speed
    for (int i=0; i<5; i++){
        avg_speed += speedTest();
    }
    avg_speed = avg_speed/5;
    
    printf("Your internet speed is: %.2f Mbits/sec\n", avg_speed);
    
    return 0;
}