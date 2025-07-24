//FormAI DATASET v1.0 Category: Firewall ; Style: Cryptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char input[128];
    printf("Enter IP Address: ");
    fgets(input, sizeof(input), stdin);

    char *ip = strtok(input, ".");        
    int octet1 = atoi(ip);

    ip = strtok(NULL, ".");               
    int octet2 = atoi(ip);

    ip = strtok(NULL, ".");
    int octet3 = atoi(ip);

    ip = strtok(NULL, ".");
    int octet4 = atoi(ip);

    if((octet1 == 10) ||                                
       ((octet1 == 172) && (octet2 >= 16 && octet2 <= 31)) || 
       ((octet1 == 192) && (octet2 == 168)))               
    {
        printf("IP address %d.%d.%d.%d is internal\n", octet1, octet2, octet3, octet4);
    }
    else                                                   
    {
        printf("IP address %d.%d.%d.%d is external\n", octet1, octet2, octet3, octet4);
    }

    return 0;
}