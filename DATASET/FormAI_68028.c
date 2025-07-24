//FormAI DATASET v1.0 Category: Firewall ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   int i,j,k,flag=0,n=0,m=0;
   char input[500];
   char firewall[50][50];
   
   // Initialize the firewall table to all zeros
   for(i=0; i<50; i++){
      for(j=0; j<50; j++){
         firewall[i][j] = '0';
      }
   }
   
   // Get the number of allowed IPs
   printf("Enter the number of allowed IPs (maximum 50): ");
   scanf("%d", &n);
   
   // Get the allowed IPs and add them to the firewall table
   for(i=0; i<n; i++){
      printf("Enter allowed IP %d (format: x.x.x.x): ", i+1);
      scanf("%s", input);
      m = strlen(input);
      k = 0;
      
      for(j=0; j<4; j++){
         if(input[k]>='0' && input[k]<='9'){
            firewall[i][j] = input[k];
            k++;
            if(input[k]>='0' && input[k]<='9'){
               firewall[i][j] = firewall[i][j]*10 + input[k];
               k++;
               if(input[k] == '.'){
                  k++;
                  continue;
               }
            }
            else if(input[k] == '.'){
               k++;
               continue;
            }
         }
         else{
            printf("Invalid input format!\n");
            flag = 1;
            break;
         }
      }
      if(flag == 1){
         break;
      }
   }
   
   // If the number of allowed IPs is less than 50, fill the rest of the table with 0s
   for(i=n; i<50; i++){
      for(j=0; j<4; j++){
         firewall[i][j] = '0';
      }
   }
   
   // Print out the firewall table
   printf("\nFirewall Table:\n");
   for(i=0; i<50; i++){
      for(j=0; j<4; j++){
         printf("%c", firewall[i][j]);
         if(j!=3){
            printf(".");
         }
      }
      printf("\n");
   }
   
   // Get the IP address to check
   printf("\nEnter an IP address to check (format: x.x.x.x): ");
   scanf("%s", input);
   m = strlen(input);
   k = 0;
   
   // Check the IP address against the firewall table
   for(i=0; i<50; i++){
      flag = 0;
      for(j=0; j<4; j++){
         if(input[k]>='0' && input[k]<='9'){
            if(firewall[i][j] == (input[k]-'0')){
               k++;
               if(input[k]>='0' && input[k]<='9'){
                  if(firewall[i][j]*10 + (input[k]-'0') > 255){
                     flag = 1;
                     break;
                  }
                  k++;
                  if(input[k] == '.'){
                     k++;
                     continue;
                  }
               }
               else if(input[k] == '.'){
                  k++;
                  continue;
               }
            }
            else{
               flag = 1;
               break;
            }
         }
         else{
            flag = 1;
            break;
         }
      }
      if(flag == 0){
         printf("IP address is allowed\n");
         break;
      }
   }
   if(flag == 1){
      printf("IP address is not allowed\n");
   }
   
   return 0;
}