/*
SUDOKU SOLVER using backtracking.
Steps 
Declare variable row col isEmpty
[1] Traverse the board from start to end.
[2] When we encounter 0 break out of both loops,while breaking save current row and col index.
[3] Check for !isEmpty if true return true means we have solved the sudoku.
[4] loop through all the possible values we can fill in the empty place.
[5] when we find a suitable number check if satisfy our condition.
[6] if yes 
*/

#include<bits/stdc++.h>
using namespace std;

bool isRowSafe(int board[][4],int row,int num)
{
	for(int j=0;j<4;j++)
	{
		if(board[row][j]==num)
			return false;
	}

	return true;
}

bool isColumnSafe(int board[][4],int col,int num)
{
	for(int i=0;i<4;i++)
	{
		if(board[i][col] == num)
			return false;
	}

	return true;
}

bool isBoxSafe(int board[][4],int row,int col,int num)
{
	int rowStart = row - row % 2;   // board is 4*4 so pow(4,0.5) is 2.
	int colStart = col - col % 2; 

	for(int i = rowStart;i<rowStart+2;i++)
		for (int j = colStart; j < colStart+2; j++)
		{
			if(board[i][j] == num)
				return false;
		}

	return true;
}

bool canPlaceNum(int board[][4],int row,int col,int num)
{
	if(!isRowSafe(board,row,num))
		return false;

	if(!isColumnSafe(board,col,num))
		return false;

	if(!isBoxSafe(board,row,col,num))
		return false;

	return true;
}

// Main body checks for empty spaces in sudoku and try's to fill with possible values.
bool sudokuSolver(int board[][4])
{
	int row = -1;
	int col = -1;
	bool isEmpty = false;

	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(board[i][j]==0)
			{
				isEmpty = true;
				row = i;
				col = j;
				break;		// when we find a empty space we break the loop to find the possible value for that place.
			}
		}
		if(isEmpty)			// condition for breaking the outer loop when we find an empty place.
			break;
	}	

	if(!isEmpty)			// Checks if sudoku is solved.
		return true;

	for(int num =1;num<=4;num++)	// Finding the possible value.
	{
		if(canPlaceNum(board,row,col,num)) // Checking the value satisfy all the conditions.
		{
			board[row][col] = num;		   // If contidion is satisfied we update the value.
			if(sudokuSolver(board))		   // To check if using this value we can obtain the complete solution.
				return true;
			board[row][col] = 0;		   // If not we change its value to 0 and try another value.
		}
	}

	return false;	// If it's not possible to solve the sudoku.
}

int main()
{
	int board[][4] = {{1,3,0,4},{2,0,3,1},{0,1,0,2},{4,0,1,0}};
	cout<<sudokuSolver(board);
}