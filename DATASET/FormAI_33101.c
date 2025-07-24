//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
   char url[100];
   int speed=0;
   printf("Enter the URL to test speed:\n");
   scanf("%s", url);
   printf("Testing speed of %s\n", url);

   // Ping the server to determine latency
   char pingCmd[100];
   sprintf(pingCmd, "ping -c 1 %s | grep 'round-trip' | awk '{print $4}'", url);
   FILE* pingResult = popen(pingCmd, "r");
   char pingOutput[10];
   fgets(pingOutput, 10, pingResult);
   pclose(pingResult);
   int latency = atoi(pingOutput);

   if (latency > 0) {
      printf("Latency: %d ms\n", latency);

      // Measure download speed by downloading a known file
      char downloadCmd[200];
      char* downloadUrl = "https://download.thinkbroadband.com/10MB.zip";
      sprintf(downloadCmd, "curl -o /dev/null --silent --head --write-out '%%{speed_download}\\n' %s", downloadUrl);
      FILE* downloadResult = popen(downloadCmd, "r");
      char downloadOutput[10];
      fgets(downloadOutput, 50, downloadResult);
      pclose(downloadResult);
      speed = atoi(downloadOutput) / 1000; // Convert from bytes/s to kilobytes/s
   }
   else {
      printf("Unable to connect to %s\n", url);
   }
   
   printf("Download Speed: %d Mbps\n", speed);
   
   return 0;
}