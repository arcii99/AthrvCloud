//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: systematic
#include <stdio.h>
#include <string.h>
 
// function to calculate checksum
void calculateCheckSum(char *message)
{
    int i, checksum = 0, length;
 
    // calculate length of message
    length = strlen(message);
 
    // add ASCII value of each character in message to checksum
    for (i = 0; i < length; i++)
        checksum += (int)message[i];
 
    // print original message and checksum
    printf("\nOriginal Message: %s", message);
    printf("\nChecksum: %d", checksum);
}
 
int main()
{
    char message[100];
 
    // read message from user
    printf("Enter a message: ");
    fgets(message, 100, stdin);
 
    // remove newline character from message
    if (message[strlen(message)-1] == '\n')
        message[strlen(message)-1] = '\0';
 
    // calculate checksum
    calculateCheckSum(message);
 
    return 0;
}