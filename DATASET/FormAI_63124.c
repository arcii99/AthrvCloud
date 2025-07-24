//FormAI DATASET v1.0 Category: Smart home light control ; Style: single-threaded
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#define MAX_LEN 25
#define MAX_DEVICE 5
 
typedef struct bulb{
    char name[MAX_LEN];
    int state;
    int brightness;
}Bulb;

int total_bulbs = 0;

/* Function to initialize device state and brightness */
void initialize_device(Bulb *device){
    device->state = 0;
    device->brightness = 50;
}

/* Function to add new device into the system */
int add_device(Bulb *device_list){
    if(total_bulbs >= MAX_DEVICE){
        printf("No more devices can be added to the system!\n");
        return 0;
    }
    Bulb new_device;
    printf("Enter the bulb name: ");
    scanf("%s", new_device.name);
    initialize_device(&new_device);
    device_list[total_bulbs] = new_device;
    total_bulbs++;
    printf("Device added successfully!\n");
    return 1;
}

/* Function to remove device from the system */
int remove_device(Bulb *device_list, char* dev_name){
    int i, device_index = -1;
    for(i=0;i<total_bulbs;i++){
        if(strcmp(dev_name, device_list[i].name)==0){
            device_index = i;
            break;
        }
    }
    if(device_index==-1){
        printf("No such device found in the system!\n");
        return 0;
    }
    total_bulbs--;
    for(i=device_index;i<total_bulbs;i++){
        device_list[i] = device_list[i+1];
    }
    printf("Device successfully removed from the system!\n");
    return 1;
}

/* Function to turn ON/OFF device */
int switch_device(Bulb *device_list, char* dev_name){
    int i, device_index = -1;
    for(i=0;i<total_bulbs;i++){
        if(strcmp(dev_name, device_list[i].name)==0){
            device_index = i;
            break;
        }
    }
    if(device_index==-1){
        printf("No such device found in the system!\n");
        return 0;
    }
    if(device_list[device_index].state==0){
        device_list[device_index].state = 1;
        printf("%s is turned ON!\n", dev_name);
    }
    else{
        device_list[device_index].state = 0;
        printf("%s is turned OFF!\n", dev_name);
    }
    return 1;
}

/* Function to set brightness of the device */
int set_brightness(Bulb *device_list, char* dev_name, int brightness){
    int i, device_index = -1;
    for(i=0;i<total_bulbs;i++){
        if(strcmp(dev_name, device_list[i].name)==0){
            device_index = i;
            break;
        }
    }
    if(device_index==-1){
        printf("No such device found in the system!\n");
        return 0;
    }
    if(brightness<0 || brightness>100){
        printf("Invalid brightness value provided!\n");
        return 0;
    }
    device_list[device_index].brightness = brightness;
    printf("%s brightness set to %d!\n", dev_name, brightness);
    return 1;
}

/* Function to display the current device status */
void display_devices(Bulb *device_list){
    int i;
    if(total_bulbs==0){
        printf("No devices found in the system!\n");
        return;
    }
    printf("List of devices in the system with their status and brightness:\n");
    for(i=0;i<total_bulbs;i++){
        printf("%d. %s - %s - Brightness:%d\n", i+1, device_list[i].name, device_list[i].state==1?"ON":"OFF", device_list[i].brightness);
    }
}

int main(){
    int choice, success;
    Bulb device_list[MAX_DEVICE];
    while(1){
        printf("\n============================\n");
        printf("SMART LIGHT CONTROL SYSTEM\n");
        printf("============================\n");
        printf("1. Add device\n");
        printf("2. Remove device\n");
        printf("3. Switch device ON/OFF\n");
        printf("4. Set brightness\n");
        printf("5. Display devices\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                success = add_device(device_list);
                if(success){
                    display_devices(device_list);
                }
                break;
            case 2:
                printf("Enter the device name to remove: ");
                char dev_name[MAX_LEN];
                scanf("%s", dev_name);
                success = remove_device(device_list, dev_name);
                if(success){
                    display_devices(device_list);
                }
                break;
            case 3:
                printf("Enter the device name to switch ON/OFF: ");
                char dev_name_switch[MAX_LEN];
                scanf("%s", dev_name_switch);
                success = switch_device(device_list, dev_name_switch);
                if(success){
                    display_devices(device_list);
                }
                break;
            case 4:
                printf("Enter the device name: ");
                char dev_name_brightness[MAX_LEN];
                scanf("%s", dev_name_brightness);
                int brightness;
                printf("Enter the brightness value (0-100): ");
                scanf("%d", &brightness);
                success = set_brightness(device_list, dev_name_brightness, brightness);
                if(success){
                    display_devices(device_list);
                }
                break;
            case 5:
                display_devices(device_list);
                break;
            case 6:
                printf("Exiting the program!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}