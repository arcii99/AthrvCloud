//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 100
#define MAX_LINKS 100

typedef struct device{
    char name[20];
    char ip[20];
    char subnet_mask[20];
} Device;

typedef struct link{
    Device *device_1;
    Device *device_2;
    char speed[10];
} Link;

Device devices[MAX_DEVICES];
Link links[MAX_LINKS];
int num_devices = 0;
int num_links = 0;

void add_device(char name[], char ip[], char subnet_mask[]){
    if(num_devices < MAX_DEVICES){
        Device new_device;
        strcpy(new_device.name, name);
        strcpy(new_device.ip, ip);
        strcpy(new_device.subnet_mask, subnet_mask);
        devices[num_devices] = new_device;
        num_devices++;
        printf("Device %s added successfully!\n", name);
    }
    else{
        printf("Max number of devices reached!\n");
    }
}

void add_link(Device *device_1, Device *device_2, char speed[]){
    if(num_links < MAX_LINKS){
        Link new_link;
        new_link.device_1 = device_1;
        new_link.device_2 = device_2;
        strcpy(new_link.speed, speed);
        links[num_links] = new_link;
        num_links++;
        printf("Link created successfully between %s and %s with speed %s.\n", device_1->name, device_2->name, speed);
    }
    else{
        printf("Max number of links reached!\n");
    }
}

void display_devices(){
    printf("List of devices:\n");
    for(int i=0; i<num_devices; i++){
        printf("Name: %s, IP: %s, Subnet Mask: %s\n", devices[i].name, devices[i].ip, devices[i].subnet_mask);
    }
}

void display_links(){
    printf("List of links:\n");
    for(int i=0; i<num_links; i++){
        printf("%s - %s, Speed: %s\n", links[i].device_1->name, links[i].device_2->name, links[i].speed);
    }
}

int main(){
    add_device("Router1", "192.168.0.1", "255.255.255.0");
    add_device("Switch1", "192.168.0.2", "255.255.255.0");
    add_device("Switch2", "192.168.0.3", "255.255.255.0");
    display_devices();
    printf("\n");
    add_link(&devices[0], &devices[1], "100 Mbps");
    add_link(&devices[0], &devices[2], "1 Gbps");
    display_links();
    return 0;
}