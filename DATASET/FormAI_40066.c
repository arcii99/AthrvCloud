//FormAI DATASET v1.0 Category: QR code reader ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_QR_CODE_LENGTH 500

// function prototypes
bool isDigit(char ch);
void readQRCode(char qrCode[], int maxCodeLength);
int calculateSum(char qrCode[], int length);
bool validateQRCode(char qrCode[], int length);

// main function
int main()
{
    char qrCode[MAX_QR_CODE_LENGTH];
    int length = 0;
    
    printf("Enter the QR Code: ");
    readQRCode(qrCode, MAX_QR_CODE_LENGTH);
    length = strlen(qrCode);
    
    if(validateQRCode(qrCode, length))
    {
        int sum = calculateSum(qrCode, length);
        printf("QR Code is valid! The sum of digits is: %d", sum);
    }
    else
    {
        printf("Invalid QR Code!");
    }
    
    return 0;
}

// function to validate QR Code by checking length and contents
bool validateQRCode(char qrCode[], int length)
{
    if(length != 44)
    {
        return false;
    }
    
    for(int i=0; i<length; i++)
    {
        if(!isDigit(qrCode[i]) && qrCode[i] != ':')
        {
            return false;
        }
    }
    
    return true;
}

// function to calculate sum of digits in QR Code
int calculateSum(char qrCode[], int length)
{
    int sum = 0;
    for(int i=0; i<length; i++)
    {
        if(isDigit(qrCode[i]))
        {
            sum += qrCode[i] - '0';
        }
    }
    return sum;
}

// function to read QR Code input
void readQRCode(char qrCode[], int maxCodeLength)
{
    char ch = getchar();
    int index = 0;
    while(ch != '\n' && index < maxCodeLength)
    {
        qrCode[index++] = ch;
        ch = getchar();
    }
    qrCode[index] = '\0';
}

// function to check if a character is a digit
bool isDigit(char ch)
{
    return (ch >= '0' && ch <= '9');
}