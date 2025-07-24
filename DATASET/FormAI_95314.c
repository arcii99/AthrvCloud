//FormAI DATASET v1.0 Category: Chess engine ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Definitions for board and pieces
#define boardSize 8
#define maxMoves 2048

typedef struct
{
    char x;
    char y;
} Coord;

typedef struct
{
    Coord pos;
    char isWhite;
    char isKing;
} Piece;

typedef struct
{
    Piece pieces[32];
    char numPieces;
    char whoseTurn; // 0 for black, 1 for white
    char isCheckmate;
    char isStalemate;
} Board;

// Function declarations
void printBoard(Board board);
void getAllValidMoves(Board board, Coord from, Coord *moves, char *numMoves);
void movePiece(Board *board, Coord from, Coord to);
char isCheckmate(Board board);
char isStalemate(Board board);

// Function definitions
void printBoard(Board board)
{
    char boardArray[8][8];
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            boardArray[i][j] = ' ';
        }
    }
    for (int i = 0; i < board.numPieces; i++)
    {
        char x = board.pieces[i].pos.x;
        char y = board.pieces[i].pos.y;
        boardArray[y][x] = board.pieces[i].isKing ? (board.pieces[i].isWhite ? 'K' : 'k') :
            (board.pieces[i].isWhite ? 'P' : 'p');
    }
    for (int i = 0; i < boardSize; i++)
    {
        printf("%d ", 8 - i);
        for (int j = 0; j < boardSize; j++)
        {
            printf("%c ", boardArray[i][j]);
        }
        printf("\n");
    }
    printf("  a b c d e f g h \n");
}

void getAllValidMoves(Board board, Coord from, Coord *moves, char *numMoves)
{
    char pieceFound = 0;
    for (int i = 0; i < board.numPieces; i++)
    {
        Piece piece = board.pieces[i];
        if (piece.pos.x == from.x && piece.pos.y == from.y && piece.isWhite == board.whoseTurn)
        {
            pieceFound = 1;
            if (piece.isKing)
            {
                for (char dx = -1; dx <= 1; dx++)
                {
                    for (char dy = -1; dy <= 1; dy++)
                    {
                        if (dx == 0 && dy == 0)
                        {
                            continue;
                        }
                        Coord to = { from.x + dx, from.y + dy };
                        if (to.x >= 0 && to.x < boardSize && to.y >= 0 && to.y < boardSize)
                        {
                            char pieceOnDest = 0;
                            for (int j = 0; j < board.numPieces; j++)
                            {
                                if (board.pieces[j].pos.x == to.x && board.pieces[j].pos.y == to.y)
                                {
                                    pieceOnDest = 1;
                                    if (board.pieces[j].isWhite != board.whoseTurn)
                                    {
                                        moves[*numMoves] = to;
                                        (*numMoves)++;
                                    }
                                    break;
                                }
                            }
                            if (!pieceOnDest)
                            {
                                moves[*numMoves] = to;
                                (*numMoves)++;
                            }
                        }
                    }
                }
            }
            else
            {
                char dir = piece.isWhite ? 1 : -1;
                Coord to = { from.x, from.y + dir };
                if (to.x >= 0 && to.x < boardSize && to.y >= 0 && to.y < boardSize)
                {
                    char pieceOnDest = 0;
                    for (int j = 0; j < board.numPieces; j++)
                    {
                        if (board.pieces[j].pos.x == to.x && board.pieces[j].pos.y == to.y)
                        {
                            pieceOnDest = 1;
                            break;
                        }
                    }
                    if (!pieceOnDest)
                    {
                        moves[*numMoves] = to;
                        (*numMoves)++;
                    }
                }
                if ((piece.isWhite && from.y == 1) || (!piece.isWhite && from.y == 6))
                {
                    to.y += dir;
                    if (to.x >= 0 && to.x < boardSize && to.y >= 0 && to.y < boardSize)
                    {
                        char pieceOnDest = 0;
                        for (int j = 0; j < board.numPieces; j++)
                        {
                            if (board.pieces[j].pos.x == to.x && board.pieces[j].pos.y == to.y)
                            {
                                pieceOnDest = 1;
                                break;
                            }
                        }
                        if (!pieceOnDest)
                        {
                            moves[*numMoves] = to;
                            (*numMoves)++;
                        }
                    }
                }
                for (char dx = -1; dx <= 1; dx += 2)
                {
                    Coord to = { from.x + dx, from.y + dir };
                    if (to.x >= 0 && to.x < boardSize && to.y >= 0 && to.y < boardSize)
                    {
                        char pieceOnDest = 0;
                        char pieceDestIsEnemy = 0;
                        for (int j = 0; j < board.numPieces; j++)
                        {
                            if (board.pieces[j].pos.x == to.x && board.pieces[j].pos.y == to.y)
                            {
                                pieceOnDest = 1;
                                if (board.pieces[j].isWhite != board.whoseTurn)
                                {
                                    pieceDestIsEnemy = 1;
                                }
                                break;
                            }
                        }
                        if (pieceDestIsEnemy)
                        {
                            moves[*numMoves] = to;
                            (*numMoves)++;
                        }
                    }
                }
            }
            break;
        }
    }
    if (!pieceFound)
    {
        printf("Invalid move.\n");
    }
}

