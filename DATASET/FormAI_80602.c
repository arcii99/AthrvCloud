//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
   printf("CPU Usage Monitor\n");
   while(1) {
      system("ps -o %cpu -p <process id>");
      sleep(1);
   }
   return 0;
}