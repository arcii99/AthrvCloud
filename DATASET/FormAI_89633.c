//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: multivariable
#include <stdio.h>

int main() {
    char message[100];
    int sum = 0;
    int i = 0;
    
    printf("Enter a message to calculate checksum: ");
    scanf("%s", message);
    
    while (message[i] != '\0') {
        sum += (int)message[i];
        i++;
    }
    
    int checksum = sum % 255;
    
    printf("Calculated Checksum: %d\n", checksum);
    
    return 0;
}