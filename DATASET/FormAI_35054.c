//FormAI DATASET v1.0 Category: Smart home light control ; Style: Sherlock Holmes
// The Adventure of the Smart Home Lighting Control

#include <stdio.h>
#include <stdlib.h>

int main() {
    int time;
    char light_status = 'off';
    
    printf("It was a dark and stormy night. Mr. Holmes enters his parlour.\n");
    printf("He observes that the electric light is hooked up to a smart home control system.\n");
    printf("Watson, the light is currently %s. Please tell me the time (in 24 hour format).\n", light_status);
    scanf("%d", &time);
    
    if (time >= 6 && time <= 18) {
        light_status = 'on';
        printf("The light is now %s. The system has detected it is daytime.\n", light_status);
    } else if (time > 18 && time < 22) {
        printf("The light is currently %s. The system has detected it is evening.\n", light_status);
    } else if (time >= 22 || time < 6) {
        light_status = 'on';
        printf("The light is now %s. The system has detected it is nighttime.\n", light_status);
    } else {
        printf("I'm sorry, Watson, that is not a valid time. Please try again.\n");
    }
    
    printf("As Mr. Holmes sits down to enjoy a good book, he recalls the recent burglary at 221B Baker Street.\n");
    printf("Watson, if an intruder were to enter our home, we could program the system to sound an alarm and flash the lights.\n");
    printf("Please enter 'Y' for yes or 'N' for no if you would like to set an intruder alert.\n");
    char alert_choice;
    scanf(" %c", &alert_choice);
    
    if (toupper(alert_choice) == 'Y') {
        printf("The system has been programmed. If an intruder were to enter, the alarm will sound and lights will flash.\n");
    } else if (toupper(alert_choice) == 'N') {
        printf("The system will not be programmed for an intruder alert.\n");
    } else {
        printf("I'm sorry, Watson, that is not a valid choice. Please try again.\n");
    }
    
    return 0;
}