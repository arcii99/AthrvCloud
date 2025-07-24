//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int speed; //variable to store internet speed
    
    //generate random number between 1 to 100
    srand(time(NULL));
    speed = rand() % 100 + 1;
    
    //print internet speed
    printf("Your internet speed is: %d Mbps\n", speed);
    
    //check internet speed category
    if(speed < 10){
        printf("Your internet speed is very slow\n");
    }
    else if(speed >= 10 && speed < 50){
        printf("Your internet speed is moderate\n");
    }
    else if(speed >= 50 && speed < 100){
        printf("Your internet speed is fast\n");
    }
    else{
        printf("Your internet speed is very fast\n");
    }
    
    return 0;
}