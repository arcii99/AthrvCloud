//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define BUFFER_SIZE 128
void printProgress(float percentage)
{
    int pos = (int)(percentage * 1.2);
    printf("\r[");
    for (int i = 0; i < 12; ++i) {
        if (i < pos) printf("=");
        else if (i == pos) printf(">");
        else printf(" ");
    }
    printf("] %3.2f%%", percentage * 100);
    fflush(stdout);
}
int main()
{
    long double a[4], b[4], loadavg;
    int fd;
    char buf[BUFFER_SIZE], *tmp;
    memset(buf, 0, BUFFER_SIZE);
    fd = open("/proc/stat", O_RDONLY);
    read(fd, buf, BUFFER_SIZE - 1);
    tmp = buf;
    // Remove the first line
    tmp = strchr(tmp, '\n') + 1;
    // Get the cpu usages
    sscanf(tmp, "%Lf %Lf %Lf %Lf", &a[0], &a[1], &a[2], &a[3]);
    sleep(1);
    memset(buf, 0, BUFFER_SIZE);
    lseek(fd, 0, SEEK_SET);
    read(fd, buf, BUFFER_SIZE - 1);
    close(fd);
    tmp = buf;
    // Remove the first line
    tmp = strchr(tmp, '\n') + 1;
    // Get the cpu usages again
    sscanf(tmp, "%Lf %Lf %Lf %Lf", &b[0], &b[1], &b[2], &b[3]);
    loadavg = ((b[0] + b[1] + b[2]) - (a[0] + a[1] + a[2])) / ((b[0] + b[1] + b[2] + b[3]) - (a[0] + a[1] + a[2] + a[3]));
    printProgress(loadavg);
    return 0;
}