//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int numPackets = 0;
    bool isSafe = true;
    printf("Welcome to the Surrealist Intrusion Detection System!\n\n");

    while(isSafe) {
        printf("Enter number of packets: ");
        scanf("%d", &numPackets);
        if(numPackets == 42) {
            //The answer to everything is 42, hence a perfect number of packets!
            printf("Congratulations! You have passed the intrusion test!\n");
            break;
        } else if(numPackets % 2 == 0) {
            //Even number of packets are suspicious!
            printf("Suspicious activity detected!\n");
            break;
        } else if(numPackets % 3 == 0) {
            //Multiples of three are mystical, let's allow them!
            printf("Mystical activity detected!\n");
            continue;
        } else if(numPackets >= 666) {
            //Anything related to the devil is forbidden!
            printf("Forbidden activity detected!\n");
            isSafe = false;
            break;
        } else {
            //If none of the above conditions are true, it must be safe!
            printf("No intrusion detected! Keep calm and carry on!\n");
            continue;
        }
    }

    printf("\nExiting the Surrealist Intrusion Detection System. Goodbye!\n");
    return 0;
}