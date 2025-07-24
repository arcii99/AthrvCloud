//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

int main(){
    int check = 1, choice, qos_value;
    time_t now;
    struct tm *current_time;

    while(check){
        printf("\nNetwork Quality of Service (QoS) monitor\n");
        printf("1. Check QoS value\n");
        printf("2. Refresh QoS value\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                printf("Current QoS value: %d\n", qos_value);
                now = time(NULL);
                current_time = localtime(&now);
                printf("Checked at %d:%d:%d\n", current_time->tm_hour, 
                       current_time->tm_min, current_time->tm_sec);
                break;
            case 2:
                printf("Refreshing QoS value...\n");
                sleep(3);
                qos_value = rand() % 101; // randomly generate QoS value
                printf("New QoS value: %d\n", qos_value);
                now = time(NULL);
                current_time = localtime(&now);
                printf("Updated at %d:%d:%d\n", current_time->tm_hour, 
                       current_time->tm_min, current_time->tm_sec);
                break;
            case 0:
                printf("Exiting program...\n");
                check = 0;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}