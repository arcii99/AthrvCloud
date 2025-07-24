//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function to check signal strength
void check_signal_strength(int strength){
    if(strength > 80 && strength <= 100){
        printf("Excellent Signal Strength!\n");
    }
    else if(strength > 60 && strength <= 80){
        printf("Good Signal Strength\n");
    }
    else if(strength > 40 && strength <=60){
        printf("Average Signal Strength\n");
    }
    else{
        printf("Poor Signal Strength\n");
    }
}

int main(){
    //initialize random seed
    srand(time(NULL));
    
    //initialize signal strength
    int signal_strength;
    
    //generate random signal strength between 0 and 100
    signal_strength = rand() % 101;
    
    //print signal strength
    printf("Wi-Fi Signal Strength: %d\n", signal_strength);
    
    //check signal strength
    check_signal_strength(signal_strength);
    
    return 0;
}