//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Ada Lovelace
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/sysinfo.h>

void print_header() {
    printf("=====================================================================\n");
    printf("=                          RAM Usage Monitor                        =\n");
    printf("=====================================================================\n");
}

void print_system_details() {
    time_t now = time(NULL);
    printf("Report generated at: %s", ctime(&now));

    struct sysinfo info;
    sysinfo(&info);
    printf("Total RAM: %ld KB\n", info.totalram / 1024);
    printf("Free RAM: %ld KB\n", info.freeram / 1024);
}

void print_footer() {
    printf("=================================END================================\n");
}

int main() {
    print_header();
    print_system_details();
    print_footer();
    return 0;
}