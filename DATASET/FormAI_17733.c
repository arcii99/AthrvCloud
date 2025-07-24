//FormAI DATASET v1.0 Category: Chess engine ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Constants
#define BOARD_SIZE 8
#define MAX_MOVES 1024

// Types
typedef enum { False, True } Boolean;

typedef enum {
    PAWN = 'p',
    KNIGHT = 'n',
    BISHOP = 'b',
    ROOK = 'r',
    QUEEN = 'q',
    KING = 'k',
    EMPTY = ' '
} PieceType;

typedef enum { BLACK, WHITE } Color;

typedef struct {
    PieceType type;
    Color color;
} Piece;

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position from;
    Position to;
} Move;

typedef struct {
    Piece pieces[BOARD_SIZE][BOARD_SIZE];
    Color turn;
    Move moves[MAX_MOVES];
    int numMoves;
} Board;

// Function Declarations
Boolean inBounds(Position pos);
Boolean isEmpty(Piece piece);
Color opposite(Color color);
Piece getPiece(Board* board, Position pos);
Boolean setPiece(Board* board, Position pos, Piece piece);
void initPieces(Board* board);
void initBoard(Board* board);
void printBoard(Board* board);
Boolean isLegalMove(Board* board, Move move);
Boolean isPathClear(Board* board, Position start, Position end);
Boolean isNotSelfCheck(Board* board, Move move);
Boolean makeMove(Board* board, Move move);
Boolean makeMoves(Board* board, Move* moves, int numMoves);
Move parseMove(char* input);
char* promptMove(Color turn);
Color winner(Board* board);

// Function Definitions
Boolean inBounds(Position pos) {
    return pos.x >= 0 && pos.x < BOARD_SIZE && pos.y >= 0 && pos.y < BOARD_SIZE;
}

Boolean isEmpty(Piece piece) {
    return piece.type == EMPTY;
}

Color opposite(Color color) {
    return color == BLACK ? WHITE : BLACK;
}

Piece getPiece(Board* board, Position pos) {
    return board->pieces[pos.x][pos.y];
}

Boolean setPiece(Board* board, Position pos, Piece piece) {
    if (!inBounds(pos)) return False;
    board->pieces[pos.x][pos.y] = piece;
    return True;
}

void initPieces(Board* board) {
    // Black Pieces
    setPiece(board, (Position){ 0, 0 }, (Piece){ ROOK, BLACK });
    setPiece(board, (Position){ 1, 0 }, (Piece){ KNIGHT, BLACK });
    setPiece(board, (Position){ 2, 0 }, (Piece){ BISHOP, BLACK });
    setPiece(board, (Position){ 3, 0 }, (Piece){ QUEEN, BLACK });
    setPiece(board, (Position){ 4, 0 }, (Piece){ KING, BLACK });
    setPiece(board, (Position){ 5, 0 }, (Piece){ BISHOP, BLACK });
    setPiece(board, (Position){ 6, 0 }, (Piece){ KNIGHT, BLACK });
    setPiece(board, (Position){ 7, 0 }, (Piece){ ROOK, BLACK });
    setPiece(board, (Position){ 0, 1 }, (Piece){ PAWN, BLACK });
    setPiece(board, (Position){ 1, 1 }, (Piece){ PAWN, BLACK });
    setPiece(board, (Position){ 2, 1 }, (Piece){ PAWN, BLACK });
    setPiece(board, (Position){ 3, 1 }, (Piece){ PAWN, BLACK });
    setPiece(board, (Position){ 4, 1 }, (Piece){ PAWN, BLACK });
    setPiece(board, (Position){ 5, 1 }, (Piece){ PAWN, BLACK });
    setPiece(board, (Position){ 6, 1 }, (Piece){ PAWN, BLACK });
    setPiece(board, (Position){ 7, 1 }, (Piece){ PAWN, BLACK });

    // White Pieces
    setPiece(board, (Position){ 0, 7 }, (Piece){ ROOK, WHITE });
    setPiece(board, (Position){ 1, 7 }, (Piece){ KNIGHT, WHITE });
    setPiece(board, (Position){ 2, 7 }, (Piece){ BISHOP, WHITE });
    setPiece(board, (Position){ 3, 7 }, (Piece){ QUEEN, WHITE });
    setPiece(board, (Position){ 4, 7 }, (Piece){ KING, WHITE });
    setPiece(board, (Position){ 5, 7 }, (Piece){ BISHOP, WHITE });
    setPiece(board, (Position){ 6, 7 }, (Piece){ KNIGHT, WHITE });
    setPiece(board, (Position){ 7, 7 }, (Piece){ ROOK, WHITE });
    setPiece(board, (Position){ 0, 6 }, (Piece){ PAWN, WHITE });
    setPiece(board, (Position){ 1, 6 }, (Piece){ PAWN, WHITE });
    setPiece(board, (Position){ 2, 6 }, (Piece){ PAWN, WHITE });
    setPiece(board, (Position){ 3, 6 }, (Piece){ PAWN, WHITE });
    setPiece(board, (Position){ 4, 6 }, (Piece){ PAWN, WHITE });
    setPiece(board, (Position){ 5, 6 }, (Piece){ PAWN, WHITE });
    setPiece(board, (Position){ 6, 6 }, (Piece){ PAWN, WHITE });
    setPiece(board, (Position){ 7, 6 }, (Piece){ PAWN, WHITE });
}

