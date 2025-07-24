//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: medieval
#include <stdio.h>
#include <string.h>

int main()
{
  // Define the periodic table elements with their medieval names and symbols
  char elements[118][50] = {
    {"Fyrngurgium - Fg"},
    {"Aurum - Au"},
    {"Stannum - Sn"},
    {"Ferrum - Fe"},
    {"Argentum - Ag"},
    {"Plumbum - Pb"},
    {"Cuprum - Cu"},
    {"Natrium - Na"},
    {"Kalium - K"},
    {"Calcium - Ca"},
    {"Magnesium - Mg"},
    {"Zincum - Zn"},
    {"Sulfur - S"},
    {"Carbon - C"},
    {"Borium - B"},
    {"Silicium - Si"},
    {"Phosphorus - P"},
    {"Deuterium - D"},
    {"Hydrogenium - H"},
    {"Helium - He"},
    {"Lithium - Li"},
    {"Berillium - Be"},
    {"Beryllium - Be"},
    {"Boron - B"},
    {"Graphene - Gr"},
    {"Nitrogen - N"},
    {"Oxygenium - O"},
    {"Fluor - F"},
    {"Chlorum - Cl"},
    {"Natrium chloratum - NaCl"},
    {"Pyrite - FeS2"},
    {"Galena - PbS"},
    {"Sphalerite - ZnS"},
    {"Ferrous oxide - FeO"},
    {"Cupric oxide - CuO"},
    {"Potassium carbonate - K2CO3"},
    {"Soda ash - Na2CO3"},
    {"Quicklime - CaO"},
    {"Magnesia - MgO"},
    {"Malachite - Cu2CO3(OH)2"},
    {"Calomel - Hg2Cl2"},
    {"Realgar - As4S4"},
    {"Orpiment - As2S3"},
    {"Alma mater - Al2O3"},
    {"Hematite - Fe2O3"},
    {"Cinnabar - HgS"},
    {"Mercurius - Hg"},
    {"Aqua fortis - HNO3"},
    {"Aqua regia - HNO3 and HCl"},
    {"Vitriol - FeSO4 and CuSO4"}
  };

  int num_of_elements = sizeof(elements) / sizeof(elements[0]);

  int score = 0;
  char answer[50];
  int index;
  char medieval_name[50];
  char medieval_symbol[5];

  // Loop through all the elements
  for(int i = 0; i < num_of_elements; i++){
    index = i + 1;
    strcpy(medieval_name, strtok(elements[i], "-"));
    strcpy(medieval_symbol, strtok(NULL, "-"));

    // Ask the user for the symbol of the element
    printf("What is the symbol for %s (Element # %d)?\n", medieval_name, index);
    scanf("%s", answer);

    // Check if the user's answer is correct
    if(strcmp(answer, medieval_symbol) == 0){
      printf("Correct!\n");
      score++;
    } else {
      printf("Incorrect. The correct answer is %s\n", medieval_symbol);
    }
  }

  // Print the final score
  printf("Your final score is %d out of %d\n", score, num_of_elements);

  return 0;
}