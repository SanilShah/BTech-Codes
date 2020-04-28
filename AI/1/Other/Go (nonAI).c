#include<stdio.h>

#define N 9
/* X:3
   Y:5
*/

int board[9];
int move = 3;

int go(int pos,int move) // Write 'move' in position 'pos'
{
    board[pos] = move;
    if(move == 3)
        move = 5;
    else
        move = 3;
}

void printBoard()
{
    for(int i=1; i<=N; i++)
    {
        if(i%3 == 1)
            printf("\n");
        printf(" %d ",board[i]);
    }
}

int makeMove() // Check empty Edges
{
    if(board[2] == 1)
        return 2;
    else if(board[4] == 1)
        return 4;
    else if(board[6] == 1)
        return 6;
    else if(board[8] == 1)
        return 8;
}

int poswin() // Check if winning and return winning position
{

}

int main()
{
    // Create Empty Board
    for(int i=1; i<=N; i++)
    {
        board[i] = 1;
    }
    // Start Filling
    go(5,move);

    /*for(int i=1; i<=N-1; i++)
    {
        if(board[5]==1)
            go(5,move);
        else if(board[1]==1)
            go(1,move);
    }*/
    // Print Board
    printBoard();


}
