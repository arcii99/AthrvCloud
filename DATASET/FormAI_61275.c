//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>

#define BUFFER_SIZE 512

void print_memory_usage(){
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    printf("\nMemory usage statistics:\n");
    printf("Resident set size: %ld MB\n", usage.ru_maxrss / 1024);
    printf("Soft page faults: %ld\n", usage.ru_minflt);
    printf("Hard page faults: %ld\n", usage.ru_majflt);
    printf("Page reclaims: %ld\n", usage.ru_minflt - usage.ru_majflt);
    printf("Swaps: %ld\n", usage.ru_nswap);
}

int main(int argc, char *argv[]){
    while(1){
        char buffer[BUFFER_SIZE];
        printf("Enter a command: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        if(strcmp(buffer, "exit\n") == 0){
            printf("Exiting program...\n");
            exit(0);
        }
        else if(strcmp(buffer, "help\n") == 0){
            printf("Commands:\n");
            printf("\thelp - display this help message\n");
            printf("\texit - exit the program\n");
            printf("\tstats - display memory usage statistics\n");
        }
        else if(strcmp(buffer, "stats\n") == 0){
            print_memory_usage();
        }
        else{
            printf("Unknown command, type 'help' for a list of commands.\n");
        }
    }
    return 0;
}