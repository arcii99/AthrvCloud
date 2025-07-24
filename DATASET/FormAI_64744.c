//FormAI DATASET v1.0 Category: Temperature monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
   FILE *fp;
   char buff[255];
   float temp;

   while (1) {
      fp = fopen("/sys/class/thermal/thermal_zone0/temp", "r");
      if (fp == NULL) {
         printf("Failed to open thermal_zone0/temp.");
         exit(1);
      }
      fgets(buff, 255, fp);
      temp = atoi(buff) / 1000.0;
      printf("Current CPU Temperature: %.1f℃\n", temp);
      fclose(fp);
      sleep(1);
   }
   return 0;
}