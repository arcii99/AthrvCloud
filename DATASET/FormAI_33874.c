//FormAI DATASET v1.0 Category: Color Code Converter ; Style: artistic
#include <stdio.h>

int main(){
  int r,g,b;
  printf("Enter the RGB values (0-255): "); //inputting RGB values
  scanf("%d%d%d",&r,&g,&b);

  //converting RGB to HEX
  int hexValue[6], i=0;
  while(r>0 || g>0 || b>0){
    hexValue[i++] = (r%16 < 10)? (r%16 + '0') : (r%16-10 + 'A');
    hexValue[i++] = (g%16 < 10)? (g%16 + '0') : (g%16-10 + 'A');
    hexValue[i++] = (b%16 < 10)? (b%16 + '0') : (b%16-10 + 'A');
    r /= 16; g /= 16; b /= 16;
  }

  //printing HEX code
  printf("The HEX code is: #");
  for(int j=i-1; j>=0; j--)
    printf("%c",hexValue[j]);
  printf("\n");

  //converting RGB to CMYK
  float r1 = r/255.0, g1 =g/255.0, b1 =b/255.0;
  float c, m, y, k;
  k = 1 - fmax(fmax(r1,g1),b1);
  c = (1 - r1 - k)/(1-k);
  m = (1 - g1 - k)/(1-k);
  y = (1 - b1 - k)/(1-k);

  //printing CMYK values
  printf("The CMYK values are: C=%.2f M=%.2f Y=%.2f K=%.2f",c,m,y,k);
  
  return 0; //end of program
}