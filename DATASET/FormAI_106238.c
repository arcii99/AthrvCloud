//FormAI DATASET v1.0 Category: Math exercise ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
  float a,b,c,disc,root1,root2,realPart,imagPart;
  printf("Enter the coefficients of Quadratic Equation (a, b, c) :\n");
  scanf("%f%f%f",&a,&b,&c);
  if(a==0 && b==0 && c==0){
      printf("Indeterminate (all coefficients are equal to zero)\n");
      return 0;
  }
  if(a==0 && b==0){
    printf("Cannot find root, linear equation is not a quadratic equation\n");
    return 0;
  }
  if(a==0){
    printf("Cannot find root, it is not a quadratic equation\n");
    return 0;  
  }
  disc=b*b-4*a*c;
  if(disc>0){
    root1=(-b+sqrt(disc))/2*a;
    root2=(-b-sqrt(disc))/2*a;
    printf("Root1 : %.2f \nRoot2 : %.2f\n",root1,root2);
  }
  else if(disc==0){
    root1=root2=-b/(2*a);
    printf("Root1 : Root2 : %.2f\n",root1);  
  }
  else{
    realPart=-b/(2*a);
    imagPart=sqrt(-disc)/(2*a);
    printf("Root1 : %.2f + %.2fi\nRoot2 : %.2f - %.2fi\n",realPart,imagPart,realPart,imagPart);
  }
  return 0;
}