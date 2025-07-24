//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: secure
#include<stdio.h>
#include<string.h>

#define PASSWORD "p@ssw0rd123"

int main(){
    char entered_password[20];
    int authenticated = 0;
    
    printf("Enter password to access drone: ");
    scanf("%s", &entered_password);
    
    if(strcmp(entered_password, PASSWORD) == 0){
        authenticated = 1;
    }
    
    if(authenticated){
        printf("Access granted. You are now controlling the drone.\n");
        //Code to control the drone.
    }
    else{
        printf("Access denied. Incorrect password entered.\n");
    }
    
    return 0;
}