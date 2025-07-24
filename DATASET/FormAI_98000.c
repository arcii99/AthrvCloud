//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define RSSI_MIN -100
#define RSSI_MAX 0
#define MAX_MAC_SIZE 6
#define MAX_RSSI_SIZE 3
#define MAX_SSID_SIZE 32

typedef struct wifi{
    char macAddress[MAX_MAC_SIZE+1];
    char ssid[MAX_SSID_SIZE+1];
    int rssi;
} Wifi;

void printWifi(Wifi wifi){
    printf("%02X:%02X:%02X:%02X:%02X:%02X | %s | %d dBm\n",
    wifi.macAddress[0],wifi.macAddress[1],wifi.macAddress[2],
    wifi.macAddress[3],wifi.macAddress[4],wifi.macAddress[5],
    wifi.ssid,wifi.rssi);
}

void generateRandomMacAddress(char* macAddress){
    int i;
    for(i=0;i<MAX_MAC_SIZE;i++){
        if(i%2==0){
            macAddress[i] = rand()%16;
        }else{
            macAddress[i] = rand()%256;
        }
    }
}

int generateRandomRssi(){
    return (rand()%(RSSI_MAX-RSSI_MIN+1))+RSSI_MIN;
}

void generateRandomWifi(Wifi* wifi){
    generateRandomMacAddress(wifi->macAddress);
    sprintf(wifi->ssid,"%d_%d",rand()%10000,rand()%10000);
    wifi->rssi = generateRandomRssi();
}

int getWifiStrengthInPercentage(int rssi){
    double distance = pow(10,(abs(rssi)-59)/(10.0*6));
    return round((1.0-(distance/100))*100);
}

int main(){
    srand(time(NULL));

    // Create and print 10 random wifi signals
    Wifi wifis[10];
    int i;
    for(i=0;i<10;i++){
        generateRandomWifi(&wifis[i]);
        printWifi(wifis[i]);
    }
    
    printf("\nWiFi Signal Strength Analyzer\n\n");

    // Get a MAC address from the user and check signal strength
    char macAddress[MAX_MAC_SIZE+1];
    printf("Enter MAC address in format xx:xx:xx:xx:xx:xx\n");
    scanf("%x:%x:%x:%x:%x:%x",&macAddress[0],&macAddress[1],&macAddress[2],
    &macAddress[3],&macAddress[4],&macAddress[5]);
    printf("Looking for Wi-Fi signal from MAC address: %02X:%02X:%02X:%02X:%02X:%02X\n",
    macAddress[0],macAddress[1],macAddress[2],macAddress[3],macAddress[4],macAddress[5]);

    bool found = false;
    int strength = 0;
    for(i=0;i<10;i++){
        if(memcmp(wifis[i].macAddress,macAddress,sizeof(macAddress))==0){
            found = true;
            strength = getWifiStrengthInPercentage(wifis[i].rssi);
            printf("Signal found! Signal Strength: %d%%\n",strength);
            break;
        }
    }

    if(!found){
        printf("Signal not found for MAC Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
        macAddress[0],macAddress[1],macAddress[2],macAddress[3],macAddress[4],macAddress[5]);
    }

    return 0;
}