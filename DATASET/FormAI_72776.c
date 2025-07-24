//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: beginner-friendly
#include<stdio.h>
#include<string.h>

int main()
{
    char message[100];
    printf("Enter the message: ");
    gets(message); // Read the input message

    int sum = 0;
    int len = strlen(message);

    for(int i = 0; i < len; i++)
    {
        sum += (int) message[i]; // Cast the character to int and add to sum
    }

    int checksum = sum % 256; // Calculate the checksum

    printf("Checksum of message is %d\n", checksum);

    return 0;
}