//FormAI DATASET v1.0 Category: Poker Game ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int rands(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

void shuffle(int* deck, int size){
    for(int i=0; i<size; i++){
        int randomIndex = rands(i, size-1);
        int temp = deck[i];
        deck[i] = deck[randomIndex];
        deck[randomIndex] = temp;
    }
}

void printCard(int card){
    char suits[4] = {'H', 'C', 'D', 'S'};
    char names[13][2] = {
        {'A', '\0'}, {'2', '\0'}, {'3', '\0'},
        {'4', '\0'}, {'5', '\0'}, {'6', '\0'},
        {'7', '\0'}, {'8', '\0'}, {'9', '\0'},
        {'T', '\0'}, {'J', '\0'}, {'Q', '\0'},
        {'K', '\0'}
    };
    printf("%c%c ", names[card/4][0], suits[card%4]);
}

void printHand(int* hand, int size){
    for(int i=0; i<size; i++){
        printCard(hand[i]);
    }
    printf("\n");
}

int hasPair(int* hand, int size){
    int count[13] = {0};
    for(int i=0; i<size; i++){
        count[hand[i]/4]++;
    }
    for(int i=0; i<13; i++){
        if(count[i] == 2){
            return 1;
        }
    }
    return 0;
}

int hasTwoPair(int* hand, int size){
    int count[13] = {0};
    int pairs = 0;
    for(int i=0; i<size; i++){
        count[hand[i]/4]++;
    }
    for(int i=0; i<13; i++){
        if(count[i] == 2){
            pairs++;
        }
    }
    if(pairs == 2){
        return 1;
    }
    return 0;
}

int hasThreeOfAKind(int* hand, int size){
    int count[13] = {0};
    for(int i=0; i<size; i++){
        count[hand[i]/4]++;
    }
    for(int i=0; i<13; i++){
        if(count[i] == 3){
            return 1;
        }
    }
    return 0;
}

int hasStraight(int* hand, int size){
    int count[13] = {0};
    for(int i=0; i<size; i++){
        count[hand[i]/4]++;
    }
    int consecutive = 0;
    for(int i=0; i<13; i++){
        if(count[i] > 0){
            consecutive++;
            if(consecutive == 5){
                return 1;
            }
        }else{
            consecutive = 0;
        }
    }
    return 0;
}

int hasFlush(int* hand, int size){
    int count[4] = {0};
    for(int i=0; i<size; i++){
        count[hand[i]%4]++;
    }
    for(int i=0; i<4; i++){
        if(count[i] == 5){
            return 1;
        }
    }
    return 0;
}

int hasFullHouse(int* hand, int size){
    int count[13] = {0};
    int hasPair = 0;
    int hasThree = 0;
    for(int i=0; i<size; i++){
        count[hand[i]/4]++;
    }
    for(int i=0; i<13; i++){
        if(count[i] == 2){
            hasPair = 1;
        }
        if(count[i] == 3){
            hasThree = 1;
        }
    }
    if(hasPair && hasThree){
        return 1;
    }
    return 0;
}

int hasFourOfAKind(int* hand, int size){
    int count[13] = {0};
    for(int i=0; i<size; i++){
        count[hand[i]/4]++;
    }
    for(int i=0; i<13; i++){
        if(count[i] == 4){
            return 1;
        }
    }
    return 0;
}

int hasStraightFlush(int* hand, int size){
    if(hasStraight(hand, size) && hasFlush(hand, size)){
        return 1;
    }
    return 0;
}

int hasRoyalFlush(int* hand, int size){
    int count[13] = {0};
    int flush = 0;
    for(int i=0; i<size; i++){
        count[hand[i]/4]++;
    }
    for(int i=0; i<4; i++){
        if(count[9+i] == 1 && count[10+i] == 1 &&
           count[11+i] == 1 && count[12+i] == 1 && count[0+i]){
            flush = 1;
            break;
        }
    }
    if(flush){
        return 1;
    }
    return 0;
}

int getHandRank(int* hand, int size){
    if(hasRoyalFlush(hand, size)){
        return 10;
    }else if(hasStraightFlush(hand, size)){
        return 9;
    }else if(hasFourOfAKind(hand, size)){
        return 8;
    }else if(hasFullHouse(hand, size)){
        return 7;
    }else if(hasFlush(hand, size)){
        return 6;
    }else if(hasStraight(hand, size)){
        return 5;
    }else if(hasThreeOfAKind(hand, size)){
        return 4;
    }else if(hasTwoPair(hand, size)){
        return 3;
    }else if(hasPair(hand, size)){
        return 2;
    }else{
        return 1;
    }
}

