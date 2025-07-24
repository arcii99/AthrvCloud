//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int timeCount = 0;
    int red = 1, yellow = 0, green = 0;
    int curState = red;
    
    srand(time(NULL));
    int randSeconds = rand() % 5 + 1;
    
    while(1){
        int extraTime = 0;
        if(curState == red){
            if(timeCount >= 10){
                curState = green;
            }
            else if(timeCount >= 5){
                curState = yellow;
                extraTime = randSeconds;
            }
        }
        else if(curState == yellow){
            if(timeCount >= 2 + extraTime){
                curState = red;
                timeCount = 0;
            }
        }
        else if(curState == green){
            if(timeCount >= 15){
                curState = yellow;
                extraTime = randSeconds;
            }
        }
        
        // Output
        if(curState == red){
            printf("RED\n");
        }
        else if(curState == yellow){
            printf("YELLOW\n");
        }
        else{
            printf("GREEN\n");
        }
        
        // Wait for 1 second
        sleep(1);
        timeCount++;
    }
    
    return 0;
}