//FormAI DATASET v1.0 Category: QR code generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

#define QR_CODE_SIZE_MAX 4096

void generate_qr_code(char *data, int data_len, int border_size, char *file_name) {
    QRcode *code = QRcode_encodeString(data, 0, QR_ECLEVEL_Q, QR_MODE_8, 1);
    if (code == NULL) {
        printf("Error generating QR Code!\n");
        return;
    }

    unsigned char *buffer = (unsigned char *) malloc(QR_CODE_SIZE_MAX * sizeof(unsigned char));
    memset(buffer, 0, QR_CODE_SIZE_MAX);

    for (int i = 0; i < code->width; i++) {
        for (int j = 0; j < code->width; j++) {
            int position = (i * code->width + j) * 3;
            buffer[position] = code->data[i * code->width + j] ? 0 : 255;
            buffer[position+1] = buffer[position];
            buffer[position+2] = buffer[position];
        }
    }

    QRcode_free(code);

    FILE *fptr = fopen(file_name, "wb");
    if (fptr == NULL) {
        printf("Cannot create file!\n");
        return;
    }

    fprintf(fptr, "P6\n%d %d\n255\n", code->width + border_size*2, code->width + border_size*2);

    for (int i = 0; i < border_size; i++) {
        fwrite(buffer, sizeof(unsigned char), 3*(code->width + border_size*2), fptr);
    }

    for (int i = 0; i < code->width; i++) {
        fwrite(buffer+i*3, sizeof(unsigned char), 3*border_size, fptr);
        fwrite(buffer+i*3 + code->width*3, sizeof(unsigned char), 3*border_size, fptr);
        fwrite(buffer+i*3 + code->width*3*2 + border_size*3, sizeof(unsigned char), 3*border_size, fptr);
        fwrite(buffer+i*3 + code->width*3*i + border_size*3, sizeof(unsigned char), 3*code->width, fptr);
    }

    for (int i = 0; i < border_size; i++) {
        fwrite(buffer + (code->width*3)*(code->width + border_size*2) + i*3, sizeof(unsigned char), 3*(code->width + border_size*2), fptr);
    }

    fclose(fptr);
    free(buffer);
}

int main() {
    char *data = "https://www.example.com";
    char *file_name = "example.png";
    int border_size = 10;

    generate_qr_code(data, strlen(data), border_size, file_name);

    return 0;
}