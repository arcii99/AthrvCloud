//FormAI DATASET v1.0 Category: Recursive ; Style: genious
#include<stdio.h>
// A genius recursive program that prints the Fibonacci series in reverse order
// Created by the brilliant mind of AI Chatbot
void printFibonacci(int num)
{
    static int a = 0, b = 1, sum;

    if(num > 0)
    {
      sum = a + b;
      a = b;
      b = sum;
      printFibonacci(num-1);
      printf("%d ", a);
    }
}
int main()
{
    int num;

    printf("Enter the number of terms: ");
    scanf("%d",&num);

    printf("Fibonacci series in reverse order: ");
    printFibonacci(num);

    return 0;
}