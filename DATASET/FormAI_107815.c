//FormAI DATASET v1.0 Category: Spam Detection System ; Style: irregular
#include<stdio.h>
#include<string.h>

int main() {
  char sentence[1000];
  int i,j=0,cnt=0;
  printf("Enter a sentence: \n");
  fgets(sentence,1000,stdin);
  for(i=0;i<strlen(sentence);i++) {
    if(sentence[i]=='c' || sentence[i]=='C') {
      if(sentence[i+1]==' ' || sentence[i+1]=='\n' || sentence[i+1]=='\t') {
        if(sentence[i-1]==' ' || i==0) {
          cnt++;
        }
      }
    }
    if(sentence[i]=='s' || sentence[i]=='S') {
      if(sentence[i+1]==' ' || sentence[i+1]=='\n' || sentence[i+1]=='\t') {
        if(sentence[i-1]==' ' || i==0) {
          cnt++;
        }
      }
    }
  }
  if(cnt>0) {
    printf("This sentence is likely spam.\n");
  }
  else {
    printf("This sentence is not spam.\n");
  }
  return 0;
}