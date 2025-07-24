//FormAI DATASET v1.0 Category: QR code generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "qrencode.h"

int main(int argc, char ** argv) {
    if(argc < 2) {
        printf("%s <string>\n", argv[0]);
        return 0;
    }

    QRcode * code = QRcode_encodeString(argv[1], 0,
                        QR_ECLEVEL_M, QR_MODE_8, 1);

    if(code == NULL) {
        fprintf(stderr, "QRcode encoding failed.\n");
        return 1;
    }

    int width = code->width;
    int height = code->width;

    unsigned char * data = (unsigned char *) code->data;

    printf("QR Code for %s\n", argv[1]);

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(data[i*width+j]&1) printf("#");
            else printf(" ");
        }
        printf("\n");
    }

    QRcode_free(code);

    return 0;
}