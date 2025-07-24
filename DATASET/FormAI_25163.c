//FormAI DATASET v1.0 Category: Educational ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>

int main(){

  // Shape 1: Basic Hello World Program
  printf("Hello World!\n\n");

  // Shape 2: Displaying Number 1 to 10 using while loop
  int i = 1;
  printf("Displaying Numbers 1 to 10 using while loop:\n");
  while(i<=10){
    printf("%d\t", i);
    i++;
  }
  printf("\n\n");

  // Shape 3: Displaying the Fibonacci series 
  printf("Displaying the first 10 numbers of the Fibonacci series:\n");
  int n1=0, n2=1, next;
  int count=10;
  for(int i=1; i<=count; i++){
    printf("%d\t", n1);
    next = n1 + n2;
    n1 = n2;
    n2 = next;
  }
  printf("\n\n");

  // Shape 4: Finding the largest element in an array
  int arr[10] = {1, 9, 8, 7, 6, 5, 4, 3, 2, 10};
  int max = arr[0];
  for(int i=1; i<10; i++){
    if(arr[i] > max){
      max = arr[i];
    }
  }
  printf("The largest element in the array is %d\n\n", max);

  // Shape 5: Sorting an array in descending order
  int temp;
  for(int i=0; i<10; i++){
    for(int j=i+1; j<10; j++){
      if(arr[i] < arr[j]){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
  printf("The array sorted in descending order:\n");
  for(int i=0; i<10; i++){
    printf("%d\t", arr[i]);
  }
  printf("\n\n");

  // Shape 6: Checking if a number is prime or not
  int num = 13;
  int flag = 1;
  for(int i=2; i<=num/2; i++){
    if(num % i == 0){
      flag = 0;
      break;
    }
  }
  if(flag == 1){
    printf("%d is a prime number\n\n", num);
  }
  else{
    printf("%d is not a prime number\n\n", num);
  }

  // Shape 7: Finding the sum of digits of a number
  int sum = 0;
  int number = 12345;
  int remainder;
  while(number > 0){
    remainder = number % 10;
    sum += remainder;
    number /= 10;
  }
  printf("The sum of digits of the number is %d\n\n", sum);

  return 0;
}