//FormAI DATASET v1.0 Category: Bitwise operations ; Style: happy
#include<stdio.h>

int main(){
    int a = 22, b = 11;
    int c = a & b;
    int d = a | b;
    int e = a ^ b;
    int f = ~a;
    int g = b << 1;
    int h = b >> 1;
    
    printf("a & b = %d\n", c); //Bitwise AND
    printf("a | b = %d\n", d); //Bitwise OR
    printf("a ^ b = %d\n", e); //Bitwise XOR
    printf("~a = %d\n", f); //Bitwise NOT
    printf("b << 1 = %d\n", g); //Bitwise Left Shift
    printf("a >> 1 = %d\n\n\n", h); //Bitwise Right Shift
    
    printf("It's a brand new day and we're doing bitwise operations!\n");
    printf("We're happy to show you that we can manipulate bits like a boss!\n");
    printf("We'll make use of our '&|~^<<>>' operators and make some magic happen!\n");
    
    printf("Let's take two numbers a = 22 and b = 11\n");
    printf("When we do a & b, we get %d because 22 in binary is 10110 and 11 is 01011\n", c);
    printf("and when we apply the & operator, we get 00010, which is 2 in decimal\n");
    
    printf("When we do a | b, we get %d because 22 in binary is 10110 and 11 is 01011\n", d);
    printf("and when we apply the | operator, we get 11111, which is 31 in decimal\n");
    
    printf("When we do a ^ b, we get %d because 22 in binary is 10110 and 11 is 01011\n", e);
    printf("and when we apply the ^ operator, we get 11101, which is 29 in decimal\n");
    
    printf("When we do ~a, we get %d because a = 22 in binary is 10110\n", f);
    printf("and when we apply the ~ operator, we get 01001, which is -23 in decimal\n");
    
    printf("When we do b << 1, we get %d because 11 in binary is 01011\n", g);
    printf("and when we apply the << operator, we get 10110, which is 22 in decimal\n");
    
    printf("When we do a >> 1, we get %d because 22 in binary is 10110\n", h);
    printf("and when we apply the >> operator, we get 01011, which is 11 in decimal\n");
    
    return 0;
}