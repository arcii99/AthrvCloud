//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Element{
    char name[20];
    char symbol[3];
    int atomic_number;
    char category[20];
    float atomic_weight;
};
typedef struct Element Element;

void print_separator(){
    printf("-------------------------------------------\n");
}

void print_welcome_message(){
    printf("Welcome to the Periodic Table Quiz in Medieval Style!\n\n");
    printf("Here are the rules:\n\n");
    printf("1. You will be asked a series of questions about the elements of the periodic table.\n");
    printf("2. For each question, you will need to enter the correct answer.\n");
    printf("3. If you answer correctly, you will score a point. If you answer incorrectly, you will not score any points.\n");
    printf("4. At the end of the quiz, your score will be displayed.\n");
    printf("\nAre you ready to begin the quiz?\n");
    printf("Press ENTER to start...\n");
    while(getchar() != '\n');
}

void initialize_elements_array(Element elements[]){
    Element hydrogen   = {"Hydrogen", "H ", 1, "Nonmetal", 1.008};
    Element helium     = {"Helium", "He", 2, "Noble gas", 4.0026};
    Element lithium    = {"Lithium", "Li", 3, "Alkali metal", 6.94};
    Element beryllium  = {"Beryllium", "Be", 4, "Alkaline earth metal", 9.0122};
    Element boron      = {"Boron", "B ", 5, "Metalloid", 10.81};
    Element carbon     = {"Carbon", "C ", 6, "Nonmetal", 12.011};
    Element nitrogen   = {"Nitrogen", "N ", 7, "Nonmetal", 14.007};
    Element oxygen     = {"Oxygen", "O ", 8, "Nonmetal", 15.999};
    Element fluorine   = {"Fluorine", "F ", 9, "Halogen", 18.998};
    Element neon       = {"Neon", "Ne", 10, "Noble gas", 20.180};

    elements[0] = hydrogen;
    elements[1] = helium;
    elements[2] = lithium;
    elements[3] = beryllium;
    elements[4] = boron;
    elements[5] = carbon;
    elements[6] = nitrogen;
    elements[7] = oxygen;
    elements[8] = fluorine;
    elements[9] = neon;
}

void shuffle_array(int arr[], int n){
    for(int i = n-1; i > 0; i--){
        int j = rand() % (i+1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void print_elements_table(Element elements[], int order[], int num_elements){
    printf("\n\nPeriodic Table:\n\n");

    printf(" %2d ", elements[order[0]].atomic_number);
    for(int i = 1; i < num_elements; i++){
        if(elements[order[i]].atomic_number == 1){
            printf(" |  ");
        }else if(i%18 == 1){
            printf(" \n-----|---");
        }else{
            printf(" |---");
        }
        printf(" %2d ", elements[order[i]].atomic_number);
    }
    printf(" |\n");

    printf(" %-3s", elements[order[0]].symbol);
    for(int i = 1; i < num_elements; i++){
        printf(" | %2s", elements[order[i]].symbol);
    }
    printf(" |\n");

    printf(" %-3s", elements[order[0]].name);
    for(int i = 1; i < num_elements; i++){
        printf(" | %2s", "");
    }
    printf(" |\n");

    printf(" %-3s", elements[order[0]].category);
    for(int i = 1; i < num_elements; i++){
        printf(" | %2s", elements[order[i]].category);
    }
    printf(" |\n");

    printf("\n");
}

int ask_question(Element elements[], int order[], int question_num){
    int ans;
    char ans_str[20];
    printf("\nQuestion %d:\n", question_num+1);
    printf("What is the symbol and name of element number %d in the periodic table?\n", order[question_num]);
    printf("Answer (e.g. He Helium): ");
    scanf("%s", ans_str);
    ans_str[strlen(ans_str)] = '\0';

    char sym[3];
    char name[20];
    sscanf(ans_str, "%s %s", sym, name);

    if(strcmp(sym, elements[order[question_num]-1].symbol) == 0 && strcmp(name, elements[order[question_num]-1].name) == 0){
        printf("Correct!\n");
        return 1;
    }else{
        printf("Incorrect. The correct answer is %s %s.\n", elements[order[question_num]-1].symbol, elements[order[question_num]-1].name);
        return 0;
    }
}

int main(){
    srand((unsigned int)time(NULL));

    Element elements[118];
    int order[118];
    int num_elements = 10;
    initialize_elements_array(elements);
    for(int i = 0; i < num_elements; i++){
        order[i] = i+1;
    }
    shuffle_array(order, num_elements);

    int num_questions = 5;
    int score = 0;

    print_welcome_message();

    for(int i = 0; i < num_questions; i++){
        print_separator();
        print_elements_table(elements, order, num_elements);
        score += ask_question(elements, order, i);
    }

    print_separator();
    printf("Quiz is over!\n");
    printf("Your score is: %d/%d\n", score, num_questions);

    return 0;
}