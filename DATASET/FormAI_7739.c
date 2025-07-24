//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  printf("Oh my goodness, what is happening to my CPU!\n");
  printf("I need to monitor my CPU usage immediately.\n");

  long double a[32000], b[32000], loadavg;
  FILE *fp;

  while (1) {
    fp = fopen("/proc/stat","r");
    fscanf(fp,"%*s %Lf %Lf %Lf %Lf",&a[0],&a[1],&a[2],&a[3]);
    fclose(fp);
    sleep(1);
    fp = fopen("/proc/stat","r");
    fscanf(fp,"%*s %Lf %Lf %Lf %Lf",&b[0],&b[1],&b[2],&b[3]);
    fclose(fp);

    loadavg = ((b[0]+b[1]+b[2])-(a[0]+a[1]+a[2]))/((b[0]+b[1]+b[2]+b[3])-(a[0]+a[1]+a[2]+a[3])) * 100;

    if (loadavg >= 90) {
      printf("Oh no! CPU usage is too high: %.2Lf%%\n", loadavg);
    } else {
      printf("Phew, CPU usage is normal: %.2Lf%%\n", loadavg);
    }
  }

  return 0;
}