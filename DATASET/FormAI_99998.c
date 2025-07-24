//FormAI DATASET v1.0 Category: Educational ; Style: curious
#include<stdio.h>

int main(){
  
  // Curious Program begins!
  
  printf("Enter a number: "); // Asking user for a number input
  int num;
  scanf("%d", &num); // storing the input number in variable 'num'
  
  int i,f=0; // declaring variables 'i' and 'f' for looping and flag respectively
  for(i=2;i<=num/2;++i){ // loop for checking if input number is prime or not
    if(num%i==0){ // if input number is divisible by any integer other than 1 and itself
      f=1; // set the flag to 1, indicating it is not a prime number
      break; // break out of the loop
    }
  }
  
  if(num==1){ // checking if the input number is 1
    printf("1 is a unique number that is neither prime nor composite."); // unique message
  }
  else{ // if input number is not 1
    if(f==0){ // checking if the flag is still 0, indicating it is a prime number
      printf("%d is a prime number.",num); // output message indicating it is a prime number
    }
    else{ // if the flag is 1, indicating it is not a prime number
      printf("%d is not a prime number.",num); // output message indicating it is not a prime number
      
      int sum=0,rem,temp; // declaring variables 'sum', 'rem' and 'temp' for summing the digits of input number
      temp=num; // storing the input number in a temporary variable 'temp'
      while(temp!=0){ // loop for summing the digits of input number
        rem=temp%10; // finding the remainder of the input number divided by 10
        sum=sum+rem; // adding the remainder to the sum
        temp=temp/10; // updating the input number by dividing it by 10
      }
      
      if(sum==1){ // checking if the sum is 1
        printf(" But %d is a unique number whose sum of digits is also 1.",num); // unique message
      }
      else{ // if the sum is not 1
        printf(" The sum of digits of %d is %d.",num,sum); // output message indicating the sum of digits of input number
      }
    }
  }
  
  // Curious Program ends!
  
  return 0; // Program execution completed successfully
}