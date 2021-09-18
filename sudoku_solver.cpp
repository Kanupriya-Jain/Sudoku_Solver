#include<iostream>
using namespace std;

const int N = 9; //Constant number of rows and columns

//Function to display the sudoku
void show(int board[N][N])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

//Function to check is the given number can be placed at a particular cell.
bool isvalid(int board[N][N], int row, int col, int num)
{
    for(int i = 0; i < N; i++)
    {
        if(board[row][i] == num)
            return false;
    }
    for(int i = 0; i < N; i++)
    {
        if(board[i][col] == num)
            return false;
    }
    int startrow = row / 3 * 3;
    int startcol = col / 3 * 3;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[startrow + i][startcol + j] == num)
                return false;
        }
    }
    return true;
}

//Function to find the next empty cell of Sudoku
bool isempty(int board[N][N], int &row, int &col)
{
    for(row = 0; row < N; row++)
    {
        for(col = 0; col < N; col++)
        {
            if(board[row][col] == 0)
                return true;
        }
    }
    return false;
}

//Main Reucrsive backtracking function to solve the SUDOKU
bool solve(int board[N][N])
{
    int row, col;

    //Base Case
    if(!isempty(board, row, col))
        return true;

    for(int num = 1; num <= 9; num++)
    {
        if(isvalid(board, row, col, num))
        {
            board[row][col] = num;

            if(solve(board))
                return true;
            
            board[row][col] = 0;
        }
    }
    return false;
}


int main()
{
    int board[N][N];
    cout<<"Enter the unsolved sudoku : "<<endl;
    cout<<"NOTE - Use 0 to represent empty cells"<<endl;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin>>board[i][j];
        }
    }
    cout<<endl;

    if(solve(board))
    {
        cout<<"Solution is as follows  : \n";
        show(board);
    }
    else
    {
        cout<<"No Solution Exists";
    }
    return 0;
}