//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: intelligent
#include<stdio.h>    
#include<math.h>    
#define PI 3.14159265    
   
void RC_CircuitSimulator(double Vc, double I, double R, double C, double t) {  
   double V;  
   V = Vc * (exp(-t/(R*C)));    
   I = Vc/R;  
    
   printf("\nI = %lf Amperes\nV = %lf Volts", I, V);
}    
   
int main() {    
    double Vc, I, R, C, t;    
    printf("Enter value of initial voltage: ");    
    scanf("%lf", &Vc);    
    printf("\nEnter value of Resistance in Ohms: ");    
    scanf("%lf", &R);    
    printf("\nEnter value of capacitance in Farads: ");    
    scanf("%lf", &C);    
    printf("\nEnter value of time in seconds: ");    
    scanf("%lf", &t);    
    RC_CircuitSimulator(Vc, I, R, C, t);    
    return 0;    
}