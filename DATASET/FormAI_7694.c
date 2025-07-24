//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

// function to parse the first integer from a string and return it
int parse_int(char* str) {
    int num = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (isdigit(str[i])) {
            num = num * 10 + (str[i] - '0');
        }
    }
    return num;
}

int main(int argc, char* argv[]) {
    int interval = 1; // default interval between measurements is 1 second
    if (argc > 1) {
        interval = parse_int(argv[1]);
    }

    while (1) {
        FILE* fp = popen("free | grep Mem | awk '{print $3/$2 * 100.0}'", "r"); // execute command to get RAM usage percentage
        if (fp == NULL) {
            printf("Failed to execute command\n");
            exit(1);
        }

        char output[10];
        fgets(output, sizeof(output), fp); // read output from command into buffer
        pclose(fp);

        float ram_usage = atof(output); // convert output to float
        printf("Memory usage: %.2f%%\n", ram_usage);

        sleep(interval); // sleep for specified interval before taking next measurement
    }

    return 0;
}