//FormAI DATASET v1.0 Category: Smart home automation ; Style: funny
#include <stdio.h>
#include <stdbool.h>

int main(){
 
    printf("Welcome to the Smart Home Automation system – Where every button press is a chance to break something!\n");
    int temp = 70;
    bool doorLock = true;
    bool lightsOn = false;
    bool TVOn = false;
    
    printf("The temperature in the house is %d degrees.\n", temp);
    if(temp > 80){
        printf("Uh Oh! It's too hot in here. The air conditioning is coming on.\n");
        // turn on air conditioning code here
    }else{
        printf("Ah, nice temperature. No need to turn anything on.\n");
    }

    if(doorLock){
        printf("The front door is locked.\n");
    }else{
        printf("Someone left the front door unlocked! Quick, lock it up.\n");
        // lock front door code here
    }
    
    if(!lightsOn){
        printf("It's pretty dark in here. Let's turn on some lights.\n");
        // turn on lights code here
    }
    
    if(TVOn){
        printf("Why is the TV on? No one is watching it. We're wasting electricity. Turn it off.\n");
        // turn off TV code here
    }else{
        printf("Time to watch some Netflix. Let's turn on the TV.\n");
        // turn on TV code here
    }
    
    printf("Thanks for using the Smart Home Automation system. Don't worry, if anything breaks, we're not responsible. Have a great day!\n");
    
    return 0;
}