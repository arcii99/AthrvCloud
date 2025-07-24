//FormAI DATASET v1.0 Category: Firewall ; Style: Alan Touring
//Alan Turing Firewall : Accept only packets from whitelisted IPs
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_IPS 1000

int main(){
    char ips[MAX_IPS][16]={0}; //Array to store whitelisted IPs
    int i=0, flag=0;
    char choice='Y', iptemp[16]={0};
    
    printf("------------------------------------\n");
    printf("\t Alan Turing Firewall \n");
    printf("------------------------------------\n");
    printf("Enter IPs to whitelist : \n\n");
    
    while(choice=='Y'){  //Whitelist IPs
        fflush(stdin);   //Clear input buffer
        printf("IP %d : ", i+1);
        fgets(iptemp, 16, stdin);  //Store input IP
        iptemp[strlen(iptemp)-1]='\0'; //Remove new line character
        strcpy(ips[i], iptemp); //Copy IP into array
        i++;
        printf("Add more IPs ? (Y/N) : ");
        scanf(" %c", &choice); //Ask for more IPs
    }

    char input_ip[16]={0};
    printf("\n\nEnter IP to check : ");
    fflush(stdin);
    fgets(input_ip, 16, stdin); //Get User Input IP
    input_ip[strlen(input_ip)-1]='\0'; //Remove new line character
    
    for(int j=0;j<i;j++){  //Compare IPs
        if(strcmp(ips[j], input_ip)==0){ //If IP is whitelisted
            flag=1;
            break;
        }
    }
    
    if(flag==1)
        printf("\n\nPacket Accepted! \n");
    else
        printf("\n\nPacket Rejected! \n");
    
    printf("------------------------------------\n");
    printf("\t Firewall End \n");
    printf("------------------------------------\n");
    return 0;
}