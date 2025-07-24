//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int subnet_mask, num_hosts, bits_borrowed;
    printf("Greetings traveler! Welcome to the Subnet Calculator!\n");
    printf("Today, I will help thee to calculate thine subnet mask, number of hosts, and borrowed bits.\n");
    printf("To begin, choose thine desired number of hosts:\n");
    scanf("%d", &num_hosts);

    if(num_hosts <= 0){
        printf("Nay, that number is too small! Try again!");
        return 0;
    }

    printf("And how many bits art thou wishing to borrow from thine network address?\n");
    scanf("%d", &bits_borrowed);

    if(bits_borrowed < 0){
        printf("I'm sorry, but that is impossible! Try again!");
        return 0;
    }

    if(bits_borrowed > 8){
        printf("Verily, thou cannot borrow more than 8 bits. Thy value hath been reduced to 8.");
        bits_borrowed = 8;
    }

    subnet_mask = 256 - (int)(pow(2, 8 - bits_borrowed));
    printf("Thine subnet mask is: %d\n", subnet_mask);
    printf("And thou hast borrowed %d bits.\n", bits_borrowed);

    int num_hosts_possible = (int)(pow(2, 32 - subnet_mask - 1)) - 2;
    if(num_hosts > num_hosts_possible){
        printf("Alas, with that subnet mask, thou can only have %d hosts.", num_hosts_possible);
    } else {
        printf("Thou hast a maximum of %d hosts on this subnet.\n", num_hosts);
    }

    printf("I hope this hath been useful to thee, traveler. Safe travels!\n");

    return 0;
}