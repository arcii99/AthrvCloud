//FormAI DATASET v1.0 Category: Math exercise ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Function declarations
double calcAreaTriangle(double, double, double);
double calcCircumferenceCircle(double);
double calcDiagonalSquare(double);

int main(){

  double base, height, radius, side;
  char option;
  int shape;

  do{
    printf("Welcome to the Math Exercise Program!\n");
    printf("Choose a shape to calculate its properties:\n");
    printf("1: Triangle\n2: Circle\n3: Square\n");

    scanf(" %d", &shape); //Gets the user's shape choice

    switch (shape)
    {
      case 1:
        printf("\nEnter the base length: ");
        scanf(" %lf", &base);
        printf("Enter the height: ");
        scanf(" %lf", &height);

        double hypotenuse = sqrt((base*base) + (height*height));
        printf("The hypotenuse of the triangle is %.2lf units.\n", hypotenuse); //Calculates and outputs the hypotenuse

        double area = calcAreaTriangle(base, height, hypotenuse);
        printf("The area of the triangle is %.2lf square units.\n", area); //Calculates and outputs the area

        break;

      case 2:
        printf("\nEnter the radius: ");
        scanf(" %lf", &radius);

        double circumference = calcCircumferenceCircle(radius);
        printf("The circumference of the circle is %.2lf units.\n", circumference); //Calculates and outputs the circumference

        double areaCircle = M_PI * pow(radius, 2);
        printf("The area of the circle is %.2lf square units.\n", areaCircle); //Calculates and outputs the area

        break;

      case 3:
        printf("\nEnter the side length: ");
        scanf(" %lf", &side);

        double diagonal = calcDiagonalSquare(side);
        printf("The diagonal of the square is %.2lf units.\n", diagonal); //Calculates and outputs the diagonal

        double areaSquare = pow(side, 2);
        printf("The area of the square is %.2lf square units.\n", areaSquare); //Calculates and outputs the area

        break;

      default:
        printf("Invalid option selected. Try again.\n");
    }

    printf("\nDo you want to solve another problem? (y/n): ");
    scanf(" %c", &option);

  }while(option == 'y' || option == 'Y');

  printf("Thank you for using the Math Exercise Program!");

  return 0;
}

//Functions
double calcAreaTriangle(double b, double h, double hyp){

  double s = (b + h + hyp)/2;
  double area = sqrt(s * (s-b) * (s-h) * (s-hyp));

  return area;
}

double calcCircumferenceCircle(double r){

  double circumference = 2 * M_PI * r;

  return circumference;
}

double calcDiagonalSquare(double s){

  double diagonal = sqrt(2 * pow(s, 2));

  return diagonal;
}