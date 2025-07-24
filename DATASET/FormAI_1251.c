//FormAI DATASET v1.0 Category: Temperature monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    float curTemp = 0.0, targetTemp = 0.0;
    char name[20];
    
    printf("Enter your name:");
    scanf("%s", name);
    printf("\nHi %s, welcome to the Temperature Monitor Program!\n\n", name);
    sleep(2);
    
    printf("Please enter the target temperature in Celsius:");
    scanf("%f", &targetTemp);
    
    while(1){
        system("clear"); // clear screen on every loop iteration
        printf("Current Temperature: %.2f°C\n", curTemp);
        printf("Target Temperature: %.2f°C\n", targetTemp);
        
        if(curTemp < targetTemp - 2){
            printf("WARNING: The current temperature is too low!\n");
        }
        else if(curTemp > targetTemp + 2){
            printf("WARNING: The current temperature is too high!\n");
        }
        else{
            printf("The current temperature is within acceptable range.\n");
        }
        
        printf("\n");
        sleep(1); // wait for a second before checking temperature again
        
        // simulate temperature changes
        if(curTemp < targetTemp){
            curTemp += 0.5;
        }
        else if(curTemp > targetTemp){
            curTemp -= 0.5;
        }
    }
    
    return 0;
}