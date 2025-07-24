//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// function to validate the user input
bool validate_input(char* input){
    // check if input is empty
    if (strlen(input) == 0){
        return false;
    }

    // check if input contains only digits and dots
    for (int i = 0; i < strlen(input); i++){
        if ((input[i] < '0' || input[i] > '9') && input[i] != '.'){
            return false;
        }
    }

    // check if input contains exactly 3 dots
    int dot_count = 0;
    for (int i = 0; i < strlen(input); i++){
        if (input[i] == '.'){
            dot_count++;
        }
    }
    if (dot_count != 3){
        return false;
    }

    // check if each octet is between 0 and 255
    char* octet = strtok(input, ".");
    while (octet != NULL){
        int val = atoi(octet);
        if (val < 0 || val > 255){
            return false;
        }
        octet = strtok(NULL, ".");
    }

    return true;
}

// function to calculate the network address and broadcast address
void calculate_network_and_broadcast(char* ip_address, char* subnet_mask, char* network_address, char* broadcast_address){
    // convert the ip address and subnet mask to binary
    int ip_binary[32];
    int subnet_binary[32];
    char* octet = strtok(ip_address, ".");
    int i = 0;
    while (octet != NULL){
        int val = atoi(octet);
        for (int j = 7; j >= 0; j--){
            ip_binary[i] = val >> j & 1;
            i++;
        }
        octet = strtok(NULL, ".");
    }

    octet = strtok(subnet_mask, ".");
    i = 0;
    while (octet != NULL){
        int val = atoi(octet);
        for (int j = 7; j >= 0; j--){
            subnet_binary[i] = val >> j & 1;
            i++;
        }
        octet = strtok(NULL, ".");
    }

    // calculate the network address and broadcast address
    for (int i = 0; i < 32; i++){
        if (i < 24){
            network_address[i / 8] |= ip_binary[i] & subnet_binary[i];
            broadcast_address[i / 8] |= ip_binary[i] & subnet_binary[i];
        } else {
            network_address[i / 8] |= subnet_binary[i];
            broadcast_address[i / 8] |= !subnet_binary[i];
        }
    }
}

int main(){
    char ip_address[16], subnet_mask[16];

    // get user input
    do {
        printf("Enter IP address: ");
        fgets(ip_address, 16, stdin);
        ip_address[strcspn(ip_address, "\n")] = 0;
    } while (!validate_input(ip_address));

    do {
        printf("Enter subnet mask: ");
        fgets(subnet_mask, 16, stdin);
        subnet_mask[strcspn(subnet_mask, "\n")] = 0;
    } while (!validate_input(subnet_mask));

    // calculate network address and broadcast address
    char network_address[16] = {0};
    char broadcast_address[16] = {0};
    calculate_network_and_broadcast(ip_address, subnet_mask, network_address, broadcast_address);

    // print results
    printf("IP address: %s\n", ip_address);
    printf("Subnet mask: %s\n", subnet_mask);
    printf("Network address: %s\n", network_address);
    printf("Broadcast address: %s\n", broadcast_address);

    return 0;
}