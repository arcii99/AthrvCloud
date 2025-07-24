//FormAI DATASET v1.0 Category: Syntax parsing ; Style: surrealist
#include<stdio.h>

int main()
{
  //Declare variables
  int x;
  float y;

  //Initialize variables
  x = 5;
  y = 3.14;

  //Printout the variables
  printf("The value of integer x is %d\n", x);
  printf("The value of float y is %f\n", y);

  //Check if x is greater than y
  if(x > y)
  {
     printf("The value of x is greater than y\n");
  }
  else
  {
     printf("The value of y is greater than x\n");
  }

  //Declare an array of integers
  int arr[5];

  //Initialize the array
  arr[0] = 1;
  arr[1] = 3;
  arr[2] = 5;
  arr[3] = 7;
  arr[4] = 9;

  //Loop through the array and printout its values
  int i;
  for(i = 0; i < 5; i++)
  {
     printf("The value at index %d is %d\n", i, arr[i]);
  }

  //Declare a pointer to a float
  float *ptr;

  //Set the pointer to point to the variable y
  ptr = &y;

  //Printout the value of y using the pointer
  printf("The value of y using the pointer is %f\n", *ptr);

  //Declare a structure
  struct Person{
     char name[20];
     int age;
  };

  //Declare a variable of type Person
  struct Person p;

  //Initialize the variable
  strcpy(p.name, "Bob");
  p.age = 30;

  //Printout the values of the variable
  printf("Name: %s\n", p.name);
  printf("Age: %d\n", p.age);

  //Declare a function that adds two numbers
  int add(int a, int b)
  {
     return a + b;
  }

  //Call the function and printout the result
  int result;
  result = add(3, 5);
  printf("The result is %d\n", result);

  return 0;
}