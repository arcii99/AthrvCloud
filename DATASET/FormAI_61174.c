//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    clock_t t;
    double time_taken;
    float download_speed, upload_speed;
    char buffer[1024];
    FILE* pipe;

    printf("Running internet speed test...\n");

    t = clock(); // start clock

    // perform download speed test using wget command
    pipe = popen("wget -O /dev/null http://speedtest.wdc01.softlayer.com/downloads/test500.zip", "r");
    while (fgets(buffer, sizeof(buffer), pipe) != NULL) {} // read output
    pclose(pipe);

    t = clock() - t; // end clock
    time_taken = ((double)t)/CLOCKS_PER_SEC; // calculate time taken
    download_speed = 500/time_taken; // calculate download speed in MB/s

    printf("Download Speed: %.2f MB/s\n", download_speed);

    t = clock(); // start clock

    // perform upload speed test using curl command
    pipe = popen("curl -F 'file=@/dev/zero' -s https://transfer.sh/testfile | tr -d '\n'", "r");
    while (fgets(buffer, sizeof(buffer), pipe) != NULL) {} // read output
    pclose(pipe);

    t = clock() - t; // end clock
    time_taken = ((double)t)/CLOCKS_PER_SEC; // calculate time taken
    upload_speed = 0.025/time_taken; // calculate upload speed in MB/s

    printf("Upload Speed: %.2f MB/s\n", upload_speed);

    return 0;
}