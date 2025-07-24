//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int pid = getpid();
    char command[50];
    sprintf(command, "ps -p %d -o %%mem | awk '{print $1}'", pid);
    int interval = 1;
    if (argc > 1) {
        interval = atoi(argv[1]);
    }
    while (1) {
        FILE *fp;
        fp = popen(command, "r");
        char result[10];
        fgets(result, sizeof(result), fp);
        printf("C RAM usage: %s", result);
        pclose(fp);
        sleep(interval);
    }
    return 0;
}