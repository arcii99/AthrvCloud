//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Romeo and Juliet
#include<stdio.h>

// Two lovely variables, alike in dignity
unsigned int sum = 0;
unsigned short checksum = 0;

int main() {
    // The program, fair and new written in C
    printf("O Romeo, sum thy integers here,\n");
    printf("And with thy sum calculate my checksum clear.\n");
    
    // A loop, to take the integers
    for(int i = 0; i < 5; i++) {
        int num;
        printf("Speak your number, fair and brave:\n");
        scanf("%d", &num);
        sum += num;
    }
    
    // A calculation, to determine the checksum's fate
    checksum = ~(sum & 0xFF) + 1;
    
    // Display the checksum, in fair and lovely form
    printf("Checksum: %d, fair and full of charm.\n", checksum);
    
    // Exit the program, with happy and light hearts
    printf("And so, we take our leave, dear friend.\n");
    printf("Our program runs without error or end.\n");
    return 0;
}