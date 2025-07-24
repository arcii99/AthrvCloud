//FormAI DATASET v1.0 Category: Unit converter ; Style: statistical
#include <stdio.h>

int main() {
  
  // Variable Declaration
  float input;
  char source[50], target[50];
  
  // Menu
  printf("*** Statistical Unit Converter ***\n");
  printf("Enter the number you want to convert: ");
  scanf("%f", &input);
  printf("\nPlease enter the source unit: ");
  scanf("%s", source);
  printf("\nPlease enter the target unit: ");
  scanf("%s", target);
  
  // Conditional Statements
  if(strcmp(source,"km")==0 && strcmp(target,"m")==0) {
    input *= 1000;
  }
  else if(strcmp(source,"m")==0 && strcmp(target,"km")==0) {
    input /= 1000;
  }
  else if(strcmp(source,"kg")==0 && strcmp(target,"g")==0) {
    input *= 1000;
  }
  else if(strcmp(source,"g")==0 && strcmp(target,"kg")==0) {
    input /= 1000;
  }
  else if(strcmp(source,"cm")==0 && strcmp(target,"m")==0) {
    input /= 100;
  }
  else if(strcmp(source,"m")==0 && strcmp(target,"cm")==0) {
    input *= 100;
  }
  else if(strcmp(source,"C")==0 && strcmp(target,"F")==0) {
    input = (input*1.8) + 32;
  }
  else if(strcmp(source,"F")==0 && strcmp(target,"C")==0) {
    input = (input-32) * (5.0/9.0);
  }
  
  // Output
  printf("\nConverted value: %.2f %s\n", input, target);
 
  return 0;
}