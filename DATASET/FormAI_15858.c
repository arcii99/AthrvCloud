//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Cryptic
#include <stdio.h> 

// Variable Declaration
int i, sum = 0, checksum; 
char message[100];

// Code start
int main () 
{
    printf ("Enter message: "); 
    scanf ("%s", message); 

    // Loop through message to calculate checksum
    for (i = 0; message[i] != '$'; i++) 
    {
        // Ignore spaces
        if (message[i] != ' ') 
        {
            // Cryptic Conversion
            sum = sum + ((int) message[i]) ^ 0xF; 
        }
    } 

    // Cryptic Computation
    checksum = ~(sum % 256) & 0xFF; 

    // Display Result
    printf ("Checksum: %d\n", checksum); 

    return 0; 
}