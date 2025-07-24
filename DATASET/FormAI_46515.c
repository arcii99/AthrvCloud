//FormAI DATASET v1.0 Category: Bitwise operations ; Style: brave
#include<stdio.h>

int main(){
    int a, b, c, d, e, f, g, h; 

    printf("Enter 8 integers to perform bitwise operations on: ");
    scanf("%d %d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g, &h);

    printf("The bitwise AND of %d, %d, %d, %d, %d, %d, %d, and %d is %d\n", a, b, c, d, e, f, g, h, (a & b & c & d & e & f & g & h));
    printf("The bitwise OR of %d, %d, %d, %d, %d, %d, %d, and %d is %d\n", a, b, c, d, e, f, g, h, (a | b | c | d | e | f | g | h));
    printf("The bitwise XOR of %d, %d, %d, %d, %d, %d, %d, and %d is %d\n", a, b, c, d, e, f, g, h, (a ^ b ^ c ^ d ^ e ^ f ^ g ^ h));
    printf("The bitwise complement of %d, %d, %d, %d, %d, %d, %d, and %d is %d\n", a, b, c, d, e, f, g, h, (~a & ~b & ~c & ~d & ~e & ~f & ~g & ~h));
    printf("The left shift of %d, %d, %d, %d, %d, %d, %d, and %d by 2 is %d, %d, %d, %d, %d, %d, %d, %d\n", a, b, c, d, e, f, g, h, (a<<2), (b<<2), (c<<2), (d<<2), (e<<2), (f<<2), (g<<2), (h<<2));
    printf("The right shift of %d, %d, %d, %d, %d, %d, %d, and %d by 2 is %d, %d, %d, %d, %d, %d, %d, %d\n", a, b, c, d, e, f, g, h, (a>>2), (b>>2), (c>>2), (d>>2), (e>>2), (f>>2), (g>>2), (h>>2));

    return 0;
}