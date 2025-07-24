//FormAI DATASET v1.0 Category: QR code generator ; Style: retro
#include <stdio.h>

// function to convert decimal value to binary
void decimalToBinary(int decimal, int binary[])
{
    int index = 0;
    while (decimal > 0)
    {
        binary[index] = decimal % 2;
        decimal /= 2;
        index++;
    }
}

// function to generate QR code
void generateQRCode(char message[])
{
    // set QR code version as 1
    int version = 1;

    // calculate length of the message
    int length = 0;
    while (message[length] != '\0')
    {
        length++;
    }

    // calculate the number of modules required for the message and version
    int modules = 21 + (4 * version);

    // create a 2D array to store the QR code
    int qrCode[modules][modules];

    // initialize the qrCode array to -1
    for (int i = 0; i < modules; i++)
    {
        for (int j = 0; j < modules; j++)
        {
            qrCode[i][j] = -1;
        }
    }

    // add finder pattern to QR code
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            qrCode[i][j] = 0;
            qrCode[i][modules - 1 - j] = 0;
            qrCode[modules - 1 - i][j] = 0;
        }
    }

    // add separators to QR code
    for (int i = 0; i < modules; i++)
    {
        qrCode[i][7] = 0;
        qrCode[7][i] = 0;
        qrCode[i][modules - 8] = 0;
        qrCode[modules - 8][i] = 0;
    }

    // add alignment pattern to QR code
    if (version > 1)
    {
        int alignmentPattern[5] = {6, 18, 0, 0, 0};
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                qrCode[alignmentPattern[i]][alignmentPattern[j]] = 0;
                qrCode[modules - 1 - alignmentPattern[i]][alignmentPattern[j]] = 0;
                qrCode[alignmentPattern[i]][modules - 1 - alignmentPattern[j]] = 0;
            }
        }
    }

    // add timing pattern to QR code
    for (int i = 8; i < modules - 8; i++)
    {
        if (i % 2 == 0)
        {
            qrCode[i][6] = 0;
            qrCode[6][i] = 0;
        }
        else
        {
            qrCode[i][6] = 1;
            qrCode[6][i] = 1;
        }
    }

    // add version information to QR code
    if (version > 6)
    {
        int binary[6];
        decimalToBinary(version, binary);
        int index = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                qrCode[(modules - 11) - j][i] = binary[index];
                index++;
            }
        }
        index = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                qrCode[i][(modules - 11) - j] = binary[index];
                index++;
            }
        }
    }

    // add data to QR code
    int rowIndex = modules - 9;
    int colIndex = modules - 9;
    int direction = 0;
    int binaryLength = 0;
    int binaryData[3000];
    // convert message to binary
    for (int i = 0; i < length; i++)
    {
        int charDecimal = (int)message[i];
        decimalToBinary(charDecimal, &binaryData[binaryLength]);
        binaryLength += 8;
    }
    // add terminator (0000)
    binaryData[binaryLength] = 0;
    binaryData[binaryLength+1] = 0;
    binaryData[binaryLength+2] = 0;
    binaryData[binaryLength+3] = 0;
    binaryLength += 4;
    // add padding
    while (binaryLength % 8 != 0)
    {
        binaryData[binaryLength] = 0;
        binaryLength++;
    }
    // add length indicator
    int lengthBinary[16];
    decimalToBinary(length, lengthBinary);
    for (int i = 0; i < 9; i++)
    {
        qrCode[rowIndex][colIndex] = lengthBinary[i];
        if (direction == 0)
        {
            colIndex--;
            if (colIndex == 7)
            {
                rowIndex--;
                colIndex++;
                direction = 1;
            }
        }
        else
        {
            colIndex++;
            if (colIndex == modules - 8)
            {
                rowIndex--;
                colIndex--;
                direction = 0;
            }
        }
    }
    // add binary data to QR code
    for (int i = 0; i < binaryLength; i++)
    {
        qrCode[rowIndex][colIndex] = binaryData[i];
        if (direction == 0)
        {
            colIndex--;
            if (colIndex == 7)
            {
                rowIndex--;
                colIndex++;
                direction = 1;
            }
        }
        else
        {
            colIndex++;
            if (colIndex == modules - 8)
            {
                rowIndex--;
                colIndex--;
                direction = 0;
            }
        }
    }

    // print QR code
    for (int i = 0; i < modules; i++)
    {
        for (int j = 0; j < modules; j++)
        {
            if (qrCode[i][j] == 0)
            {
                printf("█");
            }
            else if (qrCode[i][j] == 1)
            {
                printf("░");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main()
{
    char message[100];
    printf("Enter message: ");
    fgets(message, 100, stdin);
    generateQRCode(message);
    return 0;
}