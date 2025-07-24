//FormAI DATASET v1.0 Category: Data mining ; Style: paranoid
#include<stdio.h> 

int main(){ 
   
   int data[] = {2, 6, 9, 11, 13, 15, 18, 22, 25, 29, 30}; 
   int size = sizeof(data)/sizeof(data[0]); 
  
   int i, j, mean, deviation, threshold; 
  
   mean = 0; 
  
   for(i=0; i<size; i++){ 
      mean += data[i]; 
   } 
   
   mean /= size; 
  
   deviation = 0; 
  
   for(i=0; i<size; i++){ 
      deviation += (data[i]-mean)*(data[i]-mean); 
   } 
   
   deviation /= size; 
  
   threshold = mean - deviation; 
  
   int outliers[size]; 
   int k = 0; 
  
   for(i=0; i<size; i++){ 
      if(data[i] < threshold){ 
         outliers[k] = data[i]; 
         k++; 
      } 
   } 
  
   printf("Outliers found: "); 
  
   for(i=0; i<k; i++){ 
      printf("%d ", outliers[i]); 
   } 
  
   return 0; 
}