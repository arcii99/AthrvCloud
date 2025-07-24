//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: paranoid
#include<stdio.h>
#include<stdlib.h> 

int calc_checksum(char *message, int length){
    int checksum = 0, i = 0;
    for(i=0; i<length; i++){
        checksum += message[i];
    }
    return checksum;
}

int main(){
    char message[20]; // Max 20 characters allowed
    int checksum = 0, length = 0;
    printf("Enter the message to calculate checksum: ");
    fgets(message, 20, stdin); // Take input from user
    length = strlen(message)-1; // Remove the newline character
    checksum = calc_checksum(message, length); // Call the function to calculate checksum
    printf("Checksum of the message is: %d\n",checksum);
    return 0;
}