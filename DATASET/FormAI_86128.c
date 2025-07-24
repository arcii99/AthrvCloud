//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to display the periodic table
void display_table() {
    printf("---------------------------------------------------\n");
    printf("| H  | He | Li | Be | B  | C  | N  | O  | F  | Ne |\n");
    printf("---------------------------------------------------\n");
    printf("| Na | Mg | Al | Si | P  | S  | Cl | Ar | K  | Ca |\n");
    printf("---------------------------------------------------\n");
    printf("| Sc | Ti | V  | Cr | Mn | Fe | Co | Ni | Cu | Zn |\n");
    printf("---------------------------------------------------\n");
    printf("| Ga | Ge | As | Se | Br | Kr | Rb | Sr | Y  | Zr |\n");
    printf("---------------------------------------------------\n");
    printf("| Nb | Mo | Tc | Ru | Rh | Pd | Ag | Cd | In | Sn |\n");
    printf("---------------------------------------------------\n");
    printf("| Sb | Te | I  | Xe | Cs | Ba | La | Ce | Pr | Nd |\n");
    printf("---------------------------------------------------\n");
    printf("| Pm | Sm | Eu | Gd | Tb | Dy | Ho | Er | Tm | Yb |\n");
    printf("---------------------------------------------------\n");
    printf("| Lu | Hf | Ta | W  | Re | Os | Ir | Pt | Au | Hg |\n");
    printf("---------------------------------------------------\n");
    printf("| Tl | Pb | Bi | Po | At | Rn | Fr | Ra | Ac | Th |\n");
    printf("---------------------------------------------------\n");
    printf("| Pa | U  | Np | Pu | Am | Cm | Bk | Cf | Es | Fm |\n");
    printf("---------------------------------------------------\n");
    printf("| Md | No | Lr | Rf | Db | Sg | Bh | Hs | Mt | Ds |\n");
    printf("---------------------------------------------------\n");
    printf("| Rg | Cn | Nh | Fl | Mc | Lv | Ts | Og |    |    |\n");
    printf("---------------------------------------------------\n");
}

