//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100 //Define the maximum input length of a message

void detect_intrusion(char *message);

int main(void) {
    char input[MAX_INPUT_LENGTH]; //to store user input message
    printf("Enter a message to check for intrusion: ");
    fgets(input, MAX_INPUT_LENGTH, stdin); //input the message
    detect_intrusion(input); //check message for intrusion
    return 0;
}

void detect_intrusion(char *message) {
    char *intrusion_keywords[] = {"password", "hack", "root", "admin"}; //an array of keywords that are commonly used in intrusion attempts
    int num_keywords = sizeof(intrusion_keywords) / sizeof(intrusion_keywords[0]); //get the size of the array
    for (int i = 0; i < num_keywords; i++) {
        if (strstr(message, intrusion_keywords[i]) != NULL) { //if keyword is found in message
            printf("Intrusion detected: Message contains keyword '%s'\n", intrusion_keywords[i]);
            exit(1); //exit program with error status
        }
    }
    printf("Message is safe.\n"); //if keyword is not found in message
}