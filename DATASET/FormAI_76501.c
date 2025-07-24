//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PROC_MEMINFO_FILE "/proc/meminfo"

int get_total_ram_kb() {
    FILE *fp;
    char line[100], *p;
    long long ram_kb;

    fp = fopen(PROC_MEMINFO_FILE, "r");
    while(fgets(line, 100, fp)) {
        if(strncmp(line, "MemTotal:", 9) == 0) {
            p = strtok(line, " ");
            p = strtok(NULL, " ");
            ram_kb = atoll(p);
            break;
        }
    }
    fclose(fp);

    return ram_kb;
}

int get_free_ram_kb() {
    FILE *fp;
    char line[100], *p;
    long long free_ram_kb;

    fp = fopen(PROC_MEMINFO_FILE, "r");
    while(fgets(line, 100, fp)) {
        if(strncmp(line, "MemFree:", 8) == 0) {
            p = strtok(line, " ");
            p = strtok(NULL, " ");
            free_ram_kb = atoll(p);
            break;
        }
    }
    fclose(fp);

    return free_ram_kb;
}

int get_used_ram_percent() {
    int total_ram_kb = get_total_ram_kb();
    int free_ram_kb = get_free_ram_kb();
    int used_ram_kb = total_ram_kb - free_ram_kb;
    float used_ram_percent = (float)used_ram_kb / total_ram_kb * 100;

    return (int)used_ram_percent;
}

int main() {
    int used_ram_percent = get_used_ram_percent();
    printf("Currently using %d%% of RAM\n", used_ram_percent);

    return 0;
}