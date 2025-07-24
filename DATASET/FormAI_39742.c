//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Linus Torvalds
#include <stdio.h>
#include <sys/statvfs.h>

int main(int argc, char **argv) {
    struct statvfs st;
    if (argc != 2) {
        printf("Usage: %s <disk>\n", argv[0]);
        return 1;
    }
    if (statvfs(argv[1], &st) == -1) {
        perror("statvfs");
        return 1;
    }
    printf("Total space: %.2f GB\n", (double)st.f_blocks * st.f_bsize / (1024 * 1024 * 1024));
    printf("Free space: %.2f GB\n", (double)st.f_bfree * st.f_bsize / (1024 * 1024 * 1024));
    printf("Used space: %.2f GB\n", (double)(st.f_blocks - st.f_bfree) * st.f_bsize / (1024 * 1024 * 1024));
    printf("Usage: %.2f%%\n", (double)(st.f_blocks - st.f_bfree) / st.f_blocks * 100);
    return 0;
}