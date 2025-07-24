//FormAI DATASET v1.0 Category: QR code reader ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

// Function to check if qr code contains only alphanumeric characters
bool isAlphaNumeric(char *qrCode)
{
    for(int i = 0; i < strlen(qrCode); i++)
    {
        if(!isalnum(qrCode[i]))
        {
            return false;
        }
    }
    return true;
}

// Function to scan QR code using webcam
void scanQRCode(char *buffer)
{
    pid_t pid = fork();

    if(pid == -1)
    {
        printf("\nFailed to fork process.\n");
        return;
    }
    else if(pid == 0)
    {
        char *arguments[] = {"zbarcam", "--raw", "/dev/video0", NULL};
        execvp(arguments[0], arguments);
    }
    else
    {
        wait(NULL);

        FILE *fp;
        char path[MAX_BUFFER_SIZE];

        // Reading QR code output from zbarcam
        fp = popen("zbarimg --raw /tmp/zbarcam/*.pnm", "r");
        if(fp == NULL)
        {
            printf("\nFailed to execute zbarimg command.\n");
            return;
        }

        fgets(path, MAX_BUFFER_SIZE, fp);

        if(path[0] == '\0')
        {
            printf("\nNo QR code found.\n");
            return;
        }

        strcpy(buffer, path);

        pclose(fp);

        printf("\nQR code scanned: %s\n", buffer);
    }   
}

// Main function to read and validate QR code
int main()
{
    char buffer[MAX_BUFFER_SIZE];

    scanQRCode(buffer);

    if(!isAlphaNumeric(buffer))
    {
        printf("\nInvalid QR code.\n");
        return 0;
    }

    printf("\nValid QR code.\n");
    return 0;
}