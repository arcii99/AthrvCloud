//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Define constants for QoS */
#define MAX_PACKET_SIZE 1500 // Maximum packet size in bytes
#define MAX_BUFFER_SIZE 10000 // Maximum buffer size in bytes
#define MAX_DELAY 10 // Maximum delay in milliseconds
#define MAX_JITTER 5 // Maximum jitter in milliseconds
#define MAX_LOSS_RATE 0.1 // Maximum loss rate

/* Define variables for QoS */
float packet_size = 0; // Size of packets in bytes
float buffer_size = 0; // Size of buffer in bytes
float delay = 0; // Delay in milliseconds
float jitter = 0; // Jitter in milliseconds
float loss_rate = 0; // Loss rate

/* Function to calculate delay */
float calculate_delay(float packet_size, float buffer_size)
{
    float processing_time = packet_size * 8 / 1000000; // Convert packet size to bits and divide by 1 million to convert to milliseconds
    float transmission_time = buffer_size / packet_size * 8 / 1000000; // Divide buffer size by packet size to get number of packets, then multiply by packet size in bits, and divide by 1 million to convert to milliseconds
    float total_delay = processing_time + transmission_time; // Sum the two delays
    return total_delay;
}

/* Function to calculate jitter */
float calculate_jitter(float delay)
{
    float jitter = delay / 2; // Jitter is half of the delay
    return jitter;
}

/* Function to calculate loss rate */
float calculate_loss_rate(float packet_size, float buffer_size)
{
    float num_packets = buffer_size / packet_size; // Number of packets that can fit in the buffer
    float lost_packets = roundf(num_packets * MAX_LOSS_RATE); // Round the number of packets lost to the nearest integer
    float loss_rate = lost_packets / num_packets; // Divide the number of lost packets by the total number of packets
    return loss_rate;
}

int main()
{
    /* Set values for QoS */
    packet_size = MAX_PACKET_SIZE;
    buffer_size = MAX_BUFFER_SIZE;
    
    /* Calculate QoS values */
    delay = calculate_delay(packet_size, buffer_size);
    jitter = calculate_jitter(delay);
    loss_rate = calculate_loss_rate(packet_size, buffer_size);
    
    printf("Network Quality of Service (QoS) Monitor\n\n");
    printf("Packet Size: %.2f bytes\n", packet_size);
    printf("Buffer Size: %.2f bytes\n", buffer_size);
    printf("Maximum Delay: %.2f ms\n", MAX_DELAY);
    printf("Maximum Jitter: %.2f ms\n", MAX_JITTER);
    printf("Maximum Loss Rate: %.2f\n\n", MAX_LOSS_RATE);
    
    printf("Current Delay: %.2f ms\n", delay);
    printf("Current Jitter: %.2f ms\n", jitter);
    printf("Current Loss Rate: %.2f\n", loss_rate);
    
    /* Check if current QoS values are within acceptable limits */
    if (delay <= MAX_DELAY && jitter <= MAX_JITTER && loss_rate <= MAX_LOSS_RATE)
    {
        printf("\nNetwork is within acceptable limits.\n");
    }
    else
    {
        printf("\nNetwork is experiencing problems.\n");
    }
    
    return 0;
}