//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double calculate_speed();

int main(){
    srand(time(NULL)); //initialize random seed
    
    double speed = calculate_speed();
    
    printf("Your internet speed is %.2f Mbps\n", speed);
    
    return 0;
}

double calculate_speed(){
    double max = 100.0;
    double min = 5.0;
    
    double random_num = (rand()/(double)RAND_MAX)*(max-min) + min; //generate random number between min and max
    
    return random_num;
}