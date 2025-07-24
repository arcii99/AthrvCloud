//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: shocked
#include <stdio.h> 

int main() { 
    printf("Initializing traffic light controller...\n"); 
    int red = 1;
    int yellow = 0;
    int green = 0;

    while(1) { 
        printf("\nCurrent Status:"); 
        if(red == 1) { 
            printf("\nRED light ON"); 
            printf("\nYELLOW light OFF"); 
            printf("\nGREEN light OFF\n");
            // 60 seconds until green light is ON
            for(int i=60; i>0; i--) { 
                printf("\nTime left for GREEN: %d", i); 
                if(i == 1) { 
                    red = 0;
                    yellow = 1;
                    break;
                } 
                sleep(1); // wait for 1 second
            } 
        } 
        else if(yellow == 1) { 
            printf("\nRED light OFF"); 
            printf("\nYELLOW light ON"); 
            printf("\nGREEN light OFF\n");
            // 10 seconds until green light is OFF and red light is ON 
            for(int i=10; i>0; i--) { 
                printf("\nTime left for RED: %d", i);
                if(i == 1) { 
                    yellow = 0;
                    green = 1;
                    break;
                } 
                sleep(1); // wait for 1 second
            } 
        } 
        else { 
            printf("\nRED light OFF"); 
            printf("\nYELLOW light OFF"); 
            printf("\nGREEN light ON\n");
            // 60 seconds until yellow light is ON
            for(int i=60; i>0; i--) { 
                printf("\nTime left for YELLOW: %d", i); 
                if(i == 1) { 
                    green = 0;
                    red = 1;
                    break;
                } 
                sleep(1); // wait for 1 second
            } 
        } 
    } 

    return 0; 
}