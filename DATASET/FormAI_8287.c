//FormAI DATASET v1.0 Category: Digital signal processing ; Style: genious
#include<stdio.h>

//Function to square a number
float square(float num){
   return num*num;
}

int main(){
   int size, i;
   float signal[100], magnitude[100];
   
   //Ask user for signal size
   printf("Enter the size of signal: ");
   scanf("%d", &size);
   
   //Ask user to enter the signal
   for(i=0; i<size; i++){
      printf("Enter signal reading %d: ",i+1);
      scanf("%f", &signal[i]);
   }
   
   //Calculate magnitude spectrum
   for(i=0; i<size; i++){
      magnitude[i] = square(signal[i]);
   }
   
   //Print magnitude spectrum
   printf("\nMagnitude Spectrum:\n");
   for(i=0; i<size; i++){
      printf("%.2f\n", magnitude[i]);
   }
   
   //Apply low-pass filter
   for(i=0; i<size; i++){
      if(i<20 || i>80){
         magnitude[i] = 0;
      }
   }
   
   //Print filtered magnitude spectrum
   printf("\nFiltered Magnitude Spectrum:\n");
   for(i=0; i<size; i++){
      printf("%.2f\n", magnitude[i]);
   }
   
   return 0;
}