void movePiece(Board *board, Coord from, Coord to)
{
    char pieceIndex = -1;
    for (int i = 0; i < board->numPieces; i++)
    {
        if (board->pieces[i].pos.x == from.x && board->pieces[i].pos.y == from.y && board->pieces[i].isWhite == board->whoseTurn)
        {
            pieceIndex = i;
            break;
        }
    }
    if (pieceIndex == -1)
    {
        printf("Invalid move.\n");
        return;
    }
    for (int i = 0; i < board->numPieces; i++)
    {
        if (board->pieces[i].pos.x == to.x && board->pieces[i].pos.y == to.y)
        {
            board->pieces[i] = board->pieces[board->numPieces - 1];
            board->numPieces--;
            break;
        }
    }
    board->pieces[pieceIndex].pos = to;
    if (board->whoseTurn == 0)
    {
        board->whoseTurn = 1;
    }
    else
    {
        board->whoseTurn = 0;
    }
    board->isCheckmate = isCheckmate(*board);
    if (board->isCheckmate)
    {
        printf("Checkmate!\n");
    }
    else if (isStalemate(*board))
    {
        printf("Stalemate.\n");
    }
}

char isCheckmate(Board board)
{
    // TODO: Implement
    return 0;
}

char isStalemate(Board board)
{
    // TODO: Implement
    return 0;
}

int main()
{
    Board board = { .numPieces = 32, .whoseTurn = 1 };
    Piece pieces[32] = {
        { .pos = { 0, 0 }, .isWhite = 1 },
        { .pos = { 1, 0 }, .isWhite = 1 },
        { .pos = { 2, 0 }, .isWhite = 1 },
        { .pos = { 3, 0 }, .isWhite = 1 },
        { .pos = { 4, 0 }, .isWhite = 1 },
        { .pos = { 5, 0 }, .isWhite = 1 },
        { .pos = { 6, 0 }, .isWhite = 1 },
        { .pos = { 7, 0 }, .isWhite = 1 },
        { .pos = { 0, 1 }, .isWhite = 1 },
        { .pos = { 1, 1 }, .isWhite = 1 },
        { .pos = { 2, 1 }, .isWhite = 1 },
        { .pos = { 3, 1 }, .isWhite = 1 },
        { .pos = { 4, 1 }, .isWhite = 1 },
        { .pos = { 5, 1 }, .isWhite = 1 },
        { .pos = { 6, 1 }, .isWhite = 1 },
        { .pos = { 7, 1 }, .isWhite = 1 },
        { .pos = { 0, 7 }, .isWhite = 0 },
        { .pos = { 1, 7 }, .isWhite = 0 },
        { .pos = { 2, 7 }, .isWhite = 0 },
        { .pos = { 3, 7 }, .isWhite = 0 },
        { .pos = { 4, 7 }, .isWhite = 0 },
        { .pos = { 5, 7 }, .isWhite = 0 },
        { .pos = { 6, 7 }, .isWhite = 0 },
        { .pos = { 7, 7 }, .isWhite = 0 },
        { .pos = { 0, 6 }, .isWhite = 0 },
        { .pos = { 1, 6 }, .isWhite = 0 },
        { .pos = { 2, 6 }, .isWhite = 0 },
        { .pos = { 3, 6 }, .isWhite = 0 },
        { .pos = { 4, 6 }, .isWhite = 0 },
        { .pos = { 5, 6 }, .isWhite = 0 },
        { .pos = { 6, 6 }, .isWhite = 0 },
        { .pos = { 7, 6 }, .isWhite = 0 },
    };
    for (int i = 0; i < board.numPieces; i++)
    {
        board.pieces[i] = pieces[i];
        board.pieces[i].isKing = 0;
        if (board.pieces[i].pos.y == 0 || board.pieces[i].pos.y == 7)
        {
            board.pieces[i].isKing = 1;
        }
    }
    printBoard(board);
    char input[10];
    Coord from = { 0, 0 };
    Coord to = { 0, 0 };
    while (!board.isCheckmate && !board.isStalemate)
    {
        printf("%s's turn.\n", board.whoseTurn == 0 ? "Black" : "White");
        printf("Enter move (e.g. 'e2 e4'):\n");
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%c%d %c%d", &from.x, &from.y, &to.x, &to.y) == 4)
        {
            from.x -= 'a';
            from.y = 7 - (from.y - 1);
            to.x -= 'a';
            to.y = 7 - (to.y - 1);
            Coord validMoves[maxMoves];
            char numValidMoves = 0;
            getAllValidMoves(board, from, validMoves, &numValidMoves);
            char moveIsValid = 0;
            for (int i = 0; i < numValidMoves; i++)
            {
                if (validMoves[i].x == to.x && validMoves[i].y == to.y)
                {
                    moveIsValid = 1;
                    break;
                }
            }
            if (moveIsValid)
            {
                movePiece(&board, from, to);
                printBoard(board);
            }
            else
            {
                printf("Invalid move.\n");
            }
        }
        else
        {
            printf("Invalid input.\n");
        }
    }
    return 0;
}