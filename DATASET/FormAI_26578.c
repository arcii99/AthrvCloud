//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Donald Knuth
#include <stdio.h>

// function to calculate the 8-bit checksum
int checksum(char* message, int length) {
    int sum = 0;
    
    // loop through the message, adding the ASCII value of each character to the sum
    for (int i = 0; i < length; i++) {
        sum += (int)message[i];
    }
    
    // take the two's complement of the sum
    sum = ~sum + 1;
    
    // return the least significant 8 bits of the sum
    return sum & 0xFF; 
}

int main() {
    printf("Enter the message to calculate the checksum:\n");
    
    // read in the message from the user
    char message[100];
    fgets(message, 100, stdin);
    
    // calculate the checksum and print it out
    printf("The checksum is: %02X\n", checksum(message, strlen(message)));
    
    return 0;
}