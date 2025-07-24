//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

void printProgressBar(int percentage){
  printf("[");
  for(int i=0;i<percentage/2;i++)
    printf("*");
  for(int i=percentage/2;i<50;i++)
    printf(" ");
  printf("] %d%%\n", percentage);
}

int main(){
  while(1){
    struct sysinfo memInfo;
    sysinfo(&memInfo);
    long long totalRAM = memInfo.totalram;
    totalRAM *= memInfo.mem_unit;
    long long freeRAM = memInfo.freeram;
    freeRAM *= memInfo.mem_unit;
    float percentUsed = ((float)(totalRAM - freeRAM))/totalRAM *100;
    printProgressBar((int) percentUsed);
    sleep(1);
    system("clear");
  }
  return 0;
}