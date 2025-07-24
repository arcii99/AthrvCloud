//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DEVICES 100

int device_count = 0;

typedef struct Device{
    char name[20];
    char ip_address[20];
    char mac_address[20];
    bool is_up;
} Device;

Device devices[MAX_DEVICES];

void add_device(char* name,char* ip_address,char* mac_address,bool is_up){
    Device device = {
        .name=name,
        .ip_address=ip_address,
        .mac_address=mac_address,
        .is_up=is_up
    };
    devices[device_count++] = device;
}

void print_devices(){
    printf("\n================ Network Topology Mapper ================\n");
    printf("|%-20s|%-20s|%-20s|%-10s|\n","Name","IP Address","MAC Address","Status");
    printf("==========================================================\n");
    for(int i=0;i<device_count;i++){
        printf("|%-20s|%-20s|%-20s|%-10s|\n",devices[i].name,
                devices[i].ip_address, devices[i].mac_address,
                devices[i].is_up ? "UP" : "DOWN");
    }
    printf("==========================================================\n");
}

int main(){
    add_device("Router 1","192.168.1.1","00:11:22:33:44:55",true);
    add_device("Switch 1","192.168.1.2","AA:BB:CC:DD:EE:FF",true);
    add_device("PC 1","192.168.1.10","11:22:33:44:55:66",true);
    add_device("Printer 1","192.168.1.20","AA:11:BB:22:CC:33",false);
    add_device("Access Point 1","192.168.1.30","55:44:33:22:11:00",true);

    print_devices();

    return 0;
}