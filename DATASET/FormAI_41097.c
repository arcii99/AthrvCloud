//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct accessPoint{
   char ssid[50];
   float signalStrength;
};

int main(){
   int num_ap,i;
   printf("Enter number of access points to analyze: ");
   scanf("%d",&num_ap);
   struct accessPoint ap[num_ap];
   
   for(i=0;i<num_ap;i++){
      printf("\nEnter SSID for access point %d: ",i+1);
      scanf("%s",ap[i].ssid);
      printf("Enter signal strength (in dBm) for access point %d: ",i+1);
      scanf("%f",&ap[i].signalStrength);
   }

   printf("\nAccess points in order of signal strength:\n");
   //Sorting the access points based on signal strength
   for(i=0;i<num_ap;i++){
      int j;
      for(j=0;j<num_ap-i-1;j++){
         if(ap[j].signalStrength<ap[j+1].signalStrength){
            struct accessPoint temp = ap[j];
            ap[j] = ap[j+1];
            ap[j+1] = temp;
         }
      }
   }
   //Displaying the sorted list of access points
   for(i=0;i<num_ap;i++){
      printf("%d. SSID: %s | Signal Strength: %.1f dBm\n",i+1,ap[i].ssid,ap[i].signalStrength);
   }
   return 0;
}