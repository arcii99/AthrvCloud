//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void download_speed_test() {
    float download_speed;
    char *download_message;
    int random_num = rand() % 10 + 1;
    int download_speed_arr[] = {2, 5, 10, 20, 50, 100};
    
    sleep(2); // Simulating download time
    download_speed = (float)random_num * 2.5;
    
    if (download_speed < download_speed_arr[0]) {
        download_message = "Your download speed is very slow!";
    } else if (download_speed < download_speed_arr[1]) {
        download_message = "Your download speed is slow!";
    } else if (download_speed < download_speed_arr[2]) {
        download_message = "Your download speed is average.";
    } else if (download_speed < download_speed_arr[3]) {
        download_message = "Your download speed is good!";
    } else if (download_speed < download_speed_arr[4]) {
        download_message = "Your download speed is very good!";
    } else {
        download_message = "Your download speed is excellent!";
    }

    printf("*** DOWNLOAD SPEED TEST ***\n\n");
    printf("Download Speed: %.2f Mbps\n", download_speed);
    printf("%s\n", download_message);
}

void upload_speed_test() {
    float upload_speed;
    char *upload_message;
    int random_num = rand() % 10 + 1;
    int upload_speed_arr[] = {1, 2, 5, 10, 20, 50};
    
    sleep(1); // Simulating upload time
    upload_speed = (float)random_num;
    
    if (upload_speed < upload_speed_arr[0]) {
        upload_message = "Your upload speed is very slow!";
    } else if (upload_speed < upload_speed_arr[1]) {
        upload_message = "Your upload speed is slow!";
    } else if (upload_speed < upload_speed_arr[2]) {
        upload_message = "Your upload speed is average.";
    } else if (upload_speed < upload_speed_arr[3]) {
        upload_message = "Your upload speed is good!";
    } else if (upload_speed < upload_speed_arr[4]) {
        upload_message = "Your upload speed is very good!";
    } else {
        upload_message = "Your upload speed is excellent!";
    }
    
    printf("\n*** UPLOAD SPEED TEST ***\n\n");
    printf("Upload Speed: %.2f Mbps\n", upload_speed);
    printf("%s\n", upload_message);
}

int main() {
    printf("Starting Internet Speed Test...\n\n");
    srand(time(0)); // seed random number generator
    
    download_speed_test();
    
    upload_speed_test();
    
    printf("\nThank you for using the Internet Speed Test!\n");
    
    return 0;
}