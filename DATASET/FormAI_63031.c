//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int download_speed = 0;
    int upload_speed = 0;
    int ping_speed = 0;
    int num_tests = 3;
    int test_timeout = 10;

    srand(time(NULL)); // Seed random number generator

    printf("This is a completely confidential and secure internet speed test. Please press ENTER to begin the test.\n");
    getchar(); // Wait for user to press ENTER

    for (int i = 0; i < num_tests; i++) {
        printf("Test %d of %d...\n", i+1, num_tests);

        // Generate random download speed
        download_speed = rand() % 1000 + 1; // Speeds range from 1-1000 Mbps
        printf("Download speed: %d Mbps\n", download_speed);

        // Generate random upload speed
        upload_speed = rand() % 100 + 1; // Speeds range from 1-100 Mbps
        printf("Upload speed: %d Mbps\n", upload_speed);

        // Generate random ping speed
        ping_speed = rand() % 50 + 1; // Ping times range from 1-50 ms
        printf("Ping speed: %d ms\n\n", ping_speed);

        // Wait for user to complete test
        printf("Please wait %d seconds for the test to complete.\n", test_timeout);
        int count = 0;
        while (count < test_timeout) {
            printf("%d seconds remaining...\n", test_timeout-count);
            sleep(1);
            count++;
        }

        // Check for any unauthorized activity during test
        printf("Scanning for unauthorized activity...\n");
        int unauthorized_activity = rand() % 2; // 50/50 chance of unauthorized activity
        if (unauthorized_activity == 1) {
            printf("UNAUTHORIZED ACTIVITY DETECTED! THIS TEST HAS BEEN TERMINATED.\n");
            return 1; // Program terminates with error
        }

        printf("Test complete! Press ENTER to continue.\n");
        getchar(); // Wait for user to press ENTER
    }

    printf("All tests complete! Thank you for your cooperation.\n");
    return 0; // Program terminates successfully
}