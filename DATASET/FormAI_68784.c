//FormAI DATASET v1.0 Category: Smart home light control ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

//function to turn on the lights
void turnOnLights(){
    printf("The light is now alight!\n");
}

//function to turn off the lights
void turnOffLights(){
    printf("The light is now dark!\n");
}

int main(){

    int hourOfDay;

    printf("Greetings! Welcome to the medieval smart home system!\n");
    printf("Please enter the hour of the day in 24-hour format (0-23): ");
    scanf("%d", &hourOfDay);

    if(hourOfDay >= 0 && hourOfDay < 6){
        turnOffLights();
    }else if(hourOfDay >= 6 && hourOfDay < 12){
        turnOnLights();
    }else if(hourOfDay >= 12 && hourOfDay < 18){
        turnOnLights();
    }else{
        turnOffLights();
    }

    printf("Thank you for using the medieval smart home system!\n");

    return 0;
}