//FormAI DATASET v1.0 Category: Data mining ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define constants
#define MAX_NUM_ITEMS 1000
#define MAX_ITEM_NAME_LEN 50
#define MAX_NUM_TRANSACTIONS 10000
#define MAX_ITEMS_PER_TRANS 20

// Declare global variables
bool items[MAX_NUM_ITEMS]; // Whether an item is present or not
char itemNames[MAX_NUM_ITEMS][MAX_ITEM_NAME_LEN]; // Names of the items
int itemSupports[MAX_NUM_ITEMS]; // Support counts of the items
int numItems = 0; // Number of distinct items
int transactions[MAX_NUM_TRANSACTIONS][MAX_ITEMS_PER_TRANS]; // Transactions containing items
int numTransactions = 0; // Number of transactions

// Declare functions
void readItemNames(FILE *file);
void processTransactions(FILE *file);
void getItemSupports();
void printFrequentItemsets(int minSupp);
void printClosedItemsets(int minSupp);

int main() {
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Error reading file.\n");
        return 1;
    }

    readItemNames(file);
    processTransactions(file);
    getItemSupports();

    fclose(file);

    printf("Frequent itemsets:\n");
    printFrequentItemsets(3);

    printf("Closed itemsets:\n");
    printClosedItemsets(3);

    return 0;
}

// Read the names of the distinct items from the first line of the file
void readItemNames(FILE *file) {
    char *line = NULL;
    size_t len = 0;
    getline(&line, &len, file);

    char *token = strtok(line, " ");
    while (token != NULL) {
        strcpy(itemNames[numItems], token);
        items[numItems] = true;
        numItems++;
        token = strtok(NULL, " ");
    }

    free(line);
}

// Read the transactions from the rest of the file
void processTransactions(FILE *file) {
    char *line = NULL;
    size_t len = 0;

    while (getline(&line, &len, file) != -1) {
        char *token = strtok(line, " ");
        int i = 0;
        while (token != NULL) {
            int itemId = atoi(token);

            if (items[itemId - 1]) {
                transactions[numTransactions][i] = itemId - 1;
                i++;
            }

            token = strtok(NULL, " ");
        }

        numTransactions++;
    }

    free(line);
}

// Count the support of each item
void getItemSupports() {
    for (int i = 0; i < numItems; i++) {
        itemSupports[i] = 0;

        for (int j = 0; j < numTransactions; j++) {
            bool found = false;

            for (int k = 0; k < MAX_ITEMS_PER_TRANS && transactions[j][k] != -1; k++) {
                if (transactions[j][k] == i) {
                    found = true;
                    break;
                }
            }

            if (found) {
                itemSupports[i]++;
            }
        }
    }
}

// Print frequent itemsets with support greater than or equal to minSupp
void printFrequentItemsets(int minSupp) {
    int numItemsets = 0;
    int itemsets[MAX_NUM_ITEMS][MAX_ITEMS_PER_TRANS];

    for (int i = 0; i < numItems; i++) {
        if (itemSupports[i] >= minSupp) {
            itemsets[numItemsets][0] = i;
            itemsets[numItemsets][1] = -1;
            numItemsets++;
        }
    }

    for (int k = 2; k <= MAX_ITEMS_PER_TRANS; k++) {
        for (int i = 0; i < numItemsets; i++) {
            for (int j = i + 1; j < numItemsets; j++) {
                if (itemsets[i][k - 2] != itemsets[j][k - 2]) {
                    break;
                }

                int newItemset[MAX_ITEMS_PER_TRANS];

                for (int l = 0; l < k - 1; l++) {
                    newItemset[l] = itemsets[i][l];
                }

                newItemset[k - 1] = itemsets[j][k - 2];

                bool valid = true;

                for (int l = 0; l < k - 1; l++) {
                    for (int m = 0; m < k; m++) {
                        if (newItemset[l] == newItemset[m] || newItemset[m] == -1) {
                            continue;
                        }

                        int count = 0;

                        for (int n = 0; n < numTransactions; n++) {
                            bool found1 = false;
                            bool found2 = false;

                            for (int o = 0; o < MAX_ITEMS_PER_TRANS && transactions[n][o] != -1; o++) {
                                if (transactions[n][o] == newItemset[l]) {
                                    found1 = true;
                                }

                                if (transactions[n][o] == newItemset[m]) {
                                    found2 = true;
                                }
                            }

                            if (found1 && found2) {
                                count++;
                            }
                        }

                        if (count < minSupp) {
                            valid = false;
                            break;
                        }
                    }

                    if (!valid) {
                        break;
                    }
                }

                if (valid) {
                    int l = 0;
                    while (itemsets[numItemsets][l] != -1) {
                        l++;
                    }

                    for (int m = 0; m < k; m++) {
                        itemsets[numItemsets][l + m] = newItemset[m];
                    }

                    itemsets[numItemsets][l + k] = -1;
                    numItemsets++;
                }
            }
        }
    }

    for (int i = 0; i < numItemsets; i++) {
        printf("{ ");
        int j = 0;
        while (itemsets[i][j] != -1) {
            printf("%s ", itemNames[itemsets[i][j]]);
            j++;
        }
        printf("} (%d)\n", itemSupports[itemsets[i][0]]);
    }
}

