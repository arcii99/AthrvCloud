//FormAI DATASET v1.0 Category: Smart home automation ; Style: recursive
#include <stdio.h>

//Function to recursively turn on/off a light bulb
void lightBulb(int level, int isOn){
    if(level == 0){ //Base case: light bulb is at the lowest level
        printf("The light bulb is turned %s\n", (isOn == 1)? "on" : "off");
    }
    else{
        printf("You are on level %d\n", level);
        lightBulb(level-1, isOn); //Recursively go down one level
        printf("You are back on level %d\n", level);
        lightBulb(level-1, (isOn == 1)? 0 : 1); //Recursively go down one level and turn the light bulb on/off
    }
}

int main(){
    int levels;
    printf("How many levels does the light bulb have: ");
    scanf("%d", &levels);
    lightBulb(levels, 1); //Start at the highest level and turn the light bulb on
    return 0;
}