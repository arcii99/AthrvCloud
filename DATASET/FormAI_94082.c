//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
  int i;
  double a[4], b[4], loadavg;
  FILE *fp;

  for (i = 0; i < 3; i++) {
    fp = fopen("/proc/stat", "r");
    fscanf(fp, "%*s %lf %lf %lf %lf", &a[0], &a[1], &a[2], &a[3]);
    fclose(fp);
    sleep(1);
    fp = fopen("/proc/stat", "r");
    fscanf(fp, "%*s %lf %lf %lf %lf", &b[0], &b[1], &b[2], &b[3]);
    fclose(fp);

    loadavg = ((b[0]+b[1]+b[2]) - (a[0]+a[1]+a[2])) / ((b[0]+b[1]+b[2]+b[3]) - (a[0]+a[1]+a[2]+a[3]));
    printf("Current CPU usage: %lf%%\n", loadavg*100);
  }

  return EXIT_SUCCESS;
}