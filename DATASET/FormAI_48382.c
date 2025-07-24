//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int checksum = 0;
    char message[100];
    
    printf("Enter message to calculate checksum: ");
    scanf("%s", message);
    
    for(int i=0; message[i] != '\0'; i++)
    {
        checksum += message[i];
    }
    
    printf("\nChecksum of the message is: %d", checksum);
    
    int result = checksum % 256;
    
    printf("\nResulting checksum after modulo 256 is: %d", result);
    
    return 0;
}