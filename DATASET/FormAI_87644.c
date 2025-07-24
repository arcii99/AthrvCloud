//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: shape shifting
#include<stdio.h> 
#include<string.h> 

int main() 
{ 
    int watermark = 0x55; // binary: 01010101
    char message[100], new_message[100], c;
    int i, j, len;

    printf("Enter the message you want to embed the watermark into: "); 
    fgets(message, 100, stdin); // taking input message

    len = strlen(message);

    for(i=0; i<len; i++)
    {
        c = message[i];

        for(j=0; j<8; j++) // iterating through the bits of character
        {
            if(c & (1<<j)) // if bit is 1
            {
                new_message[i*8 + j] = watermark | (1<<j); // set the corresponding bit of watermark as 1
            } 
            else // if bit is 0
            {
                new_message[i*8 + j] = watermark & ~(1<<j); // set the corresponding bit of watermark as 0
            }
        }
    }

    printf("\nThe new message with the watermark is:\n");
    for(i=0; i<len*8; i++) // printing the new message
    {
        printf("%c", new_message[i]);
    }

    printf("\n\n");

    return 0; 
}