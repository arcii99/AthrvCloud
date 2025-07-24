//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

// Function to display the quiz instructions
void displayInstructions(){
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("In this quiz, you will be asked to identify the element based on its chemical symbol.\n");
    printf("You will have 4 options for each question and will have to select the correct one.\n");
    printf("You will get 1 point for each correct answer and there is no negative marking.\n");
    printf("Press any key to start the quiz.\n");
    getchar(); // Wait for any key input from the user
}

// Structure to store the element details
struct Element{
    char symbol[3];
    char name[20];
};

// Function to generate a random number between min and max
int getRandomNumber(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

// Function to generate a random quiz question
void generateQuizQuestion(struct Element elements[118]){
    // Generate a random index for the correct element
    int correctIndex = getRandomNumber(0, 117);
    
    // Generate random indices for the 3 incorrect options
    int optionIndices[3];
    optionIndices[0] = getRandomNumber(0, 117);
    optionIndices[1] = getRandomNumber(0, 117);
    optionIndices[2] = getRandomNumber(0, 117);
    
    // Check if any of the other indices match the correct index
    // If yes, re-generate the index until it is not the same as the correct index
    int i;
    for(i=0; i<3; i++){
        while(optionIndices[i] == correctIndex){
            optionIndices[i] = getRandomNumber(0, 117);
        }
    }
    
    // Display the quiz question and options
    printf("What is the chemical symbol for %s?\n", elements[correctIndex].name);
    printf("a. %s  b. %s  c. %s  d. %s\n", 
            elements[optionIndices[0]].symbol,
            elements[optionIndices[1]].symbol,
            elements[optionIndices[2]].symbol,
            elements[correctIndex].symbol);
    
    // Get the user's choice and check if it is correct
    char choice;
    printf("Enter your choice (a/b/c/d): ");
    scanf("%c", &choice);
    getchar(); // Consume the newline character
    if(tolower(choice) == 'd'){
        printf("Congratulations, your answer is correct!\n");
    } else {
        printf("Sorry, your answer is incorrect.\n");
    }
}

int main(){
    // Seed the random number generator
    srand(time(NULL));
    
    // Initialize the array of elements
    struct Element elements[118] = {
        {"H", "Hydrogen"}, {"He", "Helium"}, {"Li", "Lithium"}, {"Be", "Beryllium"},
        {"B", "Boron"}, {"C", "Carbon"}, {"N", "Nitrogen"}, {"O", "Oxygen"},
        {"F", "Fluorine"}, {"Ne", "Neon"}, {"Na", "Sodium"}, {"Mg", "Magnesium"},
        {"Al", "Aluminum"}, {"Si", "Silicon"}, {"P", "Phosphorus"}, {"S", "Sulfur"},
        {"Cl", "Chlorine"}, {"Ar", "Argon"}, {"K", "Potassium"}, {"Ca", "Calcium"},
        {"Sc", "Scandium"}, {"Ti", "Titanium"}, {"V", "Vanadium"}, {"Cr", "Chromium"},
        {"Mn", "Manganese"}, {"Fe", "Iron"}, {"Co", "Cobalt"}, {"Ni", "Nickel"},
        {"Cu", "Copper"}, {"Zn", "Zinc"}, {"Ga", "Gallium"}, {"Ge", "Germanium"},
        {"As", "Arsenic"}, {"Se", "Selenium"}, {"Br", "Bromine"}, {"Kr", "Krypton"},
        {"Rb", "Rubidium"}, {"Sr", "Strontium"}, {"Y", "Yttrium"}, {"Zr", "Zirconium"},
        {"Nb", "Niobium"}, {"Mo", "Molybdenum"}, {"Tc", "Technetium"}, {"Ru", "Ruthenium"},
        {"Rh", "Rhodium"}, {"Pd", "Palladium"}, {"Ag", "Silver"}, {"Cd", "Cadmium"},
        {"In", "Indium"}, {"Sn", "Tin"}, {"Sb", "Antimony"}, {"Te", "Tellurium"},
        {"I", "Iodine"}, {"Xe", "Xenon"}, {"Cs", "Cesium"}, {"Ba", "Barium"},
        {"La", "Lanthanum"}, {"Ce", "Cerium"}, {"Pr", "Praseodymium"}, {"Nd", "Neodymium"},
        {"Pm", "Promethium"}, {"Sm", "Samarium"}, {"Eu", "Europium"}, {"Gd", "Gadolinium"},
        {"Tb", "Terbium"}, {"Dy", "Dysprosium"}, {"Ho", "Holmium"}, {"Er", "Erbium"},
        {"Tm", "Thulium"}, {"Yb", "Ytterbium"}, {"Lu", "Lutetium"}, {"Hf", "Hafnium"},
        {"Ta", "Tantalum"}, {"W", "Tungsten"}, {"Re", "Rhenium"}, {"Os", "Osmium"},
        {"Ir", "Iridium"}, {"Pt", "Platinum"}, {"Au", "Gold"}, {"Hg", "Mercury"},
        {"Tl", "Thallium"}, {"Pb", "Lead"}, {"Bi", "Bismuth"}, {"Po", "Polonium"},
        {"At", "Astatine"}, {"Rn", "Radon"}, {"Fr", "Francium"}, {"Ra", "Radium"},
        {"Ac", "Actinium"}, {"Th", "Thorium"}, {"Pa", "Protactinium"}, {"U", "Uranium"},
        {"Np", "Neptunium"}, {"Pu", "Plutonium"}, {"Am", "Americium"}, {"Cm", "Curium"},
        {"Bk", "Berkelium"}, {"Cf", "Californium"}, {"Es", "Einsteinium"}, {"Fm", "Fermium"},
        {"Md", "Mendelevium"}, {"No", "Nobelium"}, {"Lr", "Lawrencium"}, {"Rf", "Rutherfordium"},
        {"Db", "Dubnium"}, {"Sg", "Seaborgium"}, {"Bh", "Bohrium"}, {"Hs", "Hassium"},
        {"Mt", "Meitnerium"}, {"Ds", "Darmstadtium"}, {"Rg", "Roentgenium"}, {"Cn", "Copernicium"},
        {"Nh", "Nihonium"}, {"Fl", "Flerovium"}, {"Mc", "Moscovium"}, {"Lv", "Livermorium"},
        {"Ts", "Tennessine"}, {"Og", "Oganesson"}
    };
    
    // Display the quiz instructions
    displayInstructions();
    
    // Start the quiz
    int i, score = 0;
    for(i=0; i<10; i++){ // Ask 10 questions
        printf("Question %d\n", i+1);
        generateQuizQuestion(elements);
        score++; // Add 1 to the score for each correct answer
    }
    
    // Display the final score
    printf("Your final score is %d out of 10!\n", score);
    
    return 0;
}