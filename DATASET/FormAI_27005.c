//FormAI DATASET v1.0 Category: QR code generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <qrencode.h>

#define NUM_THREADS 10 // Number of threads to generate QR codes
#define MAX_CODE_LENGTH 200 // Maximum length of the input string

void *generateQRCode(void *inputString); // Thread's function to generate QR codes

int main()
{
    char inputStrings[NUM_THREADS][MAX_CODE_LENGTH]; // Array of input strings for each thread
    pthread_t threads[NUM_THREADS]; // Array of thread IDs
    
    // Initialize input strings with random data
    srand(time(NULL));
    for(int i=0; i<NUM_THREADS; i++)
    {
        int length = rand() % MAX_CODE_LENGTH + 1;
        for(int j=0; j<length; j++)
        {
            inputStrings[i][j] = 'A' + rand() % 26;
        }
        inputStrings[i][length] = '\0';
    }
    
    // Create threads to generate QR codes for each input string
    for(int i=0; i<NUM_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, generateQRCode, &inputStrings[i]);
    }
    
    // Wait for all threads to finish
    for(int i=0; i<NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }
    
    return 0;
}

void *generateQRCode(void *inputString)
{
    char *input = (char *)inputString;
    QRcode *qr = QRcode_encodeString(input, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    if(qr != NULL)
    {
        // Print QR code data (first 30 bytes only) to console
        printf("QR code generated for input \"%s\":\n", input);
        for(int i=0; i<30 && i<qr->width*(qr->width+7)/8; i++)
        {
            printf("%02x ", qr->data[i]);
        }
        printf("\n");
        
        QRcode_free(qr); // Free memory allocated for QR code data
    }
    else
    {
        printf("Error generating QR code for input \"%s\"\n", input);
    }
    
    pthread_exit(NULL); // Terminate thread
}