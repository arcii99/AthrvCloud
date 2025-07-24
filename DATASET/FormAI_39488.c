//FormAI DATASET v1.0 Category: Movie Rating System ; Style: romantic
#include<stdio.h>
#include<stdlib.h>

int main(){
int i, j, rating[5][5], total[5], max = 0, maxIndex = 0;
char romanceMovies[5][20] = {"The Notebook", "A Walk to Remember", "The Fault in Our Stars", "The Vow", "To All the Boys I've Loved Before"};

printf("Welcome to the Romantic Movie Rating System!\n\n");
for(i=0; i<5; i++){
  printf("Please rate %s on a scale of 1-10:\n", romanceMovies[i]);
  for(j=0; j<5; j++){
    printf("Rating %d: ", j+1);
    scanf("%d", &rating[i][j]);
    if(rating[i][j] < 1 || rating[i][j] > 10){
      printf("\nSorry, that is not a valid rating. Please enter a number between 1-10.\n");
      j--;
    }
  }
}

//calculate and display average ratings for each movie
printf("\nThank you for rating all 5 romantic movies! Here are the average ratings for each movie:\n");
for(i=0; i<5; i++){
  total[i] = 0;
  for(j=0; j<5; j++){
    total[i] += rating[i][j];
  }
  float average = (float)total[i] / 5;
  printf("%s: %.1f\n", romanceMovies[i], average);
  if(average > max){
    max = average;
    maxIndex = i;
  }
}

//display the highest rated movie 
printf("\nThe highest rated romantic movie is %s with an average rating of %.1f!\n", romanceMovies[maxIndex], max);

return 0;
}