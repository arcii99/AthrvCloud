//FormAI DATASET v1.0 Category: System boot optimizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    char* name;
    int status;
} Service;

void optimize(Service* services, int numServices);
void enableService(Service* service);
void disableService(Service* service);
void printServiceStatus(Service* service);

int main() {
    Service services[] = {
        {"NetworkManager", TRUE},
        {"cron", TRUE},
        {"sshd", TRUE},
        {"cups", TRUE},
        {"printers", TRUE},
        {"mysql", TRUE},
        {"apache2", TRUE},
        {"postgresql", TRUE},
        {"samba", TRUE},
        {"ntp", TRUE},
        {"avahi-daemon", TRUE}
    };
    int numServices = sizeof(services)/sizeof(services[0]);

    printf("Starting system boot optimizer...\n\n");
    optimize(services, numServices);
    printf("\nSystem boot optimizer complete!\n");

    return 0;
}

void optimize(Service* services, int numServices) {
    printf("Checking services...\n");
    for(int i = 0; i < numServices; i++) {
        printServiceStatus(&services[i]);
    }

    printf("Optimizing system boot...\n");
    for (int i = 0; i < numServices; i++) {
        if (services[i].status == TRUE) {
            disableService(&services[i]);
        }
    }

    printf("Final service status:\n");
    for (int i = 0; i < numServices; i++) {
        printServiceStatus(&services[i]);
    }
}

void enableService(Service* service) {
    printf("Enabling service: %s...\n", service->name);
    service->status = TRUE;
    printf("%s service enabled.\n", service->name);
}

void disableService(Service* service) {
    printf("Disabling service: %s...\n", service->name);
    service->status = FALSE;
    printf("%s service disabled.\n", service->name);
}

void printServiceStatus(Service* service) {
    if (service->status == TRUE) {
        printf("%s service is enabled.\n", service->name);
    } else {
        printf("%s service is disabled.\n", service->name);
    }
}