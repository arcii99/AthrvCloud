//FormAI DATASET v1.0 Category: QR code generator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 2048

void generate_qr(char* text);
char* get_qr_url(char* text);

int main()
{
    char* text = (char*) malloc(sizeof(char) * BUFFER_SIZE);
    printf("Enter the text you want to convert to QR code: ");
    fgets(text, BUFFER_SIZE, stdin);
    generate_qr(text);
    free(text);
    return 0;
}

void generate_qr(char* text)
{
    char* qr_url = get_qr_url(text);
    printf("QR code URL: %s\n", qr_url);
    // code to display the generated QR code image on screen
    free(qr_url);
}

char* get_qr_url(char* text)
{
    char* api_url = "https://api.qrserver.com/v1/create-qr-code/?size=300x300&data=";
    char* encoded_text = (char*) malloc(sizeof(char) * BUFFER_SIZE);
    // code to encode the text as a URL parameter
    char* qr_url = (char*) malloc(sizeof(char) * (strlen(api_url) + strlen(encoded_text) + 1));
    sprintf(qr_url, "%s%s", api_url, encoded_text);
    free(encoded_text);
    return qr_url;
}