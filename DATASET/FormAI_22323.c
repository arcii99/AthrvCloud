//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: intelligent
#include <stdio.h>
#include <string.h>

int main()
{
    int i, score = 0;
    char ans[118], correct_ans[] = "1H 2He 3Li 4Be 5B 6C 7N 8O 9F 10Ne 11Na 12Mg 13Al 14Si 15P 16S 17Cl 18Ar 19K 20Ca 21Sc 22Ti 23V 24Cr 25Mn 26Fe 27Co 28Ni 29Cu 30Zn 31Ga 32Ge 33As 34Se 35Br 36Kr 37Rb 38Sr 39Y 40Zr 41Nb 42Mo 43Tc 44Ru 45Rh 46Pd 47Ag 48Cd 49In 50Sn 51Sb 52Te 53I 54Xe 55Cs 56Ba 57La 58Ce 59Pr 60Nd 61Pm 62Sm 63Eu 64Gd 65Tb 66Dy 67Ho 68Er 69Tm 70Yb 71Lu 72Hf 73Ta 74W 75Re 76Os 77Ir 78Pt 79Au 80Hg 81Tl 82Pb 83Bi 84Po 85At 86Rn 87Fr 88Ra 89Ac 90Th 91Pa 92U 93Np 94Pu 95Am 96Cm 97Bk 98Cf 99Es 100Fm 101Md 102No 103Lr 104Rf 105Db 106Sg 107Bh 108Hs 109Mt 110Ds 111Rg 112Cn 113Nh 114Fl 115Mc 116Lv 117Ts 118Og";

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Please enter the element symbol for each number (e.g. H for Hydrogen):\n");

    for (i=1; i<=118; i++) {
        printf("%d. ", i);
        scanf(" %s", &ans[i]);
    }

    for (i=1; i<=118; i++) {
        if (ans[i] == correct_ans[i-1]) {
            score++;
        }
    }

    printf("\n\nYour score is: %d/118\n\n", score);

    if (score == 118) {
        printf("Congratulations! You are a Periodic Table Genius!\n");
    } else if (score >= 95) {
        printf("Great job! You really know your elements!\n");
    } else if (score >= 70) {
        printf("Not bad, you got some of the trickier ones!\n");
    } else {
        printf("Better luck next time! Study up on your elements!\n");
    }

    return 0;
}