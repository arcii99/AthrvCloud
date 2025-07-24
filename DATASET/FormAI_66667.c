//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a given string contains a suspicious keyword
int contains_keyword(char *str){
    char keywords[5][10] = {"hack", "attack", "steal", "virus", "malware"};
    int i;
    for(i=0; i<5; i++){
        if(strstr(str, keywords[i])){
            return 1;
        }
    }
    return 0;
}

// Function to log suspicious activity
void log_activity(char *activity){
    FILE *fptr;
    fptr = fopen("intrusion_log.txt", "a");
    if(fptr == NULL){
        printf("Error: Could not open log file.\n");
        return;
    }
    fprintf(fptr, "%s\n", activity);
    fclose(fptr);
}

int main(){

    // Simulation of incoming network traffic
    printf("Incoming network traffic:\n\n");
    char packet1[50] = "Some normal data";
    char packet2[50] = "This packet contains the word hack";
    char packet3[50] = "Some more normal data";
    char packet4[50] = "This packet contains the word steal";

    // Check each packet for suspicious keywords
    if(contains_keyword(packet1)){
        log_activity("Suspicious network activity detected: packet1");
    }
    if(contains_keyword(packet2)){
        log_activity("Suspicious network activity detected: packet2");
    }
    if(contains_keyword(packet3)){
        log_activity("Suspicious network activity detected: packet3");
    }
    if(contains_keyword(packet4)){
        log_activity("Suspicious network activity detected: packet4");
    }

    // Check log file for recent suspicious activity
    printf("\nChecking log file for recent suspicious activity:\n\n");
    char str[100];
    FILE *fptr;
    fptr = fopen("intrusion_log.txt", "r");
    if(fptr == NULL){
        printf("Error: Could not open log file.\n");
        return 0;
    }
    while(fgets(str, 100, fptr) != NULL){
        printf("%s", str);
    }
    fclose(fptr);

    // End of program
    return 0;
}