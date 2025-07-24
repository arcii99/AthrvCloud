//FormAI DATASET v1.0 Category: Bitwise operations ; Style: imaginative
#include <stdio.h>

int main() {
    // Creating two variables
    unsigned int a = 10, b = 5;
    
    // Bitwise AND operator
    int c = a & b;
    printf("Output of a & b is %d\n", c);
    
    /* Imaginative scenario: You are a space explorer traveling through the galaxy
       and you need to calculate whether your spaceship has enough fuel to make it to
       the next planet. You know the distance in light years and the fuel efficiency
       in kilometers per liter, but you need to convert the numbers using bitwise
       operators because you only have limited memory on your spaceship's computer. */
    
    // Converting light years to kilometers using shift operators
    unsigned long int distance_ly = 1000; // distance in light years
    unsigned long int distance_km = distance_ly << 9; // 1 light year = 9.461 trillion km
    printf("The distance to the next planet is %lu kilometers\n", distance_km);
    
    // Converting kilometers to liters of fuel using AND operator
    int efficiency = 2; // kilometers per liter of fuel
    int fuel = distance_km & efficiency;
    printf("You will need %d liters of fuel to make it to the next planet\n", fuel);
    
    // Bitwise OR operator
    int d = a | b;
    printf("Output of a | b is %d\n", d);
    
    /* Imaginative scenario: You are a secret agent trying to decode a message from your enemy.
       You receive a series of numbers and need to use bitwise operators to convert them into
       binary and then combine them into a single decrypted message. */
    
    // Converting numbers to binary using shift operators
    unsigned int num1 = 128;
    unsigned int num2 = 64;
    unsigned int num3 = 32;
    unsigned int num4 = 16;
    
    int bin1 = num1 >> 7; // 128 = 10000000 in binary
    int bin2 = num2 >> 6; // 64 = 01000000 in binary
    int bin3 = num3 >> 5; // 32 = 00100000 in binary
    int bin4 = num4 >> 4; // 16 = 00010000 in binary
    
    // Combining binary numbers using OR operator
    int message = bin1 | bin2 | bin3 | bin4;
    printf("The decrypted message is %d\n", message);
    
    // Bitwise NOT operator
    int e = ~a;
    printf("Output of ~a is %d\n", e);
    
    /* Imaginative scenario: You are a hacker trying to bypass a security system
       that requires a randomly generated password. You know the password is a
       combination of uppercase and lowercase letters, but you need to use bitwise
       operators to convert the ASCII values to characters. */
    
    // Converting ASCII values to characters using bitwise AND operator
    unsigned int x = 536870912; // ASCII value of uppercase "A"
    unsigned int y = 1048584; // ASCII value of lowercase "h"
    unsigned int z = 256; // ASCII value of uppercase "Q"
    
    char pw1 = (char)(x & 0xff);
    char pw2 = (char)(y & 0xff);
    char pw3 = (char)(z & 0xff);
    
    // Printing the password
    printf("The password is %c%c%c\n", pw1, pw2, pw3);
    
    return 0;
}