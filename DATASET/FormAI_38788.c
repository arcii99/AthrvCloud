//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Cyberpunk
#include<stdio.h>

int main(){
  int rating;
  
  printf("Welcome to the Cyberpunk Movie Rating System!\n");
  printf("Please rate the following movie out of 10:\n");
  printf("Blade Runner 2049: ");
  scanf("%d", &rating);
  
  if(rating >= 8){
    printf("Wow! You have excellent taste! Blade Runner 2049 is a cyberpunk masterpiece!\n");
  }else if(rating >= 6 && rating < 8){
    printf("Not bad! Blade Runner 2049 is a solid cyberpunk movie with stunning visuals.\n");
  }else if(rating >= 4 && rating < 6){
    printf("Hmm.. seems like you're not a big fan of cyberpunk. Maybe go watch a rom-com instead?\n");
  }else{
    printf("Yikes, looks like you didn't enjoy the dark, gritty world of cyberpunk. Better stick to Disney movies!\n");
  }
  
  return 0;
}