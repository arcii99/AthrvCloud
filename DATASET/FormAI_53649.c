//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int kb_conversion = 1024;

void print_ram_usage(long rss) {
    printf("RAM usage: %ld KB\n", rss / kb_conversion);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <monitoring interval in seconds>\n", argv[0]);
        exit(1);
    }

    int monitoring_interval = atoi(argv[1]);
    long last_rss = 0;

    while (1) {
        FILE *fp;
        char buffer[1024];
        long rss;

        fp = fopen("/proc/self/statm", "r");
        fgets(buffer, 1024, fp);
        fclose(fp);

        sscanf(buffer, "%ld", &rss);

        if (last_rss != 0) {
            long diff = rss - last_rss;
            print_ram_usage(diff * kb_conversion);
        }

        last_rss = rss;
        sleep(monitoring_interval);
    }

    return 0;
}