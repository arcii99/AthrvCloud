//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
 
// Struct for storing circuit values
typedef struct circuit {
   int resistance;
   int voltage;
   int current;
} Circuit;
 
// Function to read circuit values from user
void readCircuit(Circuit *circ){
   printf("Enter Circuit Resistance: ");
   scanf("%d", &circ->resistance);
   printf("Enter Circuit Voltage: ");
   scanf("%d", &circ->voltage);
   circ->current = circ->voltage / circ->resistance;
}
 
// Function to print circuit values
void printCircuit(Circuit *circ){
   printf("Resistance: %d\n", circ->resistance);
   printf("Voltage: %d\n", circ->voltage);
   printf("Current: %d\n", circ->current);
}
 
// Main function
int main(){
   Circuit circ[MAX];
   int n, i;
 
   printf("Enter the number of circuits: ");
   scanf("%d", &n);
 
   // Read circuit values
   for(i=0; i<n; i++){
      readCircuit(&circ[i]);
   }
 
   // Print circuit values
   for(i=0; i<n; i++){
      printf("Circuit %d:\n", i+1);
      printCircuit(&circ[i]);
   }
 
   return 0;
}