void initBoard(Board* board) {
    board->turn = WHITE;
    board->numMoves = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->pieces[i][j].type = EMPTY;
            board->pieces[i][j].color = WHITE;
        }
    }
    initPieces(board);
}

void printBoard(Board* board) {
    printf("   a b c d e f g h\n");
    printf("  +---------------+\n");
    for (int j = BOARD_SIZE - 1; j >= 0; j--) {
        printf("%d ", j + 1);
        printf("|");
        for (int i = 0; i < BOARD_SIZE; i++) {
            Piece piece = getPiece(board, (Position){ i, j });
            char c = isEmpty(piece) ? EMPTY :
                piece.color == WHITE ? piece.type : piece.type - 'a' + 'A';
            printf("%c|", c);
        }
        printf(" %d", j + 1);
        printf("\n");
    }
    printf("  +---------------+\n");
    printf("   a b c d e f g h\n");
}

Boolean isLegalMove(Board* board, Move move) {
    if (!inBounds(move.from) || !inBounds(move.to)) return False;
    Piece fromPiece = getPiece(board, move.from);
    Piece toPiece = getPiece(board, move.to);
    if (isEmpty(fromPiece) || (!isEmpty(toPiece) && fromPiece.color == toPiece.color)) return False;
    switch (fromPiece.type) {
        case PAWN:
            if (fromPiece.color == WHITE) {
                if (move.from.x == move.to.x) {
                    if (!isEmpty(toPiece)) return False;
                    if (move.to.y == move.from.y + 1) return True;
                    if (move.to.y == move.from.y + 2 && move.from.y == 1 && isEmpty(getPiece(board, (Position){ move.from.x, move.from.y + 1 }))) {
                        return True;
                    }
                } else if (move.to.x == move.from.x - 1 || move.to.x == move.from.x + 1) {
                    if (move.to.y != move.from.y + 1) return False;
                    if (isEmpty(toPiece)) return False;
                    if (toPiece.color == BLACK) return True;
                }
            } else {
                if (move.from.x == move.to.x) {
                    if (!isEmpty(toPiece)) return False;
                    if (move.to.y == move.from.y - 1) return True;
                    if (move.to.y == move.from.y - 2 && move.from.y == 6 && isEmpty(getPiece(board, (Position){ move.from.x, move.from.y - 1 }))) {
                        return True;
                    }
                } else if (move.to.x == move.from.x - 1 || move.to.x == move.from.x + 1) {
                    if (move.to.y != move.from.y - 1) return False;
                    if (isEmpty(toPiece)) return False;
                    if (toPiece.color == WHITE) return True;
                }
            }
            break;
        case KNIGHT:
            if (!((abs(move.to.x - move.from.x) == 2 && abs(move.to.y - move.from.y) == 1)
                    || (abs(move.to.x - move.from.x) == 1 && abs(move.to.y - move.from.y) == 2))) {
                return False;
            }
            return True;
            break;
        case BISHOP:
            if (!isPathClear(board, move.from, move.to)) return False;
            return True;
            break;
        case ROOK:
            if (!isPathClear(board, move.from, move.to)) return False;
            return True;
            break;
        case QUEEN:
            if (!isPathClear(board, move.from, move.to)) return False;
            return True;
            break;
        case KING:
            if (abs(move.to.x - move.from.x) <= 1
                    && abs(move.to.y - move.from.y) <= 1) {
                return True;
            }
            return False;
            break;
    }
    return False;
}

