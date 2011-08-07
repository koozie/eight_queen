#include "Board.h"
#include <iostream> //cout

using namespace std;

void Board::clear()
{
/************************************************
 *  Clear all board positions by placing the 
 *  blank character " " into each board position
 * 	
 *************************************************/
 
 
	int col,row;

	col=row=0;

	for (row=0; row< BOARD_SIZE; row++)
		for (col=0; col < BOARD_SIZE; col++)
			board[row][col]=' ';
}

void Board::blockQueen(int passedrow, int passedcol)
{
/*****************************************************
 *  Given the position of a queen, block the rest of
 *  the chess board.
 *  **************************************************/
	
	int row,col;

	//test to see if queen on board
	if (passedrow <0 || passedrow >= BOARD_SIZE || 
			passedcol <0 || passedcol >= BOARD_SIZE)
	{
		//can't place queen off board
		;
	}
	else
	{
		
	// Insert Queen on to board
	if (board[passedrow][passedcol]==' ')
		board[passedrow][passedcol]='Q' ;

	/////////////////////////////////////////
	//BLOCK THE REST OF THE BOARD
	/////////////////////////////////////////
	
	// DIAG DOWN RIGHT
	row=passedrow;
	col=passedcol;
	row++;
	col++;
	while (row < BOARD_SIZE && col < BOARD_SIZE)
	{
		if (board[row][col]==' ')
			board[row][col]='#';  //blocked by queen
		row++;
		col++;
	}
	//DIAG DOWN LEFT
	row=passedrow;
	col=passedcol;
	row++;
	col--;
	while (row < BOARD_SIZE && col >=0 )
	{
		if (board[row][col]==' ')
			board[row][col]='#';  //blocked by queen
		row++;
		col--;
	}
	// DIAG UP RIGHT
	row=passedrow;
	col=passedcol;
	row--;
	col++;
	while (row >=0  && col < BOARD_SIZE)
	{
		if (board[row][col]==' ')
			board[row][col]='#';  //blocked by queen
		row--;
		col++;
	}
	//DIAG UP LEFT
	row=passedrow;
	col=passedcol;
	row--;
	col--;
	while (row >=0  && col >=0 )
	{
		if (board[row][col]==' ')
			board[row][col]='#';  //blocked by queen
		row--;
		col--;
	}


	//VERTICAL UP
	row=passedrow;
	col=passedcol;
	row--;
	while (row >=0  )
	{
		if (board[row][col]==' ')
			board[row][col]='#';  //blocked by queen
		row--;
	}
	//VERTICAL DOWN
	row=passedrow;
	col=passedcol;
	row++;
	while (row < BOARD_SIZE  )
	{
		if (board[row][col]==' ')
			board[row][col]='#';  //blocked by queen
		row++;  
	}

	//HORIZONTAL RIGHT
	row=passedrow;
	col=passedcol;
	col++;
	while (col < BOARD_SIZE  )
	{
		if (board[row][col]==' ')
			board[row][col]='#';  //blocked by queen
		col++;  
	}
	
	//HORIZONTAL LEFT
	row=passedrow;
	col=passedcol;
	col--;
	while (col >=0  )
	{
		if (board[row][col]==' ')
			board[row][col]='#';  //blocked by queen
		col--;
	}

	} //end else

}

Board::Board()
{
	clear();
}

int Board::fetchQueenCount()
{
	int queen_count, row,col;

	queen_count = 0;
	
	for (row=0; row < BOARD_SIZE; row++)
		for (col=0; col < BOARD_SIZE; col++)
			if (board[row][col]=='Q')
				queen_count++;

	return queen_count;
}

void Board::print()
{
	int row,col;
	row=col=0;

	for (row=0; row < BOARD_SIZE; row++)
	{
		for (col=0; col < BOARD_SIZE; col++)
			cout << board[row][col] << " ";
	
		cout << endl;
	}
}

char Board::grabPiece(int row, int col)
{
	return board[row][col];
}

Board Board::rotate90()
{
// This function rotates the board
// and its pieces 90 degrees to
// the left.  Then it returns
// the rotated board without
// changing the original board

	Board temp;
	int row, col;
	

	for (row = 0; row< BOARD_SIZE; row++)
		for (col = 0; col < BOARD_SIZE; col++)
			//temp.board[row][col]=board[BOARD_SIZE-col-1][row];  //rotates right 90
			temp.board[BOARD_SIZE-col-1][row]=board[row][col];
	return temp;
}

Board Board::mirror()
{
// This function returns a mirrored
// copy of the board.  Mirror is
// from the bottom of the board.
	Board temp;
	int row, col;
	

	for (row = 0; row< BOARD_SIZE; row++)
		for (col = 0; col < BOARD_SIZE; col++)
			temp.board[BOARD_SIZE-row-1][col]=board[row][col];

	return temp;
}

bool Board::operator==(Board passedobj)
{
	int row,col;

	
	for (row = 0; row< BOARD_SIZE; row++)
		for (col = 0; col < BOARD_SIZE; col++)
			if (board[row][col]!=passedobj.board[row][col])
				return false;

	return true;
}
 

bool Board::operator!=(Board passedobj)
{
	return !((*this)==passedobj);
}
	
