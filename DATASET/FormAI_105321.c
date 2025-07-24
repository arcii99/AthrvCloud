//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void analyze_wifi_strength(int dbm){
    if(dbm>=-30){
        printf("Your WiFi signal is exceptional!\n");
    }
    else if(dbm>=-67){
        printf("Your WiFi signal is good!\n");
    }
    else if(dbm>=-70){
        printf("Your WiFi signal is fair!\n");
    }
    else if(dbm>=-80){
        printf("Your WiFi signal is poor!\n");
    }
    else{
        printf("Your WiFi signal is weak!\n");
    }
}

int main(){
    int dBm;
    printf("Enter the WiFi signal strength in dBm: ");
    scanf("%d",&dBm);
    analyze_wifi_strength(dBm);
    return 0;
}