#include<unistd.h>
#include "algo.h"

using namespace std;

/*

Defining the flow:-

1. Game starts upon execution with an empty board as initial state.

2. First move goes to the human.

3. State updates according to move.

4. State is then fed into the minimax algo, which produces a result, which becomes the new state.

5. Turn goes back to human and the cycle continues until an end state is reached (win/loss/draw).

*/
void tutorial() {
	cout<<"Make moves by entering 2 space separated integers."<<"\n";
	cout<<"Example: 1 1 means row 1 column 1"<<"\n";
	cout<<"You are playing as X"<<'\n';
	cout<<'\n';
}

void print_board(vector<vector<int>>& board) {
	for(int i=0;i<3;i++) {
		cout<<' ';
		for(int j=0;j<3;j++) {
			cout<<(board[i][j]==1 ? "X" : (board[i][j]==2 ? "O" : " "))<<((j!=2) ? " | " : "");
		}
		cout<<"\n";
	}
}

void intro() {
	cout<<"Tic-Tac-Toe with minimax!"<<'\n';
	cout<<"1 to start, 2 for tutorial, 3 to quit: ";
	int k;
	cin >> k;
	if(k==1) {
		vector<vector<int>> board = {{0,0,0},{0,0,0},{0,0,0}};
		print_board(board);
	}
	else if(k==2) {
		tutorial();
		intro();
	}
	else if(k==3) {
		cout<<"Thanks for playing!"<<"\n";
		return;
	}
}

vector<vector<int>> make_move_human(vector<vector<int>> board) {
	cout<<"Enter move: ";
	int row, col;
	cin >> row >> col;
	
	board[row-1][col-1] = 1;

	print_board(board);
	//sleep(2);

	return board;
}


int main() {

	intro();

	vector<vector<int>> board = {{0,0,0},{0,0,0},{0,0,0}};

	Minimax game(board);
	int finished = game.is_end_state(board);

	while(!finished) {
		board = make_move_human(game.state);
		int score = game.getBestMove(board, true, 0, 0);
		board = game.best_next_state;
		cout<<"Thinking... "<<'\n';
		sleep(1);
		print_board(board);
		finished = game.is_end_state(board);
		game.state = game.best_next_state;
	}

	if(finished==1) cout<<"Human WINS!! nice."<<"\n";
	else if(finished==2) cout<<"Algo won. LMAOO get better."<<"\n";
	else cout<<"Draw!! nice try."<<"\n";


	return 0;
}
