//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: creative
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Function to generate random internet speed value
float generate_speed() {
    float speed = ((float)rand()/(float)(RAND_MAX)) * 100.0;
    return speed;
}

int main() {
    int choice;
    float speed;
    srand(time(0));

    printf("Choose an option:\n1. Run a speed test\n2. Exit\n");
    scanf("%d", &choice);

    while(choice != 2) {
        if(choice == 1) {
            speed = generate_speed();
            printf("Your internet speed is: %.2f MB/s\n", speed);

            if(speed < 10.0) {
                printf("Your internet speed is very slow. Please contact your service provider.\n");
            } else if(speed < 50.0) {
                printf("Your internet speed is decent, but could be better. Consider upgrading your plan.\n");
            } else {
                printf("Your internet speed is great! Keep up the good work.\n");
            }
        } else {
            printf("Invalid choice. Please try again.\n");
        }

        printf("\nChoose an option:\n1. Run a speed test\n2. Exit\n");
        scanf("%d", &choice);
    }

    printf("Thank you for using our Internet Speed Test Application.\n");

    return 0;
}