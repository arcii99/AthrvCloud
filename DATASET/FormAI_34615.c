//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

// Function to calculate internet speed
double calculate_speed(double data, double time_taken) {
    double speed = data / time_taken;
    return speed;
}

int main() {
    double data;
    printf("Enter the amount of data to be downloaded (in MB): ");
    scanf("%lf", &data);
    double time_start, time_end, time_taken;
    time_t start, end;
    int i;
    int speed[10];

    // Multivariable Speed Testing
    for (i = 0; i < 10; i++) {
        printf("Test %d\n", i+1);
        start = time(NULL);
        system("curl -O https://speedtest-ftp.netcologne.de/testfiles/100MB.bin");
        end = time(NULL);
        time_taken = difftime(end, start);
        speed[i] = calculate_speed(data, time_taken);
        printf("Speed in Test %d: %.2f MB/s\n\n", i+1, speed[i]);
        system("rm 100MB.bin");
    }

    // Finding average speed
    double total_speed = 0;
    for (i = 0; i < 10; i++) {
        total_speed += speed[i];
    }
    double avg_speed = total_speed / 10;
    printf("Average speed: %.2f MB/s\n", avg_speed);
    return 0;
}