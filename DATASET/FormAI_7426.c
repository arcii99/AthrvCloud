//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random internet speed between 0 and 100 Mbps
int generate_speed(){
    int speed;
    srand(time(NULL));
    speed = rand() % 101;
    return speed;
}

// Function to print the speed and corresponding internet quality
void print_result(int speed){
    char* quality;
    if (speed >= 90){
        quality = "Excellent";
    } else if (speed >= 60) {
        quality = "Good";
    } else if (speed >= 30) {
        quality = "Ok";
    } else {
        quality = "Poor";
    }
    printf("Your internet speed is %d Mbps. The quality is %s.\n", speed, quality);
}

// Main function to run the internet speed test
int main(){
    printf("Welcome to the Internet Speed Test Application!\n");
    printf("Press enter to start the test:");
    getchar();

    // Simulating the speed test with 3 trials
    printf("Running the test...\n");
    int i;
    int avg_speed = 0;
    for (i=1; i<=3; i++){
        // Generating a random internet speed
        int speed = generate_speed();
        printf("Test %d: ", i);
        print_result(speed);
        avg_speed += speed;
    }

    // Calculating the average speed
    avg_speed /= 3;
    printf("Overall average speed: %d Mbps.\n", avg_speed);
    
    // Suggesting to upgrade internet plan if speed is too slow
    if (avg_speed < 30){
        printf("Your internet speed is too slow. Consider upgrading your plan for better internet quality and speed.\n");
    }
    printf("Thank you for using the Internet Speed Test Application. Have a great day!\n");
    return 0;
}