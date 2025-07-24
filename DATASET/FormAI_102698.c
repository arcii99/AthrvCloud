//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: multivariable
#include<stdio.h>    
#include<stdlib.h>    
#include<string.h>    
#include<math.h>    
    
// Function to encrypt a given string using Hill Cipher    
void hillCipherEncryption(char* message, int keyMatrix[][3], int messageVector[][1])    
{    
    int i, j, k;    
    
    int keyVector[3][1];    
    
    // Generate key vector    
    for (i = 0; i < 3; i++)    
        for (j = 0; j < 1; j++)    
            keyVector[i][j] = 0;    
    
    for (i = 0; i < 3; i++)    
        for (j = 0; j < 1; j++)    
            for (k = 0; k < 3; k++)    
                keyVector[i][j] += keyMatrix[i][k] * messageVector[k][j];    
    
    // Print encrypted message vector    
    printf("\nEncrypted Message Vector using Hill Cipher:\n");    
    for (i = 0; i < 3; i++)    
        printf("%c", (char)(keyVector[i][0] % 26 + 97));    
}    
    
// Driver code    
int main()    
{    
    int keyMatrix[3][3] = {{17, 17, 5}, {21, 18, 21}, {2, 2, 19}};    
    char message[] = "topsecret";    
    
    int messageVector[3][1];    
    
    // Generate message vector    
    for (int i = 0; i < 3; i++)    
        messageVector[i][0] = message[i] - 97;    
    
    // Encrypt message using Hill Cipher    
    hillCipherEncryption(message, keyMatrix, messageVector);    
    
    return 0;    
}