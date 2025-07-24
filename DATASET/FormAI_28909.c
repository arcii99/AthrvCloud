//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    printf("Welcome to the Internet Speed Test Application!\n\n");

    printf("Please enter the number of times you want to run the test: ");
    int n;
    scanf("%d", &n);

    float sum = 0;
    int count = 0;

    for(int i=1; i<=n; i++)
    {
        printf("\nRunning test #%d...\n", i);

        srand(time(0)); // to generate random speeds
        float speed = (float) (rand() % 100 + 1); // speeds range from 1 to 100 Mbps

        printf("Your internet speed is %.2f Mbps\n", speed);

        sum += speed;
        count++;
    }

    printf("\n\n================ RESULTS ================\n\n");
    printf("You ran the test %d times\n", count);
    printf("Average speed: %.2f Mbps\n", (sum/count));

    return 0;
}