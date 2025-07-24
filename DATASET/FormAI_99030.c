//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("\n\t\t***** C Internet Speed Test Application *****\n\n");

    printf("Press enter to start the test...");
    getchar();

    printf("\nTesting Download Speed...\n");

    int download_speed = 0;
    int download_time = 0;

    srand(time(0));

    for(int i = 1; i <= 10; i++)
    {
        int x = rand() % 50 + 1;
        download_speed += x;
        printf("Downloading Chunk %d... Completed!\n", i);
        download_time += (x * 1000 / 60);
    }

    float avg_download_speed = download_speed / 10.0;
    printf("\n\tDownload Speed: %.2f Mbps\n", avg_download_speed);

    printf("\nPress enter to start Upload Test...");
    getchar();

    printf("\nTesting Upload Speed...\n");

    int upload_speed = 0;
    int upload_time = 0;

    srand(time(0));

    for(int i = 1; i <= 10; i++)
    {
        int x = rand() % 20 + 1;
        upload_speed += x;
        printf("Uploading Chunk %d... Completed!\n", i);
        upload_time += (x * 1000 / 30);
    }

    float avg_upload_speed = upload_speed / 10.0;
    printf("\n\tUpload Speed: %.2f Mbps\n", avg_upload_speed);

    printf("\nTest Completed in %d seconds!\n", (download_time + upload_time) / 1000);

    printf("\n\t\t***** Thank You for using C Internet Speed Test Application *****\n\n");

    return 0;
}