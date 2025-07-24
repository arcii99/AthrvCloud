//FormAI DATASET v1.0 Category: Bitwise operations ; Style: paranoid
#include<stdio.h>

int main(){
  int a = 0xAB;           //Binary 10101011
  int b = 0x0F;           //Binary 00001111
  int x, y, z;

  //Bitwise AND - paranoia level 1
  x = a & b;              //Binary 00001011
  printf("Bitwise AND: %X & %X = %X\n", a, b, x);
  
  //Bitwise OR - paranoia level 2
  y = a | b;              //Binary 10101111
  printf("Bitwise OR: %X | %X = %X\n", a, b, y);
  
  //Bitwise XOR - paranoia level 3
  z = a ^ b;              //Binary 10100100
  printf("Bitwise XOR: %X ^ %X = %X\n", a, b, z);

  //Bitwise NOT - paranoia level 4
  int not_a = ~a;         //Binary 01010100
  printf("Bitwise NOT of %X = %X\n", a, not_a);

  //Left Shift - paranoia level 5
  int ls_a = a << 2;      //Binary 10101100
  printf("Left shift of %X by 2 bits: %X\n", a, ls_a);

  //Right Shift - paranoia level 6
  int rs_b = b >> 3;      //Binary 00000001
  printf("Right shift of %X by 3 bits: %X\n", b, rs_b);

  //Bitwise AND with random numbers - paranoia level 7
  int c = 0x3F;           //Binary 00111111
  int d = 0xE0;           //Binary 11100000
  int e = a & c;          //Binary 00101011
  int f = b & d;          //Binary 00000000
  printf("Bitwise AND with random numbers:\n");
  printf("%X & %X = %X\n", a, c, e);
  printf("%X & %X = %X\n", b, d, f);

  //Bitwise OR with random numbers - paranoia level 8
  int g = 0xB7;           //Binary 10110111
  int h = 0x4F;           //Binary 01001111
  int i = a | g;          //Binary 10111111
  int j = b | h;          //Binary 01001111
  printf("Bitwise OR with random numbers:\n");
  printf("%X | %X = %X\n", a, g, i);
  printf("%X | %X = %X\n", b, h, j);

  //Bitwise XOR with random numbers - paranoia level 9
  int k = 0x57;           //Binary 01010111
  int l = 0xC8;           //Binary 11001000
  int m = a ^ k;          //Binary 11111100
  int n = b ^ l;          //Binary 10000111
  printf("Bitwise XOR with random numbers:\n");
  printf("%X ^ %X = %X\n", a, k, m);
  printf("%X ^ %X = %X\n", b, l, n);

  //Bitwise operations on a character - paranoia level 10
  char ch = 'A';          
  int o = ch & a;         //Binary 01000001
  int p = ch | b;         //Binary 01001111
  int q = ch ^ k;         //Binary 00010000
  printf("Bitwise operations on a character:\n");
  printf("%c & %X = %X\n", ch, a, o);
  printf("%c | %X = %X\n", ch, b, p);
  printf("%c ^ %X = %X\n", ch, k, q);

  return 0;
}