//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct disk_space {
    long long total_space;
    long long used_space;
    long long free_space;
};

struct disk_space get_disk_space() {
    struct disk_space space;
    FILE *f = popen("df -P / | tail -1", "r");
    char buff[255];
    fgets(buff, 255, f);
    sscanf(buff, "%*s %lld %lld %lld", &space.total_space, &space.used_space, &space.free_space);
    pclose(f);
    return space;
}

void print_space_information(struct disk_space space) {
    float used_percent = ((float)space.used_space / space.total_space) * 100;
    float free_percent = ((float)space.free_space / space.total_space) * 100;
    printf("Total Disk Space: %lld GB\n", space.total_space / 1024 / 1024);
    printf("Used Disk Space: %lld GB (%.2f%%)\n", space.used_space / 1024 / 1024, used_percent);
    printf("Free Disk Space: %lld GB (%.2f%%)\n", space.free_space / 1024 / 1024, free_percent);
}

int main() {
    struct disk_space space = get_disk_space();
    print_space_information(space);
    return 0;
}