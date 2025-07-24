//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: beginner-friendly
#include<stdio.h>             //importing the standard input-output library
#include<math.h>              //importing the math library

void menu();                  //declaring function menu

void main()                   //main function
{
  printf("\t\tWelcome to my Scientific Calculator\n");
  menu();                     //calling the function menu
}

void menu()                   //function which displays the menu and performs the operations
{
  int choice;
  float a,result;

  printf("\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Square\n6. Cube\n7. Square Root\n8. Logarithm\n9. Sine\n10. Cosine\n11. Tangent\n12. Exit\n");
  printf("\nEnter your choice:\n");
  scanf("%d",&choice);         //reading choice
  switch(choice)              //switch case
  {
    case 1:                   //addition
      printf("\nEnter two numbers: ");
      scanf("%f%f",&a,&result);
      printf("\n%.2f + %.2f = %.2f\n",a,result,a+result);   //printing the result
      menu();
      break;
    case 2:                   //subtraction
      printf("\nEnter two numbers: ");
      scanf("%f%f",&a,&result);
      printf("\n%.2f - %.2f = %.2f\n",a,result,a-result);   //printing the result
      menu();
      break;
    case 3:                   //multiplication
      printf("\nEnter two numbers: ");
      scanf("%f%f",&a,&result);
      printf("\n%.2f * %.2f = %.2f\n",a,result,a*result);   //printing the result
      menu();
      break;
    case 4:                   //division
      printf("\nEnter two numbers: ");
      scanf("%f%f",&a,&result);
      if(result==0)                                          //checking if divisor is zero
      {
        printf("\nDivisor cannot be zero\n");
        menu();
        break;
      }
      printf("\n%.2f / %.2f = %.2f\n",a,result,a/result);    //printing the result
      menu();
      break;
    case 5:                  //square
      printf("\nEnter a number: ");
      scanf("%f",&a);
      printf("\n%.2f ^ 2 = %.2f\n",a,pow(a,2));             //printing the result
      menu();
      break;
    case 6:                  //cube
      printf("\nEnter a number: ");
      scanf("%f",&a);
      printf("\n%.2f ^ 3 = %.2f\n",a,pow(a,3));             //printing the result
      menu();
      break;
    case 7:                  //square root
      printf("\nEnter a number: ");
      scanf("%f",&a);
      if(a<0)                                               //checking if number is negative
      {
        printf("\nImaginary number\n");
        menu();
        break;
      }
      printf("\nSquare Root of %.2f = %.2f\n",a,sqrt(a));   //printing the result
      menu();
      break;
    case 8:                  //logarithm
      printf("\nEnter a number: ");
      scanf("%f",&a);
      if(a<=0)                                              //checking if number is zero or negative
      {
        printf("\nInvalid Input\n");
        menu();
        break;
      } 
      printf("\nLogarithm of %.2f to the base 10 = %.2f\n",a,log10(a));   //printing the result
      menu();
      break;
    case 9:                  //sine
      printf("\nEnter the angle in degrees: ");
      scanf("%f",&a);
      printf("\nSine of %.2f degrees = %.2f\n",a,sin(a));   //printing the result
      menu();
      break;
    case 10:                 //cosine
      printf("\nEnter the angle in degrees: ");
      scanf("%f",&a);
      printf("\nCosine of %.2f degrees = %.2f\n",a,cos(a));  //printing the result
      menu();
      break;
    case 11:                 //tangent
      printf("\nEnter the angle in degrees: ");
      scanf("%f",&a);
      printf("\nTangent of %.2f degrees = %.2f\n",a,tan(a)); //printing the result
      menu();
      break;
    case 12:                 //exit
      printf("\nThank You for using my Scientific Calculator!!!\n");   //printing exit message
      break;
    default:                //default case
      printf("\nInvalid Input!!!\n");        //printing invalid input message
      menu();
      break;
  }
}