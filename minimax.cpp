#include "algo.h"

const int inf = 1e9+7;


Minimax::Minimax(std::vector<std::vector<int>> state_loc) {
	state = state_loc;
	best_next_state = state_loc;
}

int Minimax::is_end_state(std::vector<std::vector<int>>& b) {
	//Human win
	if((b[0][0]==1 && b[0][1]==1 && b[0][2]==1) || 
		(b[1][0]==1 && b[1][1]==1 && b[1][2]==1) || 
		(b[2][0]==1 && b[2][1]==1 && b[2][2]==1) || 
		(b[0][0]==1 && b[1][0]==1 && b[2][0]==1) || 
		(b[0][1]==1 && b[1][1]==1 && b[2][1]==1) || 
		(b[0][2]==1 && b[1][2]==1 && b[2][2]==1) || 
		(b[0][0]==1 && b[1][1]==1 && b[2][2]==1) || 
		(b[0][2]==1 && b[1][1]==1 && b[2][0]==1)) {
		return 1;
	}
	//Algo win
	if((b[0][0]==2 && b[0][1]==2 && b[0][2]==2) || 
		(b[1][0]==2 && b[1][1]==2 && b[1][2]==2) || 
		(b[2][0]==2 && b[2][1]==2 && b[2][2]==2) || 
		(b[0][0]==2 && b[1][0]==2 && b[2][0]==2) || 
		(b[0][1]==2 && b[1][1]==2 && b[2][1]==2) || 
		(b[0][2]==2 && b[1][2]==2 && b[2][2]==2) || 
		(b[0][0]==2 && b[1][1]==2 && b[2][2]==2) || 
		(b[0][2]==2 && b[1][1]==2 && b[2][0]==2)) {
		return 2;
	}
	else {
		bool has_zero=false;
		for(int i=0;i<3;i++) {
			for(int j=0;j<3;j++) {
				if(!b[i][j]) {
					has_zero=true;
					break;
				}
			}
		}
		if(has_zero) return 0; //Not finished
		else return 3; //Draw
	}
}


//recursive fn for dfs.

int Minimax::getBestMove(std::vector<std::vector<int>>& board, bool is_maximizer, int depth, int loc_score, int alpha, int beta) {
	if(is_maximizer) {
		loc_score = -inf;
		alpha = -inf;
	}
	else {
		loc_score = inf;
		beta = inf;
	}
	int end = is_end_state(board);

	if(end==1) return -1;
	if(end==2) return 1;
	if(end==3) return 0;

	for(int i=0;i<3;i++) {
		for(int j=0;j<3;j++) {
			if(board[i][j]!=0) continue;
			
			if(is_maximizer) {
				board[i][j]=2;
				int child_score = getBestMove(board, !is_maximizer, depth+1, loc_score, alpha, beta);

				if(depth==0 && child_score>loc_score) {
					loc_score = child_score;
					best_next_state = board;
				}
				else if(depth!=0 && child_score>loc_score) {
					loc_score = child_score;
				}
			}
			else {
				board[i][j]=1;
				int child_score = getBestMove(board, !is_maximizer, depth+1, loc_score, alpha, beta);
				loc_score = std::min(loc_score, child_score);
			}

			board[i][j]=0;
		}
	}

	return loc_score;
}