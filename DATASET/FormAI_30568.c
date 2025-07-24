//FormAI DATASET v1.0 Category: QR code generator ; Style: protected
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<qrencode.h>

void printQRCode(FILE *file, int pixelSize, unsigned char *string) {
    QRcode *qrCode = QRcode_encodeString((char*)string, 0, QR_ECLEVEL_Q, QR_MODE_8, 1);
    if(qrCode) {
        int x, y, offset;
        for(y=0; y < qrCode->width; y++)
        {
            for(offset=0, x=0; x<qrCode->width; x++, offset+=pixelSize)
            {
                if(qrCode->data[y*qrCode->width+x] & 1) {
                    fseek(file, (y*pixelSize*qrCode->width)+(x*pixelSize)+offset, SEEK_SET);
                    fwrite("0", 1, 1, file);
                }
                else {
                    fseek(file, (y*pixelSize*qrCode->width)+(x*pixelSize)+offset, SEEK_SET);
                    fwrite("1", 1, 1, file);
                }
            }
            offset += pixelSize * (qrCode->width+1);
            fseek(file, offset, SEEK_SET);
        }
    }
    QRcode_free(qrCode);
}

int main() {

    char data[] = "https://github.com/iamsid47"; //Your data here
    FILE *file = fopen("myQRCode.txt", "w");
    if(file)
    {
        int pixelSize = 2; //Set pixel size as required
        unsigned char *string = (unsigned char *)data;
        printQRCode(file, pixelSize, string);
        printf("Generated QR Code is saved in myQRCode.txt\n");
        fclose(file);
    }
    else
    {
        printf("Oops! Something went wrong while saving the generated QR Code.");
    }

    return 0;
}