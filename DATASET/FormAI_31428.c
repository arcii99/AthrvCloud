//FormAI DATASET v1.0 Category: QR code reader ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

struct QRCode{
    char data[MAX_LINE_LENGTH];
};

int main(){
    struct QRCode code;
    printf("Enter the QR Code data: ");
    fgets(code.data, MAX_LINE_LENGTH, stdin);
    // Remove the trailing newline character
    code.data[strcspn(code.data, "\n")] = 0;
    // Check if the data contains only alphanumeric characters
    for(int i = 0; i < strlen(code.data); i++){
        if(!isalnum(code.data[i])){
            printf("Invalid QR Code data! Must contain only alphanumeric characters.\n");
            return 0;
        }
    }
    // Generate a URL based on the QR Code data
    char url[MAX_LINE_LENGTH + 25];
    strcpy(url, "http://example.com/");
    strcat(url, code.data);
    // Display the URL
    printf("URL: %s\n", url);
    return 0;
}