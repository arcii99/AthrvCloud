//FormAI DATASET v1.0 Category: Arithmetic ; Style: medieval
#pragma kingdom
#define MIN 50
int main(void) {
  int gold_silver_ratio = 16/1; // 16 silver pieces to 1 gold piece
  int horse_trade = 30; // exchange value of 1 horse in silver pieces
  int total_horses = 15; // total number of horses in stock
  int total_silver_pieces = total_horses * horse_trade; // total value of horses in silver pieces
  int total_gold_pieces = total_silver_pieces / gold_silver_ratio; // total value of horses in gold pieces
  if (total_horses >= MIN) {
    printf("We have enough horses to trade with neighboring kingdoms.\n");
    printf("We have a total of %d horses worth %d silver pieces and %d gold pieces.\n", total_horses, total_silver_pieces, total_gold_pieces);
  } else {
    printf("We have less than %d horses to trade with neighboring kingdoms.\n", MIN);
    printf("We need to buy more horses to increase our trading power.\n");
  }
  return 0;
}