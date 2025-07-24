//FormAI DATASET v1.0 Category: Firewall ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALLOWED_IP "192.168.1.1"    // change this to the IP you want to allow 

int main()
{
    char* allowed_ip = ALLOWED_IP;
    char* input_ip = (char*)malloc(sizeof(char) * 16);   // assuming maximum length of input IP address is 15
    
    printf("Enter IP address to access network: ");
    scanf("%s", input_ip);
    
    if(strcmp(input_ip, allowed_ip) == 0) {
        printf("Access Granted! Welcome to the network.");
    }
    else {
        printf("Access Denied! Your IP address is not authorized to access this network.");
    }
    
    free(input_ip);
    return 0;
}