//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>

#define MAX_DEVICES 10
#define MAX_PACKETS 100

/* Struct to hold packet information */
typedef struct {
    int device;
    int size;
    int priority;
} Packet;

/* Struct to hold device information */
typedef struct {
    int id;
    int max_size;
    int current_size;
    int max_priority;
    int current_priority;
} Device;

/* Global variables */
Packet packets[MAX_PACKETS];
Device devices[MAX_DEVICES];
int num_packets = 0;
int num_devices = 0;

/* Function to add a packet to the system */
void add_packet(int device, int size, int priority) {
    if (num_packets < MAX_PACKETS) {
        packets[num_packets].device = device;
        packets[num_packets].size = size;
        packets[num_packets].priority = priority;
        num_packets++;
    }
}

/* Function to add a device to the system */
void add_device(int id, int max_size, int max_priority) {
    if (num_devices < MAX_DEVICES) {
        devices[num_devices].id = id;
        devices[num_devices].max_size = max_size;
        devices[num_devices].current_size = 0;
        devices[num_devices].max_priority = max_priority;
        devices[num_devices].current_priority = 0;
        num_devices++;
    }
}

/* Thread function to monitor device QoS */
void* monitor_device_qos(void* arg) {
    int device_id = *(int*)arg;
    
    while (1) {
        int i;
        int total_size = 0;
        int total_priority = 0;
        
        /* Calculate total size and priority of packets for this device */
        for (i = 0; i < num_packets; i++) {
            if (packets[i].device == device_id) {
                total_size += packets[i].size;
                total_priority += packets[i].priority;
            }
        }
        
        /* Update device QoS */
        for (i = 0; i < num_devices; i++) {
            if (devices[i].id == device_id) {
                devices[i].current_size = total_size;
                devices[i].current_priority = total_priority;
                break;
            }
        }
        
        /* Sleep for a second */
        sleep(1);
    }
    
    return NULL;
}

int main(int argc, char* argv[]) {
    int i;
    pthread_t threads[MAX_DEVICES];
    
    /* Add example devices */
    add_device(1, 100, 10);
    add_device(2, 50, 5);
    
    /* Add example packets */
    add_packet(1, 20, 5);
    add_packet(1, 15, 4);
    add_packet(2, 10, 3);
    add_packet(2, 20, 5);
    
    /* Create QoS monitoring threads for each device */
    for (i = 0; i < num_devices; i++) {
        pthread_create(&threads[i], NULL, monitor_device_qos, &devices[i].id);
    }
    
    /* Wait for threads to finish */
    for (i = 0; i < num_devices; i++) {
        pthread_join(threads[i], NULL);
    }
    
    return 0;
}