//FormAI DATASET v1.0 Category: Smart home automation ; Style: statistical
/*
 * Smart Home Automation Example Program
 * 
 * This program simulates an automated home system that allows the user to control various appliances and devices
 * via a central interface. The program uses statistical analysis to determine the most commonly used appliances 
 * and routines to conserve energy and reduce costs.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Device structure definition
struct device {
    char name[20];
    int power_rating;
    int status;
};

// Function declaration
void turn_on_device(struct device *dev);
void turn_off_device(struct device *dev);
void print_device_status(struct device *dev);

int main() {
    // Initializing devices
    struct device light = {"Light", 10, 0};
    struct device fan = {"Fan", 20, 0};
    struct device tv = {"TV", 50, 0};
    struct device ac = {"Air Conditioner", 100, 0};
    
    // Initializing statistics variables
    int total_usage = 0;
    int light_usage = 0;
    int fan_usage = 0;
    int tv_usage = 0;
    int ac_usage = 0;
    
    // Initializing random seed
    srand(time(NULL));
    
    // Simulating device usage for one week (7 days)
    for (int i = 1; i <= 7; i++) {
        printf("Day %d\n", i);
        // Simulating device usage for one day (24 hours)
        for (int j = 0; j < 24; j++) {
            // Randomly turning devices on and off
            int rand_num = rand() % 2;
            if (rand_num == 0) {
                turn_on_device(&light);
                light_usage++;
                total_usage += light.power_rating;
            } else {
                turn_off_device(&light);
            }
            rand_num = rand() % 2;
            if (rand_num == 0) {
                turn_on_device(&fan);
                fan_usage++;
                total_usage += fan.power_rating;
            } else {
                turn_off_device(&fan);
            }
            rand_num = rand() % 2;
            if (rand_num == 0) {
                turn_on_device(&tv);
                tv_usage++;
                total_usage += tv.power_rating;
            } else {
                turn_off_device(&tv);
            }
            if (j >= 12 && j <= 20) {
                turn_on_device(&ac);
                ac_usage++;
                total_usage += ac.power_rating;
            } else {
                turn_off_device(&ac);
            }
        }
        printf("Total usage for Day %d: %d kWh\n", i, total_usage);
    }
    
    // Printing statistics
    printf("\nUsage statistics for Light:\n");
    printf("Total usage for the week: %d kWh\n", light_usage);
    printf("Average daily usage: %d kWh\n", light_usage/7);
    printf("\nUsage statistics for Fan:\n");
    printf("Total usage for the week: %d kWh\n", fan_usage);
    printf("Average daily usage: %d kWh\n", fan_usage/7);
    printf("\nUsage statistics for TV:\n");
    printf("Total usage for the week: %d kWh\n", tv_usage);
    printf("Average daily usage: %d kWh\n", tv_usage/7);
    printf("\nUsage statistics for Air Conditioner:\n");
    printf("Total usage for the week: %d kWh\n", ac_usage);
    printf("Average daily usage: %d kWh\n", ac_usage/7);
    printf("\nTotal usage for the week: %d kWh\n", total_usage);
    
    return 0;
}

// Function definition to turn device on
void turn_on_device(struct device *dev) {
    dev->status = 1;
    printf("%s turned on\n", dev->name);
}

// Function definition to turn device off
void turn_off_device(struct device *dev) {
    dev->status = 0;
    printf("%s turned off\n", dev->name);
}

// Function definition to print device status
void print_device_status(struct device *dev) {
    printf("%s is currently %s\n", dev->name, dev->status ? "ON" : "OFF");
}