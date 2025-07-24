//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Alan Touring
#include <stdio.h>

int main() {
    int checksum = 0;
    char message[50];
    
    printf("Enter the message to calculate checksum: ");
    scanf("%s", message);
    
    for(int i = 0; message[i] != '\0'; i++) {
        checksum += message[i];
    }
    
    int remainder = checksum % 256;
    int checksum_value = 255 - remainder + 1;
    
    printf("Checksum value: %d", checksum_value);
    
    return 0;
}