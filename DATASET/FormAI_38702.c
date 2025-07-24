//FormAI DATASET v1.0 Category: QR code reader ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void printQRCode(char arr[][64], int numRows, int numCols)
{
    for(int i=0;i<numRows;i++)
    {
        for(int j=0;j<numCols;j++)
            printf("%c", arr[i][j]);
        printf("\n");
    }
}

int isQRCode(char arr[][64], int numRows, int numCols)
{
    // Check if corners are black
    int topLeft = arr[0][0], topRight = arr[0][numCols-1], bottomLeft = arr[numRows-1][0], bottomRight = arr[numRows-1][numCols-1];
    if(topLeft != '1' || topRight != '1' || bottomLeft != '1' || bottomRight != '1')
        return 0;

    // Check format information
    int format[15][15] = {0};
    for(int i=numRows-1;i>=numRows-7;i--)
        for(int j=8;j<15;j++)
            format[numRows-1-i][j-8] = (arr[i][j] == '1') ? 1:0;
    for(int i=numRows-8;i<numRows;i++)
        for(int j=numCols-8;j<numCols;j++)
            format[i-numRows+8][j-numCols+8] = (arr[i][j] == '1') ? 1:0;

    // Verify format information
    int xorRow1 = 0,xorCol1 = 0, xorRow2 = 0, xorCol2 = 0;
    for(int i=0;i<6;i++)
        xorRow1 += format[0][i] * pow(2,i);
    for(int i=0;i<6;i++)
        xorCol1 += format[i][8] * pow(2,i);

    if(xorRow1 != 18 || xorCol1 != 7) return 0;

    for(int i=0;i<6;i++)
        xorCol2 += format[8][i] * pow(2,i);
    for(int i=0;i<6;i++)
        xorRow2 += format[6][i] * pow(2,i);

    if(xorCol2 != 7 || xorRow2 != 5) return 0;

    // Print format information
    printf("Format Information: ");
    for(int i=0;i<15;i++)
        printf("%d", format[0][i]);
    for(int i=0;i<15;i++)
        printf("%d", format[i][8]);
}

int main()
{
    char qrcode1[29][64] = {
        "111111111111100001000100111111111111",
        "111111111111100001011100111111111111",
        "111111111111100001011100111111111111",
        "111111111111100001011100111111111111",
        "111111111111100001100100111111111111",
        "111111111111100001101100111111111111",
        "111111111111100001101100111111111111",
        "111111111111100001110100111111111111",
        "111111111111100011000100111111111111",
        "111111111111100011011100111111111111",
        "111111111111100011011100111111111111",
        "111111111111100011100100111111111111",
        "111111111111100011101100111111111111",
        "111111111111100011101100111111111111",
        "111111111111100011110100111111111111",
        "111111111111100111000100111111111111",
        "111111111111100111011100111111111111",
        "111111111111100111011100111111111111",
        "111111111111100111100100111111111111",
        "111111111111100111101100111111111111",
        "111111111111100111101100111111111111",
        "111111111111100111110100111111111111",
        "111111111111110001000100111111111111",
        "111111111111110001011100111111111111",
        "111111111111110001011100111111111111",
        "111111111111110001100100111111111111",
        "111111111111110001101100111111111111",
        "111111111111110001101100111111111111"
    };

    printQRCode(qrcode1, 29, 64);
    isQRCode(qrcode1, 29, 64);

    return 0;
}