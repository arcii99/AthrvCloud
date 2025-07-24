//FormAI DATASET v1.0 Category: System event logger ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   char* event[] = {"Startup", "Shutdown", "Login", "Logout", "File Changed", "User Created", "User Deleted", "Packet Received", "Packet Dropped"};
   srand(time(NULL));
   int count = 10;
   printf("Enter the number of events to log: ");
   scanf("%d", &count);
   for(int i=0; i<count; i++) {
      int rand_event = rand() % 9;
      printf("Logging event: %s\n", event[rand_event]);
   }
   return 0;
}