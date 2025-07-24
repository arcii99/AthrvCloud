//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENT_NAME_LENGTH 30
#define MAX_ELEMENT_SYMBOL_LENGTH 3

typedef struct element {
    char name[MAX_ELEMENT_NAME_LENGTH];
    char symbol[MAX_ELEMENT_SYMBOL_LENGTH];
    int atomic_number;
} element_t;

element_t *create_element(char *name, char *symbol, int atomic_number) {
    element_t *new_element = malloc(sizeof(element_t));
    strcpy(new_element->name, name);
    strcpy(new_element->symbol, symbol);
    new_element->atomic_number = atomic_number;
    return new_element;
}

void print_table(element_t **table, int rows, int cols) {
    printf("\n=================================================================\n");
    printf("%-4s %-3s %-20s\n", "Num", "Sym", "Name");
    printf("-----------------------------------------------------------------\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%-4d %-3s %-20s", table[i*cols+j]->atomic_number, table[i*cols+j]->symbol, table[i*cols+j]->name);
        }
        printf("\n-----------------------------------------------------------------\n");
    }
    printf("=================================================================\n");
}

int main() {
    int rows = 7;
    int cols = 18;
    element_t **periodic_table = malloc(rows*cols*sizeof(element_t));

    periodic_table[0] = create_element("Hydrogen","H",1);
    periodic_table[1] = create_element("Helium","He",2);
    periodic_table[2] = create_element("Lithium","Li",3);
    periodic_table[3] = create_element("Beryllium","Be",4);
    periodic_table[4] = create_element("Boron","B",5);
    periodic_table[5] = create_element("Carbon","C",6);
    periodic_table[6] = create_element("Nitrogen","N",7);
    periodic_table[7] = create_element("Oxygen","O",8);
    periodic_table[8] = create_element("Fluorine","F",9);
    periodic_table[9] = create_element("Neon","Ne",10);
    periodic_table[10] = create_element("Sodium","Na",11);
    periodic_table[11] = create_element("Magnesium","Mg",12);
    periodic_table[12] = create_element("Aluminum","Al",13);
    periodic_table[13] = create_element("Silicon","Si",14);
    periodic_table[14] = create_element("Phosphorus","P",15);
    periodic_table[15] = create_element("Sulfur","S",16);
    periodic_table[16] = create_element("Chlorine","Cl",17);
    periodic_table[17] = create_element("Argon","Ar",18);
    periodic_table[18] = create_element("Potassium","K",19);
    periodic_table[19] = create_element("Calcium","Ca",20);
    periodic_table[20] = create_element("Scandium","Sc",21);
    periodic_table[21] = create_element("Titanium","Ti",22);
    periodic_table[22] = create_element("Vanadium","V",23);
    periodic_table[23] = create_element("Chromium","Cr",24);
    periodic_table[24] = create_element("Manganese","Mn",25);
    periodic_table[25] = create_element("Iron","Fe",26);
    periodic_table[26] = create_element("Cobalt","Co",27);
    periodic_table[27] = create_element("Nickel","Ni",28);
    periodic_table[28] = create_element("Copper","Cu",29);
    periodic_table[29] = create_element("Zinc","Zn",30);
    periodic_table[30] = create_element("Gallium","Ga",31);
    periodic_table[31] = create_element("Germanium","Ge",32);
    periodic_table[32] = create_element("Arsenic","As",33);
    periodic_table[33] = create_element("Selenium","Se",34);
    periodic_table[34] = create_element("Bromine","Br",35);
    periodic_table[35] = create_element("Krypton","Kr",36);
    periodic_table[36] = create_element("Rubidium","Rb",37);
    periodic_table[37] = create_element("Strontium","Sr",38);
    periodic_table[38] = create_element("Yttrium","Y",39);
    periodic_table[39] = create_element("Zirconium","Zr",40);
    periodic_table[40] = create_element("Niobium","Nb",41);
    periodic_table[41] = create_element("Molybdenum","Mo",42);
    periodic_table[42] = create_element("Technetium","Tc",43);
    periodic_table[43] = create_element("Ruthenium","Ru",44);
    periodic_table[44] = create_element("Rhodium","Rh",45);
    periodic_table[45] = create_element("Palladium","Pd",46);
    periodic_table[46] = create_element("Silver","Ag",47);
    periodic_table[47] = create_element("Cadmium","Cd",48);
    periodic_table[48] = create_element("Indium","In",49);
    periodic_table[49] = create_element("Tin","Sn",50);
    periodic_table[50] = create_element("Antimony","Sb",51);
    periodic_table[51] = create_element("Tellurium","Te",52);
    periodic_table[52] = create_element("Iodine","I",53);
    periodic_table[53] = create_element("Xenon","Xe",54);
    periodic_table[54] = create_element("Cesium","Cs",55);
    periodic_table[55] = create_element("Barium","Ba",56);
    periodic_table[56] = create_element("Lanthanum","La",57);
    periodic_table[57] = create_element("Cerium","Ce",58);
    periodic_table[58] = create_element("Praseodymium","Pr",59);
    periodic_table[59] = create_element("Neodymium","Nd",60);
    periodic_table[60] = create_element("Promethium","Pm",61);
    periodic_table[61] = create_element("Samarium","Sm",62);
    periodic_table[62] = create_element("Europium","Eu",63);
    periodic_table[63] = create_element("Gadolinium","Gd",64);
    periodic_table[64] = create_element("Terbium","Tb",65);
    periodic_table[65] = create_element("Dysprosium","Dy",66);
    periodic_table[66] = create_element("Holmium","Ho",67);
    periodic_table[67] = create_element("Erbium","Er",68);
    periodic_table[68] = create_element("Thulium","Tm",69);
    periodic_table[69] = create_element("Ytterbium","Yb",70);
    periodic_table[70] = create_element("Lutetium","Lu",71);
    periodic_table[71] = create_element("Hafnium","Hf",72);
    periodic_table[72] = create_element("Tantalum","Ta",73);
    periodic_table[73] = create_element("Tungsten","W",74);
    periodic_table[74] = create_element("Rhenium","Re",75);
    periodic_table[75] = create_element("Osmium","Os",76);
    periodic_table[76] = create_element("Iridium","Ir",77);
    periodic_table[77] = create_element("Platinum","Pt",78);
    periodic_table[78] = create_element("Gold","Au",79);
    periodic_table[79] = create_element("Mercury","Hg",80);
    periodic_table[80] = create_element("Thallium","Tl",81);
    periodic_table[81] = create_element("Lead","Pb",82);
    periodic_table[82] = create_element("Bismuth","Bi",83);
    periodic_table[83] = create_element("Polonium","Po",84);
    periodic_table[84] = create_element("Astatine","At",85);
    periodic_table[85] = create_element("Radon","Rn",86);
    periodic_table[86] = create_element("Francium","Fr",87);
    periodic_table[87] = create_element("Radium","Ra",88);
    periodic_table[88] = create_element("Actinium","Ac",89);
    periodic_table[89] = create_element("Thorium","Th",90);
    periodic_table[90] = create_element("Protactinium","Pa",91);
    periodic_table[91] = create_element("Uranium","U",92);
    periodic_table[92] = create_element("Neptunium","Np",93);
    periodic_table[93] = create_element("Plutonium","Pu",94);
    periodic_table[94] = create_element("Americium","Am",95);
    periodic_table[95] = create_element("Curium","Cm",96);
    periodic_table[96] = create_element("Berkelium","Bk",97);
    periodic_table[97] = create_element("Californium","Cf",98);
    periodic_table[98] = create_element("Einsteinium","Es",99);
    periodic_table[99] = create_element("Fermium","Fm",100);
    periodic_table[100] = create_element("Mendelevium","Md",101);
    periodic_table[101] = create_element("Nobelium","No",102);
    periodic_table[102] = create_element("Lawrencium","Lr",103);
    periodic_table[103] = create_element("Rutherfordium","Rf",104);
    periodic_table[104] = create_element("Dubnium","Db",105);
    periodic_table[105] = create_element("Seaborgium","Sg",106);
    periodic_table[106] = create_element("Bohrium","Bh",107);
    periodic_table[107] = create_element("Hassium","Hs",108);
    periodic_table[108] = create_element("Meitnerium","Mt",109);
    periodic_table[109] = create_element("Darmstadtium","Ds",110);
    periodic_table[110] = create_element("Roentgenium","Rg",111);
    periodic_table[111] = create_element("Copernicium","Cn",112);
    periodic_table[112] = create_element("Nihonium","Nh",113);
    periodic_table[113] = create_element("Flerovium","Fl",114);
    periodic_table[114] = create_element("Moscovium","Mc",115);
    periodic_table[115] = create_element("Livermorium","Lv",116);
    periodic_table[116] = create_element("Tennessine","Ts",117);
    periodic_table[117] = create_element("Oganesson","Og",118);

    print_table(periodic_table, rows, cols);

    printf("\n\nKeep Learning and Exploring Chemistry! :)\n");
    return 0;
}