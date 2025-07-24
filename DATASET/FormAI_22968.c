//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: energetic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Function to check for malicious activities in the network traffic
void checkForIntrusion(char *packet){
    char *keywords[] = {"hack", "attack", "virus", "malware"}; //array of malicious keywords
    int i, j;
    for(i = 0; i < strlen(packet); i++){
        for(j = 0; j < sizeof(keywords)/sizeof(char *); j++){
            if(strstr(packet+i, keywords[j])){ //if keyword found in packet
                printf("MALICIOUS ACTIVITY DETECTED!\n");
                return;
            }
        }
    }
    printf("No malicious activity detected.\n");
}

//Function to randomly generate network traffic packets
char* generatePacket(){
    char *packet = (char*) malloc(sizeof(char)*255);
    int len = rand()%50+10; //random packet length between 10 and 60
    int i;
    for(i = 0; i < len; i++){
        packet[i] = rand()%26+65; //random uppercase letter
    }
    packet[len] = '\0';
    return packet;
}

int main(){
    int i;
    char *packets[10]; //array of 10 packets
    for(i = 0; i < 10; i++){
        packets[i] = generatePacket(); //generating random packets
    }
    for(i = 0; i < 10; i++){
        printf("Packet %d: %s\n", i+1, packets[i]);
        checkForIntrusion(packets[i]); //checking for intrusion in each packet
    }
    return 0;
}