//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: decentralized
#include<stdio.h>

int main() {
  char str[100];
  printf("Enter a string: ");
  scanf("%s", str);
  
  int i, j, k;
  for(i=0; i<strlen(str); i++) {
    int n = str[i];
    
    // Print the ASCII art of the character
    for(j=0; j<9; j++) {
      for(k=0; k<7; k++) {
        if((j==0 && k==3) || (j==1 && (k==2||k==4)) || (j==2 && (k==1||k==5)) || (j==3 && (k==0||k==6)) || (j==4 && (k==0||k==6)) || (j==5 && (k==1||k==5)) || (j==6 && (k==2||k==4)) || (j==7 && k==3) || (j==8 && k==2)) {
          printf("%c", n);
        } else {
          printf(" ");
        }
      }
      printf("\n");
    }
    printf("\n");
  }

  return 0;
}