//FormAI DATASET v1.0 Category: QR code generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char **argv)
{
    if(argc < 2)
    {
        printf("Usage: cqrgen <text>\n");
        return 0;
    }

    char *text = argv[1];   // Get the text to encode from command line arguments

    QRcode *code = QRcode_encodeString(text, 0, QR_ECLEVEL_Q, QR_MODE_8, 1);   // Create the QR code

    if(code != NULL)
    {
        int size = code->width + 2;   // Add 2 to the width for the white border around the code

        char *output = (char*) malloc(size * size + size);   // Allocate space for the output string
        memset(output, ' ', size * size + size);
        output[size - 1] = '\n';

        int x, y;

        for(y = 0; y < code->width; ++y)   // Draw the QR code
        {
            output[(y + 1) * size] = ' ';  // Add space at the beginning of each line

            for(x = 0; x < code->width; ++x)
            {
                output[(y + 1) * size + x + 1] = code->data[y * code->width + x] ? '#' : ' ';
            }
        }

        printf("%s", output);

        free(output);
        QRcode_free(code);
    }
    else
    {
        printf("Invalid input text\n");
    }

    return 0;
}