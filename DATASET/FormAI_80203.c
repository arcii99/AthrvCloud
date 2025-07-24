//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int download, upload;
    srand(time(NULL));
    download = rand() % 100 + 1;
    upload = rand() % 100 + 1;

    printf("Welcome to the Internet Speed Test Application!\n");
    printf("Checking your internet speed...\n");
    printf("Download speed: %d Mbps\n", download);
    printf("Upload speed: %d Mbps\n", upload);

    if (download >= 50 && upload >= 50)
    {
        printf("Congratulations! Your internet speed is fast.\n");
    }
    else if (download >= 25 && upload >= 25)
    {
        printf("Your internet speed is decent.\n");
    }
    else
    {
        printf("Your internet speed is slow. Consider upgrading your plan.\n");
    }

    return 0;
}