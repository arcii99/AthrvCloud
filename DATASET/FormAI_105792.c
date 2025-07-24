//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Romeo and Juliet
/* 
 * The grand C Hotel had a management system,
 * A system so powerful and splendid,
 * Yet, its code was a sight quite frightful,
 * To the human eye, it was quite delightful.
 */

// Romeo, a hotel guest, enters his room and wants to checkout.
int main() {
    int roomNumber = 101;
    int nightsStayed = 3;
    double roomRate = 99.99;
    double totalBill = roomRate * nightsStayed;
    
    printf("My dearest system, please check me out of room %d\n", roomNumber);
    
    // The management system, in its majesty, responds with the bill.
    printf("My dear guest, your total bill comes to $%.2f\n", totalBill);
    
    // Not one to shy away, Romeo responds with a discount code.
    printf("Ah, but I have a code for 10 percent off! Behold - CODE10\n");
    printf("Please apply it to my bill.\n");
    
    // The system heard Romeo's plea and applies the discount code.
    char discountCode[] = "CODE10";
    double discountAmount = 0.0;
    
    if (strcmp(discountCode, "CODE10") == 0) {
        discountAmount = totalBill * 0.1;
        totalBill -= discountAmount;
        printf("Discount code applied! Your new total is $%.2f\n", totalBill);
    } else {
        printf("I'm sorry, that code is not valid. Your original total stands at $%.2f.\n", totalBill);
    }
    
    // Juliet, Romeo's lover, enters the scene as a hotel staff member.
    printf("Alas, my love, Juliet, what brings you to these halls?\n");
    
    // Juliet responds with her tasks for the day.
    printf("I come bearing updates, my dear. Our guests of Room %d have requested extra towels.\n", roomNumber);
    printf("I must fulfill their needs post haste!\n");
    
    // Romeo, being the charming protagonist he is, offers his help.
    printf("Fear not, Juliet! I shall accompany thee and we shall complete this task together for the grand C Hotel!\n");
    
    // As they set off, their adventure begins to unfold.
    printf("Together they left, passing rooms and lobbies, and all the while Romeo's heart began to soar.\n");
    printf("For with Juliet by his side, he knew the world was his oyster, and nothing could stop them from attaining that which they desire.\n");

    return 0;
}