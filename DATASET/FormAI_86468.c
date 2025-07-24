//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: light-weight
#include<stdio.h>
#include<time.h>

int main() {
    float mbytes, speed;
    time_t start_t, end_t;
    double time_taken;

    printf("Enter the size of file you want to download in MB: ");
    scanf("%f", &mbytes);

    printf("\nTesting Internet Speed....\n");

    time(&start_t);
    // Downlaod the given size of file, you can add code to download file or use some api to download it.

    time(&end_t);

    time_taken = (double) (end_t - start_t);
    speed = mbytes / time_taken;

    printf("\nYour Internet Speed is %.2f MB/s\n", speed);

    return 0;
}