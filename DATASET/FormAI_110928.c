//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: irregular
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    char command[50];
    char system_area[1000]= "Safe";

    printf("Please enter a command: ");
    fgets(command, sizeof(command), stdin);

    if(strncmp(command, "sudo", 4) == 0){
        if(strstr(command, "rm -rf /") != NULL){
            printf("Intrusion detected! Removing all files. \n");
            strcpy(system_area, "Intrusion detected");
            system("sudo rm -rf /");
        }
        else if(strstr(command, "cat /etc/passwd") != NULL){
            printf("Intrusion detected! Attempted to view password file. \n");
            strcpy(system_area, "Intrusion detected");
        }
        else{
            printf("Permission granted. \n");
        }
    }
    else{
        printf("Invalid command. \n");
    }

    printf("System status: %s \n", system_area);
    return 0;
}