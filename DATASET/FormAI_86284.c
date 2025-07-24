//FormAI DATASET v1.0 Category: System boot optimizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct boot_opt{
    char os_version[20];
    int startup_time;
    int num_services;
    char services[50][50];
} Boot_Opt;

int main(){
    Boot_Opt system_opt;
    system_opt.startup_time = 20;
    system_opt.num_services = 10;
    strcpy(system_opt.os_version, "Ubuntu 20.04");

    printf("Welcome to the C System Boot Optimizer!\n");
    printf("This program will optimize your system's startup time.\n");

    srand(time(0));

    printf("\nChecking for unnecessary services...\n");
    for(int i=0; i<system_opt.num_services; i++){
        if(rand()%2 == 0){
            strcpy(system_opt.services[i], "STOP");
        }
    }

    printf("Analyzing system settings...\n");
    if(strcmp(system_opt.os_version, "Ubuntu 20.04")==0){
        system_opt.startup_time -= 5;
    }else{
        system_opt.startup_time += 5;
    }

    printf("Optimizing boot sequence...\n");
    for(int i=0; i<system_opt.num_services-1; i++){
        for(int j=0; j<system_opt.num_services-i-1; j++){
            if(strcmp(system_opt.services[j], "STOP")==0){
                strcpy(system_opt.services[j], system_opt.services[j+1]);
                strcpy(system_opt.services[j+1], "STOP");
            }
        }
    }

    printf("\nBoot Optimization Report:\n");
    printf("System: %s\n", system_opt.os_version);
    printf("Services Stopped:\n");
    for(int i=0; i<system_opt.num_services; i++){
        if(strcmp(system_opt.services[i], "STOP")==0){
            printf("- %s\n", system_opt.services[i]);
        }
    }

    printf("\nBoot time reduced by %d seconds!\n", system_opt.startup_time);

    return 0;
}