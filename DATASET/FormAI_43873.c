//FormAI DATASET v1.0 Category: Smart home light control ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void turnOnLight(int lightNum){
    printf("Light %d turned on.\n", lightNum);
}

void turnOffLight(int lightNum){
    printf("Light %d turned off.\n", lightNum);
}

int main(){
    printf("Welcome to Smart Home Light Control System\n\n");
    while(1){
        int choice = -1;
        printf("Enter the light number to turn ON or OFF. Enter -1 to exit: ");
        scanf("%d", &choice);
        if(choice == -1){
            printf("Exiting from Smart Home Light Control System\n");
            break;
        }else if(choice < 1 || choice > 10){
            printf("Error! Invalid light number.\n");
            continue;
        }
        int status = -1;
        printf("Enter 0 to turn OFF or 1 to turn ON: ");
        scanf("%d", &status);
        if(status == 0){
            turnOffLight(choice);
        }else if(status == 1){
            turnOnLight(choice);
            // Additional code to send update to central server
            // and notify other connected devices about the status
        }else{
            printf("Error! Invalid choice.\n");
        }
        printf("\n");
    }
    return 0;
}