// Print closed itemsets with support greater than or equal to minSupp
void printClosedItemsets(int minSupp) {
    int numClosedItemsets = 0;
    int closedItemsets[MAX_NUM_ITEMS][MAX_ITEMS_PER_TRANS];
    bool closedSet[MAX_NUM_ITEMS];

    for (int i = 0; i < numItems; i++) {
        closedSet[i] = true;
    }

    for (int i = 0; i < numItems; i++) {
        if (itemSupports[i] < minSupp) {
            closedSet[i] = false;
        }
    }

    for (int i = 0; i < numItems; i++) {
        if (closedSet[i]) {
            closedItemsets[numClosedItemsets][0] = i;
            closedItemsets[numClosedItemsets][1] = -1;
            numClosedItemsets++;
        }
    }

    for (int k = 2; k <= MAX_ITEMS_PER_TRANS; k++) {
        for (int i = 0; i < numClosedItemsets; i++) {
            bool isClosed = true;

            for (int j = 0; j < numItems; j++) {
                if (items[j] && closedSet[j] && itemSupports[j] >= minSupp) {
                    int newItemset[MAX_ITEMS_PER_TRANS];

                    for (int l = 0; l < k - 1; l++) {
                        newItemset[l] = closedItemsets[i][l];
                    }

                    newItemset[k - 1] = j;

                    bool valid = true;

                    for (int l = 0; l < k - 1; l++) {
                        int count1 = itemSupports[closedItemsets[i][l]];
                        int count2 = itemSupports[j];
                        int count3 = 0;

                        for (int m = 0; m < numTransactions; m++) {
                            bool found1 = false;
                            bool found2 = false;

                            for (int n = 0; n < MAX_ITEMS_PER_TRANS && transactions[m][n] != -1; n++) {
                                if (transactions[m][n] == closedItemsets[i][l]) {
                                    found1 = true;
                                }

                                if (transactions[m][n] == j) {
                                    found2 = true;
                                }
                            }

                            if (found1 && found2) {
                                count3++;
                            }
                        }

                        if (count1 == count2 && count3 == count1) {
                            valid = false;
                            break;
                        }
                    }

                    if (valid) {
                        int count1 = itemSupports[j];
                        int count2 = 0;

                        for (int l = 0; l < numTransactions; l++) {
                            bool found = true;

                            for (int m = 0; m < k; m++) {
                                if (transactions[l][m] == -1 || !closedSet[transactions[l][m]]) {
                                    found = false;
                                    break;
                                }
                            }

                            if (found) {
                                bool included = true;

                                for (int m = 0; m < k; m++) {
                                    if (transactions[l][m] == j) {
                                        included = false;
                                        break;
                                    }
                                }

                                if (included) {
                                    count2++;
                                }
                            }
                        }

                        if (count2 == count1) {
                            isClosed = false;
                            closedSet[j] = false;

                            int l = 0;
                            while (closedItemsets[numClosedItemsets][l] != -1) {
                                l++;
                            }

                            for (int m = 0; m < k; m++) {
                                closedItemsets[numClosedItemsets][l + m] = newItemset[m];
                            }

                            closedItemsets[numClosedItemsets][l + k] = -1;
                            numClosedItemsets++;
                        }
                    }
                }
            }

            if (isClosed) {
                printf("{ ");
                int j = 0;
                while (closedItemsets[i][j] != -1) {
                    printf("%s ", itemNames[closedItemsets[i][j]]);
                    j++;
                }
                printf("} (%d)\n", itemSupports[closedItemsets[i][0]]);
            }
        }
    }
}