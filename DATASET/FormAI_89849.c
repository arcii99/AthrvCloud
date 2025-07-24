//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void printRAMUsage(int n){

    if(n == 0)  // base case
        return;

    char cmd[50];   // command to get RAM usage
    sprintf(cmd, "ps -o pid,ppid,rss,vsz,cmd | grep %d", getpid());
    FILE* fp = popen(cmd, "r"); // execute command and get file pointer

    if(fp == NULL){
        printf("Error in executing command!\n");
        exit(1);
    }

    char result[100];   // buffer to store output of command

    while(fgets(result, sizeof(result), fp)){    // read output of command line by line
        printf("%d \t %s", n, result);
    }

    pclose(fp);

    sleep(1);   // wait for 1 second before printing next RAM usage status

    printRAMUsage(n-1); // call function recursively with reducing counter
}

int main(){

    int n = 10; // number of times to print RAM usage
    printf("Printing %d RAM usages...\n", n);
    printRAMUsage(n);

    return 0;
}