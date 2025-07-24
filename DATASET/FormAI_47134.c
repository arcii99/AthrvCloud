//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: interoperable
#include<stdio.h>
#define MAX_EVENTS 10
#define MAX_NAME_LENGTH 20

void alert(char* componentName, char* message);

int main(){
    int eventCount = 0;
    char eventName[MAX_EVENTS][MAX_NAME_LENGTH];
    printf("Enter the name of the event: ");
    fgets(eventName[eventCount++], MAX_NAME_LENGTH, stdin);
    while(eventCount < MAX_EVENTS){
        printf("Enter the name of the next event(enter 'exit' to quit): ");
        fgets(eventName[eventCount], MAX_NAME_LENGTH, stdin);
        if(eventName[eventCount++] == "exit"){
            break;
        }
    }
    return 0;
}

void alert(char* componentName, char* message){
    printf("Alert! %s: %s\n", componentName, message);
    //Code to send alert to the security team can be added here
}