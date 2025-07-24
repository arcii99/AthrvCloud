//FormAI DATASET v1.0 Category: Temperature monitor ; Style: mind-bending
#include <stdio.h>

int main(){
    float temperature;
    int alert_flag = 0;
    printf("Welcome to the Temperature Monitor\n");
    while(1){

        printf("\nEnter the current temperature in Celsius: ");
        scanf("%f",&temperature);

        if(temperature>30){
            printf("\nAlert!! The temperature is too high. It is %0.2f degrees Celsius.\n",temperature);
            alert_flag = 1;
        }
        else if(temperature<10){
            printf("\nAlert!! The temperature is too low. It is %0.2f degrees Celsius.\n",temperature);
            alert_flag = 1;
        }
        else{
            alert_flag = 0;
        }

        if(alert_flag){
            printf("Sending notification to the relevant authorities...\n");
        }
        else{
            printf("The temperature is okay.\n");
        }
    }
    return 0;
}