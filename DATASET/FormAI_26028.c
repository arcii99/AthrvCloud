//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char symbol[3];
    char name[20];
    int atomic_number;
} element;

const element periodic_table[118] = {
    {"H",  "Hydrogen",          1},
    {"He", "Helium",            2},
    {"Li", "Lithium",           3},
    {"Be", "Beryllium",         4},
    {"B",  "Boron",             5},
    {"C",  "Carbon",            6},
    {"N",  "Nitrogen",          7},
    {"O",  "Oxygen",            8},
    {"F",  "Fluorine",          9},
    {"Ne", "Neon",             10},
    {"Na", "Sodium",           11},
    {"Mg", "Magnesium",        12},
    {"Al", "Aluminum",        13},
    {"Si", "Silicon",         14},
    {"P",  "Phosphorus",      15},
    {"S",  "Sulfur",          16},
    {"Cl", "Chlorine",        17},
    {"Ar", "Argon",           18},
    {"K",  "Potassium",       19},
    {"Ca", "Calcium",         20},
    {"Sc", "Scandium",        21},
    {"Ti", "Titanium",        22},
    {"V",  "Vanadium",        23},
    {"Cr", "Chromium",        24},
    {"Mn", "Manganese",       25},
    {"Fe", "Iron",            26},
    {"Co", "Cobalt",          27},
    {"Ni", "Nickel",          28},
    {"Cu", "Copper",          29},
    {"Zn", "Zinc",            30},
    {"Ga", "Gallium",         31},
    {"Ge", "Germanium",       32},
    {"As", "Arsenic",         33},
    {"Se", "Selenium",        34},
    {"Br", "Bromine",         35},
    {"Kr", "Krypton",         36},
    {"Rb", "Rubidium",        37},
    {"Sr", "Strontium",       38},
    {"Y",  "Yttrium",         39},
    {"Zr", "Zirconium",       40},
    {"Nb", "Niobium",         41},
    {"Mo", "Molybdenum",      42},
    {"Tc", "Technetium",      43},
    {"Ru", "Ruthenium",       44},
    {"Rh", "Rhodium",         45},
    {"Pd", "Palladium",       46},
    {"Ag", "Silver",          47},
    {"Cd", "Cadmium",         48},
    {"In", "Indium",          49},
    {"Sn", "Tin",             50},
    {"Sb", "Antimony",        51},
    {"Te", "Tellurium",       52},
    {"I",  "Iodine",          53},
    {"Xe", "Xenon",           54},
    {"Cs", "Cesium",          55},
    {"Ba", "Barium",          56},
    {"La", "Lanthanum",       57},
    {"Ce", "Cerium",          58},
    {"Pr", "Praseodymium",    59},
    {"Nd", "Neodymium",       60},
    {"Pm", "Promethium",      61},
    {"Sm", "Samarium",        62},
    {"Eu", "Europium",        63},
    {"Gd", "Gadolinium",      64},
    {"Tb", "Terbium",         65},
    {"Dy", "Dysprosium",      66},
    {"Ho", "Holmium",         67},
    {"Er", "Erbium",          68},
    {"Tm", "Thulium",         69},
    {"Yb", "Ytterbium",       70},
    {"Lu", "Lutetium",        71},
    {"Hf", "Hafnium",         72},
    {"Ta", "Tantalum",        73},
    {"W",  "Tungsten",        74},
    {"Re", "Rhenium",         75},
    {"Os", "Osmium",          76},
    {"Ir", "Iridium",         77},
    {"Pt", "Platinum",        78},
    {"Au", "Gold",            79},
    {"Hg", "Mercury",         80},
    {"Tl", "Thallium",        81},
    {"Pb", "Lead",            82},
    {"Bi", "Bismuth",         83},
    {"Po", "Polonium",        84},
    {"At", "Astatine",        85},
    {"Rn", "Radon",           86},
    {"Fr", "Francium",        87},
    {"Ra", "Radium",          88},
    {"Ac", "Actinium",        89},
    {"Th", "Thorium",         90},
    {"Pa", "Protactinium",    91},
    {"U",  "Uranium",         92},
    {"Np", "Neptunium",       93},
    {"Pu", "Plutonium",       94},
    {"Am", "Americium",       95},
    {"Cm", "Curium",          96},
    {"Bk", "Berkelium",       97},
    {"Cf", "Californium",     98},
    {"Es", "Einsteinium",     99},
    {"Fm", "Fermium",        100},
    {"Md", "Mendelevium",    101},
    {"No", "Nobelium",       102},
    {"Lr", "Lawrencium",     103},
    {"Rf", "Rutherfordium",  104},
    {"Db", "Dubnium",        105},
    {"Sg", "Seaborgium",     106},
    {"Bh", "Bohrium",        107},
    {"Hs", "Hassium",        108},
    {"Mt", "Meitnerium",     109},
    {"Ds", "Darmstadtium",   110},
    {"Rg", "Roentgenium",    111},
    {"Cn", "Copernicium",    112},
    {"Nh", "Nihonium",       113},
    {"Fl", "Flerovium",      114},
    {"Mc", "Moscovium",      115},
    {"Lv", "Livermorium",    116},
    {"Ts", "Tennessine",     117},
    {"Og", "Oganesson",      118}
};

int main(){
    printf("\n\t\tWELCOME TO THE PERIODIC TABLE QUIZ\n\n");
    printf("How well do you know the periodic table? Take this quiz to find out.\n");
    printf("There are 20 questions in the quiz and each question has four choices.\n");
    printf("Enter the correct option number to answer the questions.\n");
    printf("Let's get started!\n\n");

    int score = 0;

    for(int i=0;i<20;i++){
        printf("Question %d\n", i+1);
        int rnd_num = rand() % 118;

        printf("What is the atomic number of %s?\n", periodic_table[rnd_num].name);

        int correct_option = rand() % 4 + 1;
        int option_seq[] = {1,2,3,4};

        for(int j=0;j<4;j++){
            if(option_seq[j] == correct_option){
                printf("\t%d. %d\n", option_seq[j], periodic_table[rnd_num].atomic_number);
                continue;
            }
            int wrong_option;
            do{
                wrong_option = rand() % 118;
            } while(wrong_option == rnd_num || wrong_option == periodic_table[rnd_num].atomic_number);

            printf("\t%d. %d\n", option_seq[j], periodic_table[wrong_option].atomic_number);
        }

        int user_option;
        scanf("%d", &user_option);

        if(user_option == correct_option){
            printf("Correct Answer!\n\n");
            score++;
        } else {
            printf("Wrong Answer... Correct answer is %d\n\n", correct_option);
        }
    }

    printf("Quiz completed! Your score is %d/20\n", score);
    printf("\nThanks for playing the periodic table quiz..! Have a nice day!!\n");

    return 0;
}