//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h> // for usleep()

// Function to generate a random number between min and max
int random_num(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

int main(){
    srand(time(NULL)); // initialize random seed

    int wifi_strength = 0;
    int x_coordinate = random_num(0, 100);
    int y_coordinate = random_num(0, 100);

    printf("Analyzing Wi-Fi Signal Strength...\n");
    usleep(2000000); // wait for 2 seconds

    printf("Connecting to Wi-Fi network...\n");
    usleep(2000000); // wait for 2 seconds

    printf("Checking Wi-Fi signal strength...\n");
    wifi_strength = random_num(0, 100);

    if(wifi_strength > 80){
        printf("Your Wi-Fi signal strength is excellent (%d%%) at (%d, %d)!\n", wifi_strength, x_coordinate, y_coordinate);
    } else if(wifi_strength > 60){
        printf("Your Wi-Fi signal strength is good (%d%%) at (%d, %d).\n", wifi_strength, x_coordinate, y_coordinate);
    } else if(wifi_strength > 40){
        printf("Your Wi-Fi signal strength is fair (%d%%) at (%d, %d).\n", wifi_strength, x_coordinate, y_coordinate);
    } else {
        printf("Your Wi-Fi signal strength is poor (%d%%) at (%d, %d).\n", wifi_strength, x_coordinate, y_coordinate);
    }

    return 0;
}