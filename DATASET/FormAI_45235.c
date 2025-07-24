//FormAI DATASET v1.0 Category: Smart home automation ; Style: decentralized
#include <stdio.h>

// structure for smart home devices
struct smart_device{
    int device_id;
    int status;
};

// function to turn on smart device
void turn_on(struct smart_device* device){
    device->status = 1;
    printf("Smart device with ID %d is turned ON.\n", device->device_id);
}

// function to turn off smart device
void turn_off(struct smart_device* device){
    device->status = 0;
    printf("Smart device with ID %d is turned OFF.\n", device->device_id);
}

// function to toggle smart device status
void toggle(struct smart_device* device){
    if(device->status == 0){
        turn_on(device);
    }
    else{
        turn_off(device);
    }
}

int main(void) {
    // initializing smart home devices
    struct smart_device light = {1, 0};  // light with ID 1 and status OFF
    struct smart_device fan = {2, 0};    // fan with ID 2 and status OFF
    
    // turning on light
    turn_on(&light);
    
    // toggling fan
    toggle(&fan);
    
    // turning off light
    turn_off(&light);
    
    return 0;
}