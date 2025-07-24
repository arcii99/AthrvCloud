//FormAI DATASET v1.0 Category: Math exercise ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

//Function to print fancy borders for the output
void printBorder(int n, char c){
  printf("\n");
  for(int i=0; i<n; i++){
    printf("%c",c);
  }
  printf("\n");
}

int main(){
  srand(time(0));       //Seed for random numbers

  //Fancy Borders
  printBorder(50,'*');
  printf("          Challenge: Math Magic Squares         ");
  printBorder(50,'*');

  //User Input
  int size; 
  printf("\nEnter the size of the magic square (3,5,7,9,11): ");
  scanf("%d",&size);
  printf("\n");

  // Magic Square Algorithm: n is the size of the square, 
  //magic[n][n] is the resulting magic square
  int magic[size][size];
  int count = 1;
  int row = 0;
  int col = (size-1)/2;
  magic[row][col] = count;
 
  while (count < size*size){
    if (magic[(row-1+size)%size][(col+1)%size] == 0){
      row = (row-1+size)%size;
      col = (col+1)%size;
    }else{
      row = (row+1)%size;
    }
    count++;
    magic[row][col] = count;
  }

  //Display Magic Square
  printBorder(50,'*');
  printf("\n Magic Square of Size %d: \n",size);
  for(int i=0; i<size; i++){
    printf(" * ");
    for(int j=0; j<size; j++){
      printf("%d ",magic[i][j]);
    }
    printf(" * \n");
  }
  printBorder(50,'*');

  //Calculations
  int row_sum = 0;
  int col_sum = 0;
  int diag_sum1 = 0;
  int diag_sum2 = 0;

  //Sum of rows
  for(int i=0; i<size; i++){
    row_sum += magic[0][i];
  }

  //Sum of columns
  for(int i=0; i<size; i++){
    col_sum += magic[i][0];
  }

  //Sum of diagonal 1 (top-left to bottom-right)
  for(int i=0; i<size; i++){
    diag_sum1 += magic[i][i];
  }

  //Sum of diagonal 2 (top-right to bottom-left)
  for(int i=0; i<size; i++){
    diag_sum2 += magic[i][size-1-i];
  }

  //Print Results
  printf("\n\n Results: \n");
  printf(" Row Sum: %d \n Column Sum: %d \n Diagonal Sum 1: %d \n Diagonal Sum 2: %d \n\n",row_sum,col_sum,diag_sum1,diag_sum2);
  printBorder(50,'*');

  //Artistic Conclusion
  int random_num = rand()%5;   //Random Number between 0 and 4

  if(random_num == 0){
    printf("\n\n You have unlocked the secret of the universe! \n\n");
  }else if(random_num == 1){
    printf("\n\n Congratulations! You have found the hidden treasure! \n\n");
  }else if(random_num == 2){
    printf("\n\n You are a math genius! \n\n");
  }else if(random_num == 3){
    printf("\n\n Your skill in Math is unparalleled! \n\n");
  }else{
    printf("\n\n You have proven that you are the master of Math! \n\n");
  }

  return 0;
}