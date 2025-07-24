//FormAI DATASET v1.0 Category: Pattern printing ; Style: surprised
#include<stdio.h>
int main(){
  int n,i,j,k;
  printf("How big do you want your C pattern to be? ");
  scanf("%d",&n);
  printf("\n");
  if(n<=0){
    printf("Invalid input. C pattern cannot be generated. Please try again.");
    return 0;
  }
  for(i=1;i<=n;i++){
    printf("*");
    if(i==1 || i==n){ //printing the upper and lower edge of the C
      for(j=1;j<n-1;j++)
        printf("*");
    }
    else{
      for(k=2;k<=n;k++){
        if(k==i) //printing the vertical line of the C
          printf("*");
        else
          printf(" ");
      }
    }
    printf("\n");
  }
  printf("\nC pattern generated successfully! We hope you're surprised!");
  return 0;
}