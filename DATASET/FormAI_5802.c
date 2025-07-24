//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: excited
#include<stdio.h>
#include<math.h>

int main()
{
   int signal_strength;
   
   printf("Enter the signal strength (in dBm): "); 
   scanf("%d",&signal_strength);

   if(signal_strength >= -30)
   {
      printf("Excellent Signal Strength. You are in a close proximity of the access point.\n");
   }
   else if(signal_strength >= -67)
   {
      printf("Good Signal Strength. You can stream videos and do online gaming without any buffering issues.\n");
   }
   else if(signal_strength >= -70)
   {
      printf("Fair Signal Strength. You can browse the internet but the speed may vary.\n");
   }
   else if(signal_strength >= -80)
   {
      printf("Poor Signal Strength. You may face difficulty in browsing the internet.\n");
   }
   else if(signal_strength >= -100)
   {
      printf("No Signal Strength. You are out of the coverage area.\n");
   }
   else
   {
      printf("Invalid Input. Please enter a valid signal strength (in dBm). \n");
   }

   return 0;
}