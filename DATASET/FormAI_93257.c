//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double internet_speed_test(){
    double speed = 0;
    time_t start, end;
    time(&start); //start timer
    
    //download a file
    system("curl -o /dev/null http://speedtest.wdc01.softlayer.com/downloads/test500.zip");
    
    //end timer
    time(&end);
    
    double time_taken = difftime(end, start);
    speed = 500/time_taken; //calculating speed in MB/s
    return speed;
}

int main(){
    double speed = internet_speed_test();
    printf("Your Internet Speed is: %.2lf MB/s", speed);
    return 0;
}