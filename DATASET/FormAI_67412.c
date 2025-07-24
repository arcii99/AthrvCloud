//FormAI DATASET v1.0 Category: Smart home light control ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

/* Smart home light control program */

int main(void)
{
    int light_on = 0;
    int hour, minute;

    printf("Welcome to Smart Home Light Control\n");

    while(1){
        printf("Enter time in 24-hour format (HH:MM): ");
        scanf("%d:%d", &hour, &minute);

        if(hour >= 0 && hour < 24 && minute >= 0 && minute < 60){
            if(hour >= 18 || hour < 6){
                if(!light_on){
                    printf("Turning on lights\n");
                    light_on = 1;
                } else {
                    printf("Lights already turned on\n");
                }
            } else {
                if(light_on){
                    printf("Turning off lights\n");
                    light_on = 0;
                } else {
                    printf("Lights already turned off\n");
                }
            }
        } else {
            printf("Invalid time entered. Please try again.\n");
        }
    }

    return 0;
}