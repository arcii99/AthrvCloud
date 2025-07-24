//FormAI DATASET v1.0 Category: Educational ; Style: Cryptic
#include<stdio.h> 
#define a R 
#define b S 
#define c T 
int a, b, c; // defining integer variables R, S, and T
void func(int p, int q, int r) // function definition for func which takes in 3 integer arguments
{ 
    a = p - q; 
    b = q - r; 
    c = r - p; 
    if (a < 0) 
    {
        a = -a;
    }
    if (b < 0) 
    {
        b = -b;
    }
    if (c < 0) 
    {
        c = -c;
    }
} 

int main() 
{ 
    int var1, var2, var3; // declaring 3 integer variables
    printf("Enter the three numbers separated by commas: "); // asking the user to input 3 numbers
    scanf("%d, %d, %d", &var1, &var2, &var3); // reading the user input
    
    func(var1, var2, var3); // calling the function func with the 3 user inputs  
    printf("%d %d %d\n", R, S, T); // outputting the abs values of the differences with the help of R, S, and T
    
    return 0; 
}