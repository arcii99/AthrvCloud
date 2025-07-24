//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>

//defining traffic light state constants
#define RED 0
#define YELLOW 1
#define GREEN 2

//function declarations
void printState(int currentState);
int getNextState(int currentState);

int main(){
    
    int state = RED; //initial state is red
    
    while(1){ //continuously run the program until terminated
        
        printState(state);
        state = getNextState(state); //get next state based on current state
        
        //delay for 1 second
        for(int i=0;i<100000000;i++);
        
    }
    
    return 0;
}

//function to print current state
void printState(int currentState){
    
    switch(currentState){
        case RED:
            printf("RED LIGHT\n");
            break;
        case YELLOW:
            printf("YELLOW LIGHT\n");
            break;
        case GREEN:
            printf("GREEN LIGHT\n");
            break;
    }
}

//function to get next state based on current state
int getNextState(int currentState){
    
    int nextState;
    
    switch(currentState){
        case RED:
            nextState = GREEN;
            break;
        case YELLOW:
            nextState = RED;
            break;
        case GREEN:
            nextState = YELLOW;
            break;
    }
    
    return nextState;
}