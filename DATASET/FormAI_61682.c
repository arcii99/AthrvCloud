//FormAI DATASET v1.0 Category: Poker Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_PLAYERS 2
#define MAX_HAND_SIZE 5
#define MAX_BET 100

// Function prototypes
void shuffle_deck(int deck[]);
void deal_cards(int deck[], int hands[][MAX_HAND_SIZE]);
void print_hand(int hand[], int size);
int evaluate_hand(int hand[], int size);
void clear_buffer();

int main() {
  int deck[NUM_CARDS];
  int hands[NUM_PLAYERS][MAX_HAND_SIZE] = {0};
  int bets[NUM_PLAYERS] = {0};
  int bankrolls[NUM_PLAYERS] = {1000, 1000}; // Starting bankrolls of 1000 for each player
  int current_player = 0; // Start with player 1
  int num_cards_dealt = 0;
  int pot_size = 0;
  int round = 1;
  
  // Seed the random number generator
  srand(time(NULL));
  
  // Shuffle the deck
  shuffle_deck(deck);
  
  // Deal initial hand
  deal_cards(deck, hands);
  
  // Display initial hands
  printf("P1's Hand: ");
  print_hand(hands[0], MAX_HAND_SIZE);
  printf("\n");
  printf("P2's Hand: ");
  print_hand(hands[1], MAX_HAND_SIZE);
  printf("\n");
  
  // Round 1: Initial Bet
  printf("Round 1: Initial Bet\n");
  for (int i = 0; i < NUM_PLAYERS; i++) {
    printf("P%d, enter bet (max %d): ", i+1, MAX_BET);
    scanf("%d", &bets[i]);
    clear_buffer();
    
    // Check if bet is valid
    while (bets[i] < 0 || bets[i] > MAX_BET || bets[i] > bankrolls[i]) {
      printf("Invalid bet, try again: ");
      scanf("%d", &bets[i]);
      clear_buffer();
    }
    
    // Update bankroll and pot size
    bankrolls[i] -= bets[i];
    pot_size += bets[i];
  }
  
  // Display updated bankrolls and pot size
  printf("Pot size: %d\n", pot_size);
  printf("P1's Bankroll: %d\n", bankrolls[0]);
  printf("P2's Bankroll: %d\n", bankrolls[1]);
  
  // Round 2: Discard and Draw
  printf("Round 2: Discard and Draw\n");
  for (int i = 0; i < NUM_PLAYERS; i++) {
    printf("P%d, enter cards to discard (0 to 5): ", i+1);
    int num_cards_to_discard;
    scanf("%d", &num_cards_to_discard);
    clear_buffer();
    
    // Check if number of cards to discard is valid
    while (num_cards_to_discard < 0 || num_cards_to_discard > MAX_HAND_SIZE) {
      printf("Invalid number of cards to discard, try again: ");
      scanf("%d", &num_cards_to_discard);
      clear_buffer();
    }
    
    // Discard and draw new cards
    for (int j = 0; j < num_cards_to_discard; j++) {
      printf("Enter card to discard (1 to 5): ");
      int card_to_discard;
      scanf("%d", &card_to_discard);
      clear_buffer();
      
      while (card_to_discard < 1 || card_to_discard > MAX_HAND_SIZE) {
        printf("Invalid card to discard, try again: ");
        scanf("%d", &card_to_discard);
        clear_buffer();
      }
      
      // Replace discarded card with new card from deck
      hands[i][card_to_discard-1] = deck[num_cards_dealt];
      num_cards_dealt++;
    }
    
    // Print updated hand
    printf("P%d's New Hand: ", i+1);
    print_hand(hands[i], MAX_HAND_SIZE);
    printf("\n");
  }
  
  // Evaluate hands and determine winner
  int p1_score = evaluate_hand(hands[0], MAX_HAND_SIZE);
  int p2_score = evaluate_hand(hands[1], MAX_HAND_SIZE);
  
  if (p1_score > p2_score) {
    printf("P1 Wins!\n");
    bankrolls[0] += pot_size;
  }
  else if (p2_score > p1_score) {
    printf("P2 Wins!\n");
    bankrolls[1] += pot_size;
  }
  else {
    printf("Tie Game!\n");
    bankrolls[0] += pot_size / 2;
    bankrolls[1] += pot_size / 2;
  }
  
  // Display updated bankrolls
  printf("P1's Bankroll: %d\n", bankrolls[0]);
  printf("P2's Bankroll: %d\n", bankrolls[1]);
  
  return 0;
}

void shuffle_deck(int deck[]) {
  // Initialize deck with cards in order
  for (int i = 0; i < NUM_CARDS; i++) {
    deck[i] = i;
  }
  
  // Shuffle deck using Fisher-Yates algorithm
  for (int i = NUM_CARDS-1; i > 0; i--) {
    int j = rand() % (i+1);
    int temp = deck[i];
    deck[i] = deck[j];
    deck[j] = temp;
  }
}

void deal_cards(int deck[], int hands[][MAX_HAND_SIZE]) {
  // Deal initial hand to each player
  for (int i = 0; i < NUM_PLAYERS; i++) {
    for (int j = 0; j < MAX_HAND_SIZE; j++) {
      hands[i][j] = deck[j + (MAX_HAND_SIZE * i)];
    }
  }
}

void print_hand(int hand[], int size) {
  // Print each card in hand
  for (int i = 0; i < size; i++) {
    int card_number = hand[i] % 13;
    int suit_number = hand[i] / 13;
    char card_name[3];
    char suit_name[7];
    
    // Convert card number to name
    switch (card_number) {
      case 0: sprintf(card_name, "A"); break;
      case 9: sprintf(card_name, "T"); break;
      case 10: sprintf(card_name, "J"); break;
      case 11: sprintf(card_name, "Q"); break;
      case 12: sprintf(card_name, "K"); break;
      default: sprintf(card_name, "%d", card_number+1); break;
    }
    
    // Convert suit number to name
    switch (suit_number) {
      case 0: sprintf(suit_name, "Spades"); break;
      case 1: sprintf(suit_name, "Hearts"); break;
      case 2: sprintf(suit_name, "Diamonds"); break;
      case 3: sprintf(suit_name, "Clubs"); break;
      default: break;
    }
    
    printf("%s of %s ", card_name, suit_name);
  }
}

int evaluate_hand(int hand[], int size) {
  // TODO: Implement hand evaluation logic
  return 0;
}

void clear_buffer() {
  char c = getchar();
  while (c != '\n' && c != EOF) {
    c = getchar();
  }
}