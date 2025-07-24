//FormAI DATASET v1.0 Category: QR code generator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <content> <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* generate the QR code */
    QRcode *code = QRcode_encodeString(argv[1], 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if (!code)
    {
        printf("Failed to generate QR code\n");
        return EXIT_FAILURE;
    }

    /* open the output file */
    FILE *fp = fopen(argv[2], "wb");
    if (!fp)
    {
        printf("Failed to open output file \"%s\"\n", argv[2]);
        QRcode_free(code);
        return EXIT_FAILURE;
    }

    /* write the QR code to the output file */
    fwrite(code->data, sizeof(char), code->width * code->width * 3, fp);

    /* clean up */
    fclose(fp);
    QRcode_free(code);

    printf("QR code saved to \"%s\"\n", argv[2]);

    return EXIT_SUCCESS;
}