//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BUF_LEN 1024
#define MAX_DELAY 100

// function to calculate network quality of service using mathematical model
double calculate_qos(double throughput, double delay, double jitter)
{
    double qos;

    qos = (pow(throughput/10, 4) * pow(jitter/10, 2)) / (pow(delay/10, 3));
    
    return qos;
}

int main()
{
    char buffer[BUF_LEN];
    double throughput, delay, jitter, qos;

    // get input from user
    printf("Enter the network throughput (in Mbps): ");
    fgets(buffer, BUF_LEN, stdin);
    throughput = atof(buffer);
    printf("Enter the average delay (in ms): ");
    fgets(buffer, BUF_LEN, stdin);
    delay = atof(buffer);
    printf("Enter the jitter (in ms): ");
    fgets(buffer, BUF_LEN, stdin);
    jitter = atof(buffer);

    // validate input
    if(throughput <= 0)
    {
        printf("Invalid throughput entered. Program terminated.\n");
        return 1;
    }
    if(delay <= 0 || delay > MAX_DELAY)
    {
        printf("Invalid delay entered. Program terminated.\n");
        return 1;
    }
    if(jitter <= 0 || jitter > MAX_DELAY)
    {
        printf("Invalid jitter entered. Program terminated.\n");
        return 1;
    }

    // calculate network quality of service
    qos = calculate_qos(throughput, delay, jitter);

    // output result to user
    printf("The network quality of service is: %.2f\n", qos);

    return 0;
}