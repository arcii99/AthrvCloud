//FormAI DATASET v1.0 Category: Firewall ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

#define PORT_MAX 65535

bool allowedPorts[PORT_MAX];

void* firewallHandler(void* arg) {
    int portNumber = *(int*)arg;
    if (allowedPorts[portNumber]) {
        printf("Port %d is allowed.\n", portNumber);
    } else {
        printf("Port %d is blocked.\n", portNumber);
    }
    pthread_exit(NULL);
}

int main() {
    //Initialize allowedPorts to false for all ports
    for (int i = 0; i < PORT_MAX; i++) {
        allowedPorts[i] = false;
    }

    //Open ports for communication
    allowedPorts[80] = true; //HTTP
    allowedPorts[443] = true; //HTTPS
    allowedPorts[22] = true; //SSH
    allowedPorts[25] = true; //SMTP
    allowedPorts[587] = true; //SMTP - TLS

    //User input for ports to check
    int numPorts, currentPort;
    printf("Enter number of ports to check: ");
    scanf("%d", &numPorts);
    int ports[numPorts];
    printf("Enter port number(s) to check:\n");
    for (int i = 0; i < numPorts; i++) {
        scanf("%d", &currentPort);
        ports[i] = currentPort;
    }

    //Create threads for checking each port
    pthread_t threads[numPorts];
    for (int i = 0; i < numPorts; i++) {
        pthread_create(&threads[i], NULL, firewallHandler, &ports[i]);
    }
    
    //Wait for all threads to finish
    for (int i = 0; i < numPorts; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}