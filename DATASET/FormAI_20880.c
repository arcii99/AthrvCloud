//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: complete
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int main() { 
   int start,end; // Define variables to hold start and end time
   int s, e, time_elapsed; // Define variables to hold start and end speed and time elapsed
   float speed; // Define variable to hold speed
   printf("Welcome to the Internet Speed Tester\n"); 
   printf("Press 'Enter' to begin the test\n"); 
   getchar(); // Wait for user to press enter

   printf("\nTesting download speed...\n"); 
   start = time(NULL); // Record start time
   // Generate random download speed between 1-10 Mbps
   s = rand() % (10 - 1 + 1) + 1; 
   end = time(NULL); // Record end time
   time_elapsed = end - start; // Calculate time elapsed
   printf("Download speed: %d Mbps\n", s); 
   printf("Time taken: %d seconds\n", time_elapsed); 

   printf("\nTesting upload speed...\n"); 
   start = time(NULL); // Record start time
   // Generate random upload speed between 1-5 Mbps
   e = rand() % (5 - 1 + 1) + 1; 
   end = time(NULL); // Record end time
   time_elapsed = end - start; // Calculate time elapsed
   printf("Upload speed: %d Mbps\n", e); 
   printf("Time taken: %d seconds\n", time_elapsed); 

   // Calculate average speed
   speed = (float)(s + e) / 2; 
   printf("\nAverage internet speed: %.2f Mbps\n", speed); 

   return 0; 
}