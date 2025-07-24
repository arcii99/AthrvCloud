//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    srand(time(NULL));
    char elements[118][3] = { //list of elements for periodic table
        "H ","He","Li","Be","B ","C ","N ","O ","F ","Ne","Na","Mg","Al",
        "Si","P ","S ","Cl","Ar","K ","Ca","Sc","Ti","V ","Cr","Mn","Fe",
        "Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr","Rb","Sr","Y ",
        "Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te",
        "I ","Xe","Cs","Ba","La","Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb",
        "Dy","Ho","Er","Tm","Yb","Lu","Hf","Ta","W ","Re","Os","Ir","Pt",
        "Au","Hg","Tl","Pb","Bi","Po","At","Rn","Fr","Ra","Ac","Th","Pa",
        "U ","Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No","Lr"
    };
    int correct_answer, user_answer;
    int element_index = rand() % 118; //randomly select an element from the list
    printf("What is the atomic number of %s?\n", elements[element_index]);
    switch(element_index) { //switch statements to assign the correct atomic number
        case 0: correct_answer = 1; break;
        case 1: correct_answer = 2; break;
        case 2: correct_answer = 3; break;
        case 3: correct_answer = 4; break;
        case 4: correct_answer = 5; break;
        case 5: correct_answer = 6; break;
        case 6: correct_answer = 7; break;
        case 7: correct_answer = 8; break;
        case 8: correct_answer = 9; break;
        case 9: correct_answer = 10; break;
        case 10: correct_answer = 11; break;
        case 11: correct_answer = 12; break;
        case 12: correct_answer = 13; break;
        case 13: correct_answer = 14; break;
        case 14: correct_answer = 15; break;
        case 15: correct_answer = 16; break;
        case 16: correct_answer = 17; break;
        case 17: correct_answer = 18; break;
        case 18: correct_answer = 19; break;
        case 19: correct_answer = 20; break;
        case 20: case 21: case 22: case 23: case 24: case 25: case 26: case 27: case 28: case 29: case 30: case 31: case 32: case 33: case 34: case 35: case 36: //all elements from potassium to krypton have atomic number 39-36 respectively
            correct_answer = element_index - 18;
            break;
        case 37: case 38: //all elements from rubidium to strontium have atomic number 37-38 respectively
            correct_answer = element_index - 18;
            break;
        case 39: case 40: //all elements from yttrium to zirconium have atomic number 39-40 respectively
            correct_answer = element_index - 16;
            break;
        case 41: case 42: case 43: case 44: case 45: case 46: case 47: case 48: case 49: case 50: case 51: case 52: case 53: case 54: //all elements from niobium to xenon have atomic number 41-54 respectively
            correct_answer = element_index - 20;
            break;
        case 55: case 56: //all elements from caesium to barium have atomic number 55-56 respectively
            correct_answer = element_index - 13;
            break;
        case 57: case 58: case 59: case 60: case 61: case 62: case 63: case 64: case 65: case 66: case 67: case 68: case 69: case 70: case 71: //all elements from lanthanum to lutetium have atomic number 57-71 respectively
            correct_answer = element_index - 32;
            break;
        case 72: case 73: case 74: case 75: case 76: case 77: case 78: case 79: case 80: case 81: case 82: case 83: case 84: case 85: case 86: //all elements from hafnium to radon have atomic number 72-86 respectively
            correct_answer = element_index - 28;
            break;
        case 87: case 88: //all elements from francium to radium have atomic number 87-88 respectively
            correct_answer = element_index - 55;
            break;
        case 89: case 90: case 91: case 92: case 93: case 94: case 95: case 96: case 97: case 98: case 99: case 100: case 101: case 102: case 103: //all elements from actinium to lawrencium have atomic number 89-103 respectively
            correct_answer = element_index - 56;
            break;
        case 104: case 105: case 106: case 107: case 108: case 109: case 110: case 111: case 112: //all elements from rutherfordium to copernicium have atomic number 104-112 respectively
            correct_answer = element_index - 73;
            break;
        case 113: //all elements beyond that have atomic number assigned to themselves
            correct_answer = 113;
            break;
        case 114:
            correct_answer = 114;
            break;
        case 115:
            correct_answer = 115;
            break;
        case 116:
            correct_answer = 116;
            break;
        case 117:
            correct_answer = 117;
            break;
        default:
            printf("Error: element not found.\n");
            return 1;
    }
    printf("Enter your answer: ");
    scanf("%d", &user_answer);
    if(user_answer == correct_answer) {
        printf("Correct answer!\n");
    }
    else {
        printf("Incorrect answer. The correct answer is %d.\n", correct_answer);
    }
    return 0;
}