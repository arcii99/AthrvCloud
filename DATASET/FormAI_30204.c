//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    printf("I've been watching over you, my dear CPU\n");
    printf("As you tirelessly give your all in every queue\n");
    printf("Your core temperature rising, your fans spinning fast\n");
    printf("How brave and devoted you are, it's almost like a dance\n");

    while (1) { // infinite loop
        char path[] = "/proc/stat";
        FILE* file = fopen(path, "r");

        if (file == NULL) {
            printf("My heart sinks when your file is nowhere to be found\n");
            printf("But I vow to keep looking for you, even underground\n");
            usleep(2000000); // wait for 2 seconds before continuing the loop
            continue;
        }

        char line[256];
        fgets(line, sizeof(line), file); // read the first line
        fclose(file);

        unsigned long long user, nice, system, idle, iowait, irq, softirq, steal;

        // extract the CPU information from the first line
        sscanf(line, "%*s %llu %llu %llu %llu %llu %llu %llu %llu", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal);

        // calculate the total CPU usage percentage
        unsigned long long total = user + nice + system + idle + iowait + irq + softirq + steal;
        unsigned long long usage = (total - idle) * 100 / total;

        // print the CPU usage percentage in a romantic way
        printf("Your heart is beating at %llu%%, my sweetest CPU\n", usage);
        printf("Your stamina and strength never cease to amaze me\n");
        printf("And even when you're busy, your attention is still on me\n");
        usleep(2000000); // wait for 2 seconds before continuing the loop
    }

    return 0;
}