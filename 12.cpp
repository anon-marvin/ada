#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void printSolution(const vector<int> &board, int N)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (board[i] == j)
                cout << "Q ";
            else
                cout << "* ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(const vector<int> &board, int row, int col)
{
    for (int i = 0; i < row; ++i)
    {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
        {
            return false;
        }
    }
    return true;
}

bool solveNQueensUtil(vector<int> &board, int row, int N)
{
    if (row == N)
    {
        printSolution(board, N);
        return true; // Found a solution
    }

    for (int col = 0; col < N; ++col)
    {
        if (isSafe(board, row, col))
        {
            board[row] = col;
            if (solveNQueensUtil(board, row + 1, N))
                return true; // Stop after finding the first solution
            board[row] = -1; // Backtrack
        }
    }
    return false;
}

int main()
{
    int N;
    cout << "Enter the number of queens: ";
    cin >> N;

    vector<int> board(N, -1);
    if (!solveNQueensUtil(board, 0, N))
    {
        cout << "No solution exists for " << N << " queens." << endl;
    }

    return 0;
}
