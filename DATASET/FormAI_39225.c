//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: irregular
#include <stdio.h>

int main() {
   FILE *fp;
   char buffer[1024];
   char *token;

   fp = fopen("data.csv", "r");

   while (fgets(buffer, 1024, fp)) {
      token = strtok(buffer, ",");
      while (token != NULL) {
         printf("%s\n", token);
         token = strtok(NULL, ",");
      }
   }

   fclose(fp);
   return 0;
}