//*****************************************************************************
//Eight Queen Problem - Version 3
//
//Programmer: Chris Stansbury
//Completed : 5 MAR 2001
//Status    : Work in Progress
// 
//Purpose   : To solve Eight Queen Problem
//
//
//Algorithm : The program finds solutions by starting with a queen in the top
//            left corner of the chess board.  It then places a queen in the
//            second column and moves it until it finds a place where it
//            cannot be hit by the queen in the first column.  It then 
//            places a queen in the third column and moves it until it 
//            cannot be hit by either of the first two queens.  Then it  
//            continues this process with the remaining columns.  If there is
//            no place for a queen in the current column the program goes back
//            to the preceeding column and moves the queen in that column.  If
//            the current column is the LAST column and a safe place has been
//            found for the last queen, then a solution of the puzzle has been
//            found.  If the current column is the first column and its queen 
//            is being moved off the board, then all possible configurations
//            have been examined, all solutions have been found, and the  
//            algorithm terminates.
//
//*****************************************************************************


#include "Board.h"
#include <iostream.h>	//input/output declarations



int SolveQueen (Board b, int col, Board Solution[], int &SolutionTOS);
int StoreSolution(Board passedobj, Board Solution[], int &SolutionTOS);



// MAIN FUNCTION - PROGRAM BEGINS HERE
int main ()
{
	
	Board b1;
	Board Solution[1000];
	int SolutionTOS, ctr;

	SolutionTOS=0;

/*
	b1.blockQueen(0,0);
	b1.blockQueen(6,7);
	b1.print();

	cout << "\nRotate 90 Left\n";
	b1.rotate90().print();

	cout << "\nMirror\n";
	b1.mirror().print();

*/

	SolveQueen(b1,0, Solution, SolutionTOS);

	//print unique solutions

	for (ctr=1; ctr<=SolutionTOS; ctr++)
	{
		cout << "Solution " << ctr << endl;
		Solution[ctr].print();
		cout << "\n\n";
	}


	return 0;
}

int SolveQueen (Board b, int col, Board Solution[], int &SolutionTOS)
{

	int row;
	Board temp;
	
	row=0;

	temp = b;
	for (row=0; row< BOARD_SIZE; row++)
	{
		if (b.grabPiece(row,col)==' ')
		{
			b.blockQueen(row,col);
			if (b.fetchQueenCount() < BOARD_SIZE )
			{
				SolveQueen(b, col+1, Solution, SolutionTOS);
				b = temp;
			}
		}
		if (b.fetchQueenCount() == BOARD_SIZE)
		{
			//FOUND a SOLUTION

			StoreSolution(b, Solution, SolutionTOS);


		//	cout << "FOUND 8 QUEENS!" << endl;
		//	b.print();
		//	cout << "\n\n";
			return 0;
		}
	}

	return 0;
	
}
	
int StoreSolution(Board passedobj, Board Solution[], int &SolutionTOS)
{
	int ctr;

	if (SolutionTOS == 0)
	{//case for first solution

		SolutionTOS++;
		Solution[SolutionTOS]=passedobj; //store solution

	}

	else
	{  //need to test for unique solution

		for (ctr=1;ctr<= SolutionTOS; ctr++)
		{

			//test each unique solution against different board 
			// positions, 90 Left, 90 Right, 180, and original
			// also test the mirror of the 4 above

			if (Solution[ctr]!=passedobj &&
				Solution[ctr]!=passedobj.rotate90() &&
				Solution[ctr]!=passedobj.rotate90().rotate90() &&  //180
				Solution[ctr]!=passedobj.rotate90().rotate90().rotate90() &&  //right 90
				
				// MIRROR options
				Solution[ctr]!=passedobj.mirror() &&
				Solution[ctr]!=passedobj.rotate90().mirror() &&
				Solution[ctr]!=passedobj.rotate90().rotate90().mirror() &&  //180
				Solution[ctr]!=passedobj.rotate90().rotate90().rotate90().mirror()   //right 90
			)
			{
				//found another POSSIBLE unique solution
				// KEEP testing all other solutions
				;
			}					
			else
				return 0; //do not store solution	FOUND MATCH	
		}
		// store another unique solution
		SolutionTOS++;
		Solution[SolutionTOS]=passedobj;


	}

	return 0;
}
