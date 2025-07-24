//FormAI DATASET v1.0 Category: QR code reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_QR_CODE_SIZE 250

typedef struct qr_code {
    char content[MAX_QR_CODE_SIZE];
    size_t size;
} qr_code;

bool check_qr_code_size(qr_code *qr){
    if (qr->size > MAX_QR_CODE_SIZE){
        printf("QR code size exceeds limit of %d bytes", MAX_QR_CODE_SIZE);
        return false;
    }
    return true;
}

bool check_qr_code_format(qr_code *qr){
    if (strstr(qr->content, "http") == NULL){
        printf("QR code does not contain a valid URL");
        return false;
    }
    return true;
}

int main(int argc, char **argv){
    qr_code qr;
    memset(&qr, 0, sizeof(qr));

    printf("Place your QR code in front of the camera: ");
    fgets(qr.content, MAX_QR_CODE_SIZE, stdin);
    qr.size = strlen(qr.content);

    if (check_qr_code_size(&qr)){
        if (check_qr_code_format(&qr)){
            printf("QR code successfully read: %s", qr.content);
            // further processing of the QR code content
        }
        else {
            printf("QR code format is not valid\n");
            // handle invalid QR code format
        }
    }
    else {
        printf("QR code size is too big\n");
        // handle QR code exceeding size limit
    }

    return 0;
}