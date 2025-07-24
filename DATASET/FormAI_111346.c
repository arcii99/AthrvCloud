//FormAI DATASET v1.0 Category: QR code generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <qrencode.h>

#define MAX_THREAD 10

// Data Structure for QrCode generation
struct qrdatastruct {
    char* data;
    int size;
    int margin;
    int version;
    QRecLevel level;
    int hint;
    unsigned char *output;
};

// Thread Structure
typedef struct threadstruct {
    pthread_t threadID;
    int threadnum;
    struct qrdatastruct qrdatal;
}Thread;

// Function Declaration
void* qrCodeGenerator(void *ptr);

int main() {

    char* message = "Sample QR Code"; // Sample Message for QR Code

    QRecLevel qreclevel = QR_ECLEVEL_L; // Error Correction Level

    int hint = QR_MODE_8; // QR Code Mode

    Thread th[MAX_THREAD]; // Thread Structure
    struct qrdatastruct qrdata[MAX_THREAD]; // QrCode Struct for each Thread

    // Passing Data to Each Thread
    for(int i = 0; i < MAX_THREAD; i++) {

        qrdata[i].data = message;
        qrdata[i].size = strlen(message);
        qrdata[i].margin = 4;
        qrdata[i].version = 0;
        qrdata[i].level = qreclevel;
        qrdata[i].hint = hint;
        qrdata[i].output = (unsigned char*)malloc(sizeof(char) * 100);

        th[i].threadnum = i;
        th[i].qrdatal = qrdata[i];

        pthread_create(&th[i].threadID, NULL, qrCodeGenerator, (void*)&th[i]);
    }

    // Wait for Threads to Finish
    for(int i = 0; i < MAX_THREAD; i++) {
        pthread_join(th[i].threadID, NULL);
    }

    // Printing QrCodes from each Thread
    for(int i = 0; i < MAX_THREAD; i++) {
        printf("QrCode from Thread %d:\n", i);
        for(int j = 0; j < qrdata[i].size; j++) {
            for(int k = 0; k < qrdata[i].size; k++) {
                if (qrdata[i].output[j*qrdata[i].size+k] == 0) {
                    printf(" ");
                } else {
                    printf("█");
                }
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}

// Function for Generating QR Codes
void* qrCodeGenerator(void *ptr) {

    Thread* threadptr = (Thread*)ptr;

    QRecLevel qreclevel = threadptr->qrdatal.level;

    int hint = threadptr->qrdatal.hint;

    QRcode* qrcode = QRcode_encodeString(threadptr->qrdatal.data, 0, qreclevel, hint, 1);

    int qrSize = qrcode->width + threadptr->qrdatal.margin * 2; // Margin

    // Generating QR Code
    for(int i = 0; i < qrSize; i++) {
        for(int j = 0; j < qrSize; j++) {
            if(i >= threadptr->qrdatal.margin && i < qrSize - threadptr->qrdatal.margin && j >= threadptr->qrdatal.margin && j < qrSize - threadptr->qrdatal.margin) {
                threadptr->qrdatal.output[(i-threadptr->qrdatal.margin)*(qrSize-2*threadptr->qrdatal.margin)+(j-threadptr->qrdatal.margin)] = qrcode->data[(i-threadptr->qrdatal.margin)*qrcode->width+(j-threadptr->qrdatal.margin)];
            } else {
                threadptr->qrdatal.output[i*qrSize+j] = 0;
            }
        }
    }

    QRcode_free(qrcode);

    pthread_exit(NULL);
}