int compareHands(int* hand1, int* hand2, int size){
    int rank1 = getHandRank(hand1, size);
    int rank2 = getHandRank(hand2, size);
    if(rank1 > rank2){
        return 1;
    }else if(rank2 > rank1){
        return -1;
    }else{
        int count1[13] = {0};
        int count2[13] = {0};
        for(int i=0; i<size; i++){
            count1[hand1[i]/4]++;
            count2[hand2[i]/4]++;
        }
        if(rank1 == 10 || rank1 == 9 || rank1 == 6){
            return 0;
        }else if(rank1 == 8 || rank1 == 7 || rank1 == 4){
            int card1, card2;
            for(int i=0; i<13; i++){
                if(count1[i] == 4){
                    card1 = i;
                }
                if(count2[i] == 4){
                    card2 = i;
                }
            }
            if(card1 > card2){
                return 1;
            }else if(card2 > card1){
                return -1;
            }else{
                return 0;
            }
        }else if(rank1 == 5){
            int card1 = -1, card2 = -1;
            for(int i=0; i<13; i++){
                if(count1[i] == 1){
                    card1 = i;
                }
                if(count2[i] == 1){
                    card2 = i;
                }
            }
            if(card1 > card2){
                return 1;
            }else if(card2 > card1){
                return - 1;
            }else{
                return 0;
            }
        }else if(rank1 == 3){
            int highPair1 = -1, highPair2 = -1, lowPair1 = -1, lowPair2 = -1, kicker1 = -1, kicker2 = -1;
            for(int i=0; i<13; i++){
                if(count1[i] == 2){
                    if(i > highPair1){
                        lowPair1 = highPair1;
                        highPair1 = i;
                    }else{
                        lowPair1 = i;
                    }
                }
                if(count2[i] == 2){
                    if(i > highPair2){
                        lowPair2 = highPair2;
                        highPair2 = i;
                    }else{
                        lowPair2 = i;
                    }
                }
                if(count1[i] == 1 && i > kicker1){
                    kicker1 = i;
                }
                if(count2[i] == 1 && i > kicker2){
                    kicker2 = i;
                }
            }
            if(highPair1 > highPair2){
                return 1;
            }else if(highPair2 > highPair1){
                return -1;
            }else{
                if(lowPair1 > lowPair2){
                    return 1;  
                }else if(lowPair2 > lowPair1){
                    return -1;
                }else{
                    if(kicker1 > kicker2){
                        return 1;
                    }else if(kicker2 > kicker1){
                        return -1;
                    }else{
                        return 0;
                    }
                }
            }
        }else if(rank1 == 2){
            int pair1 = -1, pair2 = -1, kicker1 = -1, kicker2 = -1;
            for(int i=0; i<13; i++){
                if(count1[i] == 2){
                    pair1 = i;
                }
                if(count2[i] == 2){
                    pair2 = i;
                }
                if(count1[i] == 1 && i > kicker1){
                    kicker1 = i;
                }
                if(count2[i] == 1 && i > kicker2){
                    kicker2 = i;
                }
            }
            if(pair1 > pair2){
                return 1;
            }else if(pair2 > pair1){
                return -1;
            }else{
                if(kicker1 > kicker2){
                    return 1;
                }else if(kicker2 > kicker1){
                    return -1;
                }else{
                    return 0;
                }
            }
        }else{
            int kicker1 = -1, kicker2 = -1;
            for(int i=0; i<13; i++){
                if(count1[i] == 1 && i > kicker1){
                    kicker1 = i;
                }
                if(count2[i] == 1 && i > kicker2){
                    kicker2 = i;
                }
            }
            if(kicker1 > kicker2){
                return 1;
            }else if(kicker2 > kicker1){
                return -1;
            }else{
                return 0;
            }
        }
    }
}

int main(){
    srand(time(NULL));
    int deck[52];
    for(int i=0; i<52; i++){
        deck[i] = i;
    }
    shuffle(deck, 52);
    int hands[5][5];
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            hands[i][j] = deck[i*5 + j];
        }
    }
    printf("Hand One: ");
    printHand(hands[0], 5);
    printf("Hand Two: ");
    printHand(hands[1], 5);
    int result = compareHands(hands[0], hands[1], 5);
    if(result == 1){
        printf("Hand One wins\n");
    }else if(result == -1){
        printf("Hand Two wins\n");
    }else{
        printf("Tie\n");
    }
    return 0;
}