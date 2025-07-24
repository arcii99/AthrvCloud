//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {

    srand(time(NULL));
    int r = rand() % 118;

    char symbol[3], answer[32];

    switch(r) {
        case 0:
        strcpy(symbol, "H");
        strcpy(answer, "Hydrogen");
        break;

        case 1:
        strcpy(symbol, "He");
        strcpy(answer, "Helium");
        break;

        case 2:
        strcpy(symbol, "Li");
        strcpy(answer, "Lithium");
        break;

        case 3:
        strcpy(symbol, "Be");
        strcpy(answer, "Beryllium");
        break;

        case 4:
        strcpy(symbol, "B");
        strcpy(answer, "Boron");
        break;

        case 5:
        strcpy(symbol, "C");
        strcpy(answer, "Carbon");
        break;

        case 6:
        strcpy(symbol, "N");
        strcpy(answer, "Nitrogen");
        break;

        case 7:
        strcpy(symbol, "O");
        strcpy(answer, "Oxygen");
        break;

        case 8:
        strcpy(symbol, "F");
        strcpy(answer, "Fluorine");
        break;

        case 9:
        strcpy(symbol, "Ne");
        strcpy(answer, "Neon");
        break;

        case 10:
        strcpy(symbol, "Na");
        strcpy(answer, "Sodium");
        break;

        case 11:
        strcpy(symbol, "Mg");
        strcpy(answer, "Magnesium");
        break;

        case 12:
        strcpy(symbol, "Al");
        strcpy(answer, "Aluminum");
        break;

        case 13:
        strcpy(symbol, "Si");
        strcpy(answer, "Silicon");
        break;

        case 14:
        strcpy(symbol, "P");
        strcpy(answer, "Phosphorus");
        break;

        case 15:
        strcpy(symbol, "S");
        strcpy(answer, "Sulfur");
        break;

        case 16:
        strcpy(symbol, "Cl");
        strcpy(answer, "Chlorine");
        break;

        case 17:
        strcpy(symbol, "Ar");
        strcpy(answer, "Argon");
        break;

        case 18:
        strcpy(symbol, "K");
        strcpy(answer, "Potassium");
        break;

        case 19:
        strcpy(symbol, "Ca");
        strcpy(answer, "Calcium");
        break;

        case 20:
        strcpy(symbol, "Sc");
        strcpy(answer, "Scandium");
        break;

        case 21:
        strcpy(symbol, "Ti");
        strcpy(answer, "Titanium");
        break;

        case 22:
        strcpy(symbol, "V");
        strcpy(answer, "Vanadium");
        break;

        case 23:
        strcpy(symbol, "Cr");
        strcpy(answer, "Chromium");
        break;

        case 24:
        strcpy(symbol, "Mn");
        strcpy(answer, "Manganese");
        break;

        case 25:
        strcpy(symbol, "Fe");
        strcpy(answer, "Iron");
        break;

        case 26:
        strcpy(symbol, "Co");
        strcpy(answer, "Cobalt");
        break;

        case 27:
        strcpy(symbol, "Ni");
        strcpy(answer, "Nickel");
        break;

        case 28:
        strcpy(symbol, "Cu");
        strcpy(answer, "Copper");
        break;

        case 29:
        strcpy(symbol, "Zn");
        strcpy(answer, "Zinc");
        break;

        case 30:
        strcpy(symbol, "Ga");
        strcpy(answer, "Gallium");
        break;

        case 31:
        strcpy(symbol, "Ge");
        strcpy(answer, "Germanium");
        break;

        case 32:
        strcpy(symbol, "As");
        strcpy(answer, "Arsenic");
        break;

        case 33:
        strcpy(symbol, "Se");
        strcpy(answer, "Selenium");
        break;

        case 34:
        strcpy(symbol, "Br");
        strcpy(answer, "Bromine");
        break;

        case 35:
        strcpy(symbol, "Kr");
        strcpy(answer, "Krypton");
        break;

        case 36:
        strcpy(symbol, "Rb");
        strcpy(answer, "Rubidium");
        break;

        case 37:
        strcpy(symbol, "Sr");
        strcpy(answer, "Strontium");
        break;

        case 38:
        strcpy(symbol, "Y");
        strcpy(answer, "Yttrium");
        break;

        case 39:
        strcpy(symbol, "Zr");
        strcpy(answer, "Zirconium");
        break;

        case 40:
        strcpy(symbol, "Nb");
        strcpy(answer, "Niobium");
        break;

        case 41:
        strcpy(symbol, "Mo");
        strcpy(answer, "Molybdenum");
        break;

        case 42:
        strcpy(symbol, "Tc");
        strcpy(answer, "Technetium");
        break;

        case 43:
        strcpy(symbol, "Ru");
        strcpy(answer, "Ruthenium");
        break;

        case 44:
        strcpy(symbol, "Rh");
        strcpy(answer, "Rhodium");
        break;

        case 45:
        strcpy(symbol, "Pd");
        strcpy(answer, "Palladium");
        break;

        case 46:
        strcpy(symbol, "Ag");
        strcpy(answer, "Silver");
        break;

        case 47:
        strcpy(symbol, "Cd");
        strcpy(answer, "Cadmium");
        break;

        case 48:
        strcpy(symbol, "In");
        strcpy(answer, "Indium");
        break;

        case 49:
        strcpy(symbol, "Sn");
        strcpy(answer, "Tin");
        break;

        case 50:
        strcpy(symbol, "Sb");
        strcpy(answer, "Antimony");
        break;

        case 51:
        strcpy(symbol, "Te");
        strcpy(answer, "Tellurium");
        break;

        case 52:
        strcpy(symbol, "I");
        strcpy(answer, "Iodine");
        break;

        case 53:
        strcpy(symbol, "Xe");
        strcpy(answer, "Xenon");
        break;

        case 54:
        strcpy(symbol, "Cs");
        strcpy(answer, "Cesium");
        break;

        case 55:
        strcpy(symbol, "Ba");
        strcpy(answer, "Barium");
        break;

        case 56:
        strcpy(symbol, "La");
        strcpy(answer, "Lanthanum");
        break;

        case 57:
        strcpy(symbol, "Ce");
        strcpy(answer, "Cerium");
        break;

        case 58:
        strcpy(symbol, "Pr");
        strcpy(answer, "Praseodymium");
        break;

        case 59:
        strcpy(symbol, "Nd");
        strcpy(answer, "Neodymium");
        break;

        case 60:
        strcpy(symbol, "Pm");
        strcpy(answer, "Promethium");
        break;

        case 61:
        strcpy(symbol, "Sm");
        strcpy(answer, "Samarium");
        break;

        case 62:
        strcpy(symbol, "Eu");
        strcpy(answer, "Europium");
        break;

        case 63:
        strcpy(symbol, "Gd");
        strcpy(answer, "Gadolinium");
        break;

        case 64:
        strcpy(symbol, "Tb");
        strcpy(answer, "Terbium");
        break;

        case 65:
        strcpy(symbol, "Dy");
        strcpy(answer, "Dysprosium");
        break;

        case 66:
        strcpy(symbol, "Ho");
        strcpy(answer, "Holmium");
        break;

        case 67:
        strcpy(symbol, "Er");
        strcpy(answer, "Erbium");
        break;

        case 68:
        strcpy(symbol, "Tm");
        strcpy(answer, "Thulium");
        break;

        case 69:
        strcpy(symbol, "Yb");
        strcpy(answer, "Ytterbium");
        break;

        case 70:
        strcpy(symbol, "Lu");
        strcpy(answer, "Lutetium");
        break;

        case 71:
        strcpy(symbol, "Hf");
        strcpy(answer, "Hafnium");
        break;

        case 72:
        strcpy(symbol, "Ta");
        strcpy(answer, "Tantalum");
        break;

        case 73: 
        strcpy(symbol, "W");
        strcpy(answer, "Tungsten");
        break;

        case 74:
        strcpy(symbol, "Re");
        strcpy(answer, "Rhenium");
        break;

        case 75:
        strcpy(symbol, "Os");
        strcpy(answer, "Osmium");
        break;

        case 76:
        strcpy(symbol, "Ir");
        strcpy(answer, "Iridium");
        break;

        case 77:
        strcpy(symbol, "Pt");
        strcpy(answer, "Platinum");
        break;

        case 78:
        strcpy(symbol, "Au");
        strcpy(answer, "Gold");
        break;

        case 79:
        strcpy(symbol, "Hg");
        strcpy(answer, "Mercury");
        break;

        case 80:
        strcpy(symbol, "Tl");
        strcpy(answer, "Thallium");
        break;

        case 81:
        strcpy(symbol, "Pb");
        strcpy(answer, "Lead");
        break;

        case 82:
        strcpy(symbol, "Bi");
        strcpy(answer, "Bismuth");
        break;

        case 83:
        strcpy(symbol, "Po");
        strcpy(answer, "Polonium");
        break;

        case 84:
        strcpy(symbol, "At");
        strcpy(answer, "Astatine");
        break;

        case 85:
        strcpy(symbol, "Rn");
        strcpy(answer, "Radon");
        break;

        case 86:
        strcpy(symbol, "Fr");
        strcpy(answer, "Francium");
        break;

        case 87:
        strcpy(symbol, "Ra");
        strcpy(answer, "Radium");
        break;

        case 88:
        strcpy(symbol, "Ac");
        strcpy(answer, "Actinium");
        break;

        case 89:
        strcpy(symbol, "Th");
        strcpy(answer, "Thorium");
        break;

        case 90:
        strcpy(symbol, "Pa");
        strcpy(answer, "Protactinium");
        break;

        case 91:
        strcpy(symbol, "U");
        strcpy(answer, "Uranium");
        break;

        case 92:
        strcpy(symbol, "Np");
        strcpy(answer, "Neptunium");
        break;

        case 93:
        strcpy(symbol, "Pu");
        strcpy(answer, "Plutonium");
        break;

        case 94:
        strcpy(symbol, "Am");
        strcpy(answer, "Americium");
        break;

        case 95:
        strcpy(symbol, "Cm");
        strcpy(answer, "Curium");
        break;

        case 96:
        strcpy(symbol, "Bk");
        strcpy(answer, "Berkelium");
        break;

        case 97:
        strcpy(symbol, "Cf");
        strcpy(answer, "Californium");
        break;

        case 98:
        strcpy(symbol, "Es");
        strcpy(answer, "Einsteinium");
        break;

        case 99:
        strcpy(symbol, "Fm");
        strcpy(answer, "Fermium");
        break;

        case 100:
        strcpy(symbol, "Md");
        strcpy(answer, "Mendelevium");
        break;

        case 101:
        strcpy(symbol, "No");
        strcpy(answer, "Nobelium");
        break;

        case 102:
        strcpy(symbol, "Lr");
        strcpy(answer, "Lawrencium");
        break;

        case 103:
        strcpy(symbol, "Rf");
        strcpy(answer, "Rutherfordium");
        break;

        case 104:
        strcpy(symbol, "Db");
        strcpy(answer, "Dubnium");
        break;

        case 105:
        strcpy(symbol, "Sg");
        strcpy(answer, "Seaborgium");
        break;

        case 106:
        strcpy(symbol, "Bh");
        strcpy(answer, "Bohrium");
        break;

        case 107:
        strcpy(symbol, "Hs");
        strcpy(answer, "Hassium");
        break;

        case 108:
        strcpy(symbol, "Mt");
        strcpy(answer, "Meitnerium");
        break;

        case 109:
        strcpy(symbol, "Ds");
        strcpy(answer, "Darmstadtium");
        break;

        case 110:
        strcpy(symbol, "Rg");
        strcpy(answer, "Roentgenium");
        break;

        case 111:
        strcpy(symbol, "Cn");
        strcpy(answer, "Copernicium");
        break;

        case 112:
        strcpy(symbol, "Nh");
        strcpy(answer, "Nihonium");
        break;

        case 113:
        strcpy(symbol, "Fl");
        strcpy(answer, "Flerovium");
        break;

        case 114:
        strcpy(symbol, "Mc");
        strcpy(answer, "Moscovium");
        break;

        case 115:
        strcpy(symbol, "Lv");
        strcpy(answer, "Livermorium");
        break;

        case 116:
        strcpy(symbol, "Ts");
        strcpy(answer, "Tennessine");
        break;

        case 117:
        strcpy(symbol, "Og");
        strcpy(answer, "Oganesson");
        break;
    }

    printf("What element has the symbol '%s'? ", symbol);
    scanf("%s", answer);

    if(strcmp(answer, symbol) == 0) {
        printf("Well done! You're correct.\n");
    } else {
        printf("Wrong answer! The correct answer is '%s'.\n", symbol);
    }

    return 0;
}