Boolean isPathClear(Board* board, Position start, Position end) {
    Piece startPiece = getPiece(board, start);
    if (isEmpty(startPiece)) return False;
    if (start.x == end.x) {
        int ymin = start.y < end.y ? start.y : end.y;
        int ymax = start.y < end.y ? end.y : start.y;
        for (int y = ymin + 1; y < ymax; y++) {
            if (!isEmpty(getPiece(board, (Position){ start.x, y }))) return False;
        }
        return True;
    } else if (start.y == end.y) {
        int xmin = start.x < end.x ? start.x : end.x;
        int xmax = start.x < end.x ? end.x : start.x;
        for (int x = xmin + 1; x < xmax; x++) {
            if (!isEmpty(getPiece(board, (Position){ x, start.y }))) return False;
        }
        return True;
    } else if (abs(end.x - start.x) == abs(end.y - start.y)) {
        int xmin = start.x < end.x ? start.x : end.x;
        int xmax = start.x < end.x ? end.x : start.x;
        int ymin = start.y < end.y ? start.y : end.y;
        int ymax = start.y < end.y ? end.y : start.y;
        for (int i = 1; i < xmax - xmin; i++) {
            if (!isEmpty(getPiece(board, (Position){ xmin + i, ymin + i }))) return False;
        }
        return True;
    }
    return False;
}

Boolean isNotSelfCheck(Board* board, Move move) {
    Board tempBoard = *board;
    makeMove(&tempBoard, move);
    for (int i = 0; i < MAX_MOVES; i++) {
        if (isLegalMove(&tempBoard, tempBoard.moves[i])) {
            Board nextTempBoard = tempBoard;
            makeMove(&nextTempBoard, tempBoard.moves[i]);
            if (winner(&nextTempBoard) == board->turn) return False;
        }
    }
    return True;
}

Boolean makeMove(Board* board, Move move) {
    Piece piece = getPiece(board, move.from);
    if (!isLegalMove(board, move)) return False;
    if (!isNotSelfCheck(board, move)) return False;
    board->moves[board->numMoves++] = move;
    setPiece(board, move.to, piece);
    setPiece(board, move.from, (Piece){ EMPTY, WHITE });
    board->turn = opposite(board->turn);
    return True;
}

Boolean makeMoves(Board* board, Move* moves, int numMoves) {
    for (int i = 0; i < numMoves; i++) {
        if (!makeMove(board, moves[i])) return False;
    }
    return True;
}

Move parseMove(char* input) {
    int x1 = input[0] - 'a';
    int y1 = input[1] - '1';
    int x2 = input[2] - 'a';
    int y2 = input[3] - '1';
    return (Move){ (Position){ x1, y1 }, (Position){ x2, y2 } };
}

char* promptMove(Color turn) {
    printf("%s's turn: ", turn == WHITE ? "White" : "Black");
    static char input[5];
    scanf("%s", input);
    return input;
}

Color winner(Board* board) {
    // if there is no king, return opposite color as the winner
    Boolean hasWhiteKing = False;
    Boolean hasBlackKing = False;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            Piece piece = board->pieces[i][j];
            if (piece.type == KING) {
                if (piece.color == WHITE) {
                    hasWhiteKing = True;
                } else {
                    hasBlackKing = True;
                }
            }
        }
    }
    if (!hasWhiteKing) return BLACK;
    if (!hasBlackKing) return WHITE;

    // if one side has no legal moves, return opposite color as the winner
    int numWhiteMoves = 0;
    int numBlackMoves = 0;
    for (int i = 0; i < MAX_MOVES; i++) {
        if (isLegalMove(board, board->moves[i])) {
            if (board->moves[i].from.y == 1) {
                numWhiteMoves++;
            } else if (board->moves[i].from.y == 6) {
                numBlackMoves++;
            }
        }
    }
    if (numWhiteMoves == 0) return BLACK;
    if (numBlackMoves == 0) return WHITE;

    // game is not over
    return WHITE;
}

int main() {
    Board board;
    initBoard(&board);
    while (True) {
        printBoard(&board);
        char* input = promptMove(board.turn);
        if (input[0] == 'q') break;
        Move move = parseMove(input);
        if (!makeMove(&board, move)) {
            printf("Illegal move!\n");
        }
        if (winner(&board) != WHITE) break;
    }
    printf("Game over!\n");
}