int main() {
    char symbol[3];
    int atomic_number, group, period;

    // Display the periodic table
    display_table();

    // Get the symbol from the user
    printf("\nEnter the symbol of the element: ");
    scanf("%s", symbol);

    // Determine the atomic number based on the symbol
    if (strcmp(symbol, "H") == 0) {
        atomic_number = 1;
    } else if (strcmp(symbol, "He") == 0) {
        atomic_number = 2;
    } else if (strcmp(symbol, "Li") == 0) {
        atomic_number = 3;
    } else if (strcmp(symbol, "Be") == 0) {
        atomic_number = 4;
    } else if (strcmp(symbol, "B") == 0) {
        atomic_number = 5;
    } else if (strcmp(symbol, "C") == 0) {
        atomic_number = 6;
    } else if (strcmp(symbol, "N") == 0) {
        atomic_number = 7;
    } else if (strcmp(symbol, "O") == 0) {
        atomic_number = 8;
    } else if (strcmp(symbol, "F") == 0) {
        atomic_number = 9;
    } else if (strcmp(symbol, "Ne") == 0) {
        atomic_number = 10;
    } else if (strcmp(symbol, "Na") == 0) {
        atomic_number = 11;
    } else if (strcmp(symbol, "Mg") == 0) {
        atomic_number = 12;
    } else if (strcmp(symbol, "Al") == 0) {
        atomic_number = 13;
    } else if (strcmp(symbol, "Si") == 0) {
        atomic_number = 14;
    } else if (strcmp(symbol, "P") == 0) {
        atomic_number = 15;
    } else if (strcmp(symbol, "S") == 0) {
        atomic_number = 16;
    } else if (strcmp(symbol, "Cl") == 0) {
        atomic_number = 17;
    } else if (strcmp(symbol, "Ar") == 0) {
        atomic_number = 18;
    } else if (strcmp(symbol, "K") == 0) {
        atomic_number = 19;
    } else if (strcmp(symbol, "Ca") == 0) {
        atomic_number = 20;
    } else if (strcmp(symbol, "Sc") == 0) {
        atomic_number = 21;
    } else if (strcmp(symbol, "Ti") == 0) {
        atomic_number = 22;
    } else if (strcmp(symbol, "V") == 0) {
        atomic_number = 23;
    } else if (strcmp(symbol, "Cr") == 0) {
        atomic_number = 24;
    } else if (strcmp(symbol, "Mn") == 0) {
        atomic_number = 25;
    } else if (strcmp(symbol, "Fe") == 0) {
        atomic_number = 26;
    } else if (strcmp(symbol, "Co") == 0) {
        atomic_number = 27;
    } else if (strcmp(symbol, "Ni") == 0) {
        atomic_number = 28;
    } else if (strcmp(symbol, "Cu") == 0) {
        atomic_number = 29;
    } else if (strcmp(symbol, "Zn") == 0) {
        atomic_number = 30;
    } else if (strcmp(symbol, "Ga") == 0) {
        atomic_number = 31;
    } else if (strcmp(symbol, "Ge") == 0) {
        atomic_number = 32;
    } else if (strcmp(symbol, "As") == 0) {
        atomic_number = 33;
    } else if (strcmp(symbol, "Se") == 0) {
        atomic_number = 34;
    } else if (strcmp(symbol, "Br") == 0) {
        atomic_number = 35;
    } else if (strcmp(symbol, "Kr") == 0) {
        atomic_number = 36;
    } else if (strcmp(symbol, "Rb") == 0) {
        atomic_number = 37;
    } else if (strcmp(symbol, "Sr") == 0) {
        atomic_number = 38;
    } else if (strcmp(symbol, "Y") == 0) {
        atomic_number = 39;
    } else if (strcmp(symbol, "Zr") == 0) {
        atomic_number = 40;
    } else if (strcmp(symbol, "Nb") == 0) {
        atomic_number = 41;
    } else if (strcmp(symbol, "Mo") == 0) {
        atomic_number = 42;
    } else if (strcmp(symbol, "Tc") == 0) {
        atomic_number = 43;
    } else if (strcmp(symbol, "Ru") == 0) {
        atomic_number = 44;
    } else if (strcmp(symbol, "Rh") == 0) {
        atomic_number = 45;
    } else if (strcmp(symbol, "Pd") == 0) {
        atomic_number = 46;
    } else if (strcmp(symbol, "Ag") == 0) {
        atomic_number = 47;
    } else if (strcmp(symbol, "Cd") == 0) {
        atomic_number = 48;
    } else if (strcmp(symbol, "In") == 0) {
        atomic_number = 49;
    } else if (strcmp(symbol, "Sn") == 0) {
        atomic_number = 50;
    } else if (strcmp(symbol, "Sb") == 0) {
        atomic_number = 51;
    } else if (strcmp(symbol, "Te") == 0) {
        atomic_number = 52;
    } else if (strcmp(symbol, "I") == 0) {
        atomic_number = 53;
    } else if (strcmp(symbol, "Xe") == 0) {
        atomic_number = 54;
    } else if (strcmp(symbol, "Cs") == 0) {
        atomic_number = 55;
    } else if (strcmp(symbol, "Ba") == 0) {
        atomic_number = 56;
    } else if (strcmp(symbol, "La") == 0) {
        atomic_number = 57;
    } else if (strcmp(symbol, "Ce") == 0) {
        atomic_number = 58;
    } else if (strcmp(symbol, "Pr") == 0) {
        atomic_number = 59;
    } else if (strcmp(symbol, "Nd") == 0) {
        atomic_number = 60;
    } else if (strcmp(symbol, "Pm") == 0) {
        atomic_number = 61;
    } else if (strcmp(symbol, "Sm") == 0) {
        atomic_number = 62;
    } else if (strcmp(symbol, "Eu") == 0) {
        atomic_number = 63;
    } else if (strcmp(symbol, "Gd") == 0) {
        atomic_number = 64;
    } else if (strcmp(symbol, "Tb") == 0) {
        atomic_number = 65;
    } else if (strcmp(symbol, "Dy") == 0) {
        atomic_number = 66;
    } else if (strcmp(symbol, "Ho") == 0) {
        atomic_number = 67;
    } else if (strcmp(symbol, "Er") == 0) {
        atomic_number = 68;
    } else if (strcmp(symbol, "Tm") == 0) {
        atomic_number = 69;
    } else if (strcmp(symbol, "Yb") == 0) {
        atomic_number = 70;
    } else if (strcmp(symbol, "Lu") == 0) {
        atomic_number = 71;
    } else if (strcmp(symbol, "Hf") == 0) {
        atomic_number = 72;
    } else if (strcmp(symbol, "Ta") == 0) {
        atomic_number = 73;
    } else if (strcmp(symbol, "W") == 0) {
        atomic_number = 74;
    } else if (strcmp(symbol, "Re") == 0) {
        atomic_number = 75;
    } else if (strcmp(symbol, "Os") == 0) {
        atomic_number = 76;
    } else if (strcmp(symbol, "Ir") == 0) {
        atomic_number = 77;
    } else if (strcmp(symbol, "Pt") == 0) {
        atomic_number = 78;
    } else if (strcmp(symbol, "Au") == 0) {
        atomic_number = 79;
    } else if (strcmp(symbol, "Hg") == 0) {
        atomic_number = 80;
    } else if (strcmp(symbol, "Tl") == 0) {
        atomic_number = 81;
    } else if (strcmp(symbol, "Pb") == 0) {
        atomic_number = 82;
    } else if (strcmp(symbol, "Bi") == 0) {
        atomic_number = 83;
    } else if (strcmp(symbol, "Po") == 0) {
        atomic_number = 84;
    } else if (strcmp(symbol, "At") == 0) {
        atomic_number = 85;
    } else if (strcmp(symbol, "Rn") == 0) {
        atomic_number = 86;
    } else if (strcmp(symbol, "Fr") == 0) {
        atomic_number = 87;
    } else if (strcmp(symbol, "Ra") == 0) {
        atomic_number = 88;
    } else if (strcmp(symbol, "Ac") == 0) {
        atomic_number = 89;
    } else if (strcmp(symbol, "Th") == 0) {
        atomic_number = 90;
    } else if (strcmp(symbol, "Pa") == 0) {
        atomic_number = 91;
    } else if (strcmp(symbol, "U") == 0) {
        atomic_number = 92;
    } else if (strcmp(symbol, "Np") == 0) {
        atomic_number = 93;
    } else if (strcmp(symbol, "Pu") == 0) {
        atomic_number = 94;
    } else if (strcmp(symbol, "Am") == 0) {
        atomic_number = 95;
    } else if (strcmp(symbol, "Cm") == 0) {
        atomic_number = 96;
    } else if (strcmp(symbol, "Bk") == 0) {
        atomic_number = 97;
    } else if (strcmp(symbol, "Cf") == 0) {
        atomic_number = 98;
    } else if (strcmp(symbol, "Es") == 0) {
        atomic_number = 99;
    } else if (strcmp(symbol, "Fm") == 0) {
        atomic_number = 100;
    } else if (strcmp(symbol, "Md") == 0) {
        atomic_number = 101;
    } else if (strcmp(symbol, "No") == 0) {
        atomic_number = 102;
    } else if (strcmp(symbol, "Lr") == 0) {
        atomic_number = 103;
    } else if (strcmp(symbol, "Rf") == 0) {
        atomic_number = 104;
    } else if (strcmp(symbol, "Db") == 0) {
        atomic_number = 105;
    } else if (strcmp(symbol, "Sg") == 0) {
        atomic_number = 106;
    } else if (strcmp(symbol, "Bh") == 0) {
        atomic_number = 107;
    } else if (strcmp(symbol, "Hs") == 0) {
        atomic_number = 108;
    } else if (strcmp(symbol, "Mt") == 0) {
        atomic_number = 109;
    } else if (strcmp(symbol, "Ds") == 0) {
        atomic_number = 110;
    } else if (strcmp(symbol, "Rg") == 0) {
        atomic_number = 111;
    } else if (strcmp(symbol, "Cn") == 0) {
        atomic_number = 112;
    } else if (strcmp(symbol, "Nh") == 0) {
        atomic_number = 113;
    } else if (strcmp(symbol, "Fl") == 0) {
        atomic_number = 114;
    } else if (strcmp(symbol, "Mc") == 0) {
        atomic_number = 115;
    } else if (strcmp(symbol, "Lv") == 0) {
        atomic_number = 116;
    } else if (strcmp(symbol, "Ts") == 0) {
        atomic_number = 117;
    } else if (strcmp(symbol, "Og") == 0) {
        atomic_number = 118;
    } else {
        printf("Invalid symbol \"%s\".\n", symbol);
        return 0;
    }

    // Determine the group and period based on the atomic number
    if (atomic_number == 1 || atomic_number == 2) {
        group = 1;
        if (atomic_number == 1) {
            period = 1;
        } else {
            period = 2;
        }
    } else if (atomic_number >= 3 && atomic_number <= 10) {
        group = 2;
        period = 2;
    } else if (atomic_number >= 11 && atomic_number <= 18) {
        group = atomic_number - 10;
        period = 3;
    } else if (atomic_number >= 19 && atomic_number <= 36) {
        group = atomic_number - 18;
        period = 4;
    } else if (atomic_number >= 37 && atomic_number <= 54) {
        group = atomic_number - 36;
        period = 5;
    } else if (atomic_number >= 55 && atomic_number <= 86) {
        group = atomic_number - 54;
        period = 6;
    } else if (atomic_number >= 87 && atomic_number <= 118) {
        group = atomic_number - 86;
        period = 7;
    }

    // Output the information
    printf("\n%s is in group %d and period %d.\n", symbol, group, period);

    return 0;
}