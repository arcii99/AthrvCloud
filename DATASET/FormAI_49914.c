//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int cpuUsage = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    float delayTime = 0.05;

    srand(time(NULL));

    for(i = 0; i < 50; i++){
        cpuUsage = rand() % 101; //Random value between 0 to 100

        for(j = 0; j < cpuUsage; j++){
            for(k = 0; k < 1000000; k++){
                //CPU intensive operation
            }
        }

        if(i % 10 == 0){
            system("clear");
        }

        printf("CPU usage: %d%%\n", cpuUsage);

        //Delay program for a moment
        clock_t start_time = clock();
        while((float)(clock() - start_time)/CLOCKS_PER_SEC < delayTime);
    }

    return 0;
}