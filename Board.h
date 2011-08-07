#define BOARD_SIZE 8

class Board {

	char board[BOARD_SIZE][BOARD_SIZE];


public:
	void clear();
	void blockQueen(int row, int col);
	Board();
	int fetchQueenCount();
	void print();
	char grabPiece (int, int);

	Board mirror();
	Board rotate90();

	bool operator==(Board passedobj);

	bool operator!=(Board passedobj);
};
