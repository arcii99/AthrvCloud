//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define TOTAL_TIME 10               /* The total time for internet speed test */
#define BUF_SIZE   (500 * 1024 * 8) /* Buffer size to be used for download test */
#define SERVER_URL "http://speedtest.telecom.com.cn/test/random4000x4000.jpg"
/* Download test server URL */

double calc_download_speed();
double calc_upload_speed();

int main()
{
    printf("Welcome to the Internet Speed Test Application!\n");
    printf("This application will test your internet speed for download and upload.\n");
    printf("Please wait for %d seconds while the test is being performed.\n\n", TOTAL_TIME);

    double download_speed = calc_download_speed();
    printf("Download speed: %.2f Mbps\n", download_speed);

    double upload_speed = calc_upload_speed();
    printf("Upload speed: %.2f Mbps\n\n", upload_speed);

    printf("Thank you for using the Internet Speed Test Application.\n");

    return 0;
}

double calc_download_speed()
{
    /* Download test */
    char cmd[BUF_SIZE];
    sprintf(cmd, "curl -s -o /dev/null -OJ %s", SERVER_URL); /* Download file from the server */
    system(cmd);

    time_t start_time = time(NULL);
    int bytes_received = 0;

    while (difftime(time(NULL), start_time) < TOTAL_TIME) {
        sprintf(cmd, "curl -s -o /dev/null %s", SERVER_URL);
        system(cmd);
        bytes_received += BUF_SIZE;
        usleep(1000);
    }

    double download_speed = (double)(bytes_received * 8) / (double)(TOTAL_TIME * 1000 * 1000);

    return download_speed;
}

double calc_upload_speed()
{
    /* Upload test */
    char cmd[BUF_SIZE];
    sprintf(cmd, "dd if=/dev/zero bs=500K count=8 | nc -w 5 -v speedtest.telecom.com.cn 9191 > /dev/null");
    /* Upload 4MB of data to the server */

    time_t start_time = time(NULL);
    int bytes_sent = 0;

    while (difftime(time(NULL), start_time) < TOTAL_TIME) {
        system(cmd);
        bytes_sent += BUF_SIZE;
        usleep(1000);
    }

    double upload_speed = (double)(bytes_sent * 8) / (double)(TOTAL_TIME * 1000 * 1000);

    return upload_speed;
}