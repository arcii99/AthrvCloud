//FormAI DATASET v1.0 Category: Port Scanner ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {
    int port;
    char ip[20];
    printf("Enter the IP address to scan: ");
    scanf("%s", ip);
    printf("\n*** Initiating scan of IP address %s ***\n\n", ip);
    for(port=1;port<=65535;port++) {
        printf("Scanning port %d ", port);
        if(port%10==0) printf("\n");
        sleep(1); // Simulate scanning time
    }
    printf("\n*** Scan complete! ***\n");
    return 0;
}