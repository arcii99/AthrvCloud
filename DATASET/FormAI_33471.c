//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sysinfo.h>

int main() {
    struct sysinfo si;
    while(1) {
        sysinfo(&si);

        double used_mem = ((double) (si.totalram - si.freeram) / si.totalram) * 100;
        printf("RAM usage: %.2f%%\n", used_mem);

        FILE* fileptr;
        char* buffer;
        long filelen;

        fileptr = fopen("/proc/meminfo", "r");  // Reading memory info from /proc/meminfo
        fseek(fileptr, 0, SEEK_END);
        filelen = ftell(fileptr);
        rewind(fileptr);

        buffer = (char *) malloc((filelen + 1));  // Creating a buffer to read the file
        fread(buffer, filelen, 1, fileptr);
        fclose(fileptr);
        buffer[filelen] = '\0';

        printf("\nMemory information:\n\n%s", buffer);

        free(buffer);
        sleep(1);
        system("clear");  // Clearing the terminal screen for readability
    }

    return 0;
}