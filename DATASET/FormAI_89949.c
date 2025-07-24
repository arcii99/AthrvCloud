//FormAI DATASET v1.0 Category: Firewall ; Style: rigorous
#include<stdio.h>
#include<string.h>

int main() {
    char sourceIP[15];
    char destIP[15];
    char firewallList[10][15] = {"10.0.0.1", "192.168.1.1", "172.16.0.1", "192.168.0.1", "10.0.0.2", "192.168.1.2", "172.16.0.2", "192.168.0.2", "10.0.0.3", "192.168.1.3"};

    int i, j, flag = 0;

    printf("Enter the Source IP: ");
    scanf("%s", sourceIP);

    printf("Enter the Destination IP: ");
    scanf("%s", destIP);

    for(i = 0; i < 10; i++) {
        if(strcmp(sourceIP, firewallList[i]) == 0) {
            flag = 1;
            break;
        }
    }

    if(flag == 1) {
        printf("Source IP is in the Firewall List! Access Denied.\n");
    }
    else {
        flag = 0;
        for(j = 0; j < 10; j++) {
            if(strcmp(destIP, firewallList[j]) == 0) {
                flag = 1;
                break;
            }
        }

        if(flag == 1) {
            printf("Destination IP is in the Firewall List! Access Denied.\n");
        }
        else {
            printf("Access Granted!\n");
        }
    }

    return 0;
}