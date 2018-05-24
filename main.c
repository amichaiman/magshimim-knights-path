#include <stdio.h>

#define BOARD_SIZE 8
#define NUMBER_OF_HORSE_MOVES 8


typedef struct {
    int x;
    int y;
} Point;

void printBoard(int board[][BOARD_SIZE]);
int isInBoard(int x, int y);

int canReach(int board[][BOARD_SIZE], Point curSpot, Point endSpot);

int main()
{
    int board[BOARD_SIZE][BOARD_SIZE] = {0};
    Point startPoint = {0,0};
    Point endPoint = {7,7};

    if (canReach(board,startPoint,endPoint))
    {
        printBoard(board);
    }
    else
    {
        printf("spot not reachable\n");
    }

    return 0;
}

int canReach(int board[][BOARD_SIZE], Point curSpot, Point endSpot)
{
    static int x[] = {-2,-1,-2,-1,1,2,1,2};
    static int y[] = {-1,-2,1,2,-2,-1,2,1};
    static int step = 0;

    int i=0;
    Point nextSpot;
    /*  current spot is out of board, or has been visited in current path   */
    if (!isInBoard(curSpot.x,curSpot.y) || board[curSpot.x][curSpot.y] != 0)
    {
        return 0;
    }

    board[curSpot.x][curSpot.y] = ++step;

    /*  if destination spot has been reached    */
    if (curSpot.x == endSpot.x && curSpot.y == endSpot.y)
    {
        return 1;
    }

    /*  check all 8 possible horse moves  */
    for (i=0; i<NUMBER_OF_HORSE_MOVES; i++)
    {
        nextSpot.x = curSpot.x+x[i];
        nextSpot.y = curSpot.y+y[i];

        if (canReach(board,nextSpot,endSpot))
        {
            return 1;
        }
    }

    /*  current spot is not part of final path, hence- mark as unvisited    */
    board[curSpot.x][curSpot.y] = 0;
    --step;
    return 0;
}

void printBoard(int board[][BOARD_SIZE])
{
    int i = 0;
    int j = 0;

    for (i=0; i<BOARD_SIZE; i++)
    {
        for (j=0; j<BOARD_SIZE; j++)
        {
            board[i][j] == 0 ? printf(" \t") : printf("%d\t",board[i][j]);
        }
        putchar('\n');
    }
}

/*  returns 1 if x and y are */
int isInBoard(int x, int y)
{
    return x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE ? 0 : 1;
}