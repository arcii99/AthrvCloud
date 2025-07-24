//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
   int i;
   FILE *fp;
   char path[1035];

   while(1) {
      fp = popen("free -m | awk 'NR==2{printf \"%s/%sMB (%.2f%%)\", $3,$2,$3*100/$2 }'", "r");
      if (fp == NULL) {
         printf("Failed to run command\n" );
         exit(1);
      }
      fgets(path, sizeof(path)-1, fp);
      printf("%s\n", path );
      pclose(fp);
      sleep(1);
   }
   return 0;
}