//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>

int main(){
    
    printf("Starting Wireless Network Scanner...\n\n");
    
    char scan_cmd[100] = "iwlist wlan0 scan | grep ESSID > scan_report.txt";
    system(scan_cmd);
    
    FILE *scan_report;
    scan_report = fopen("scan_report.txt", "r");
    
    if(scan_report == NULL){
        printf("Error opening scan_report.txt file!");
        exit(1);
    }
    
    char line[100];
    int count = 0;
    
    while(fgets(line, 100, scan_report) != NULL){
        
        char *essid = strstr(line, "ESSID");
        if(essid != NULL){
            printf("%d. ", ++count);
            printf("%.*s\n", (int)strlen(essid)-1, essid+7);
        }
    }
    
    fclose(scan_report);
    printf("\nScanning complete. Found %d networks nearby.\n", count);
    
    return 0;
}