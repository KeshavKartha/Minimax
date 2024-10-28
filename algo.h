#ifndef ALGO_H
#define ALGO_H

#include<vector>
#include<iostream>
#include<algorithm>

class Minimax {
public:
	std::vector<std::vector<int>> state;
	std::vector<std::vector<int>> best_next_state;

	Minimax(std::vector<std::vector<int>> state_loc);
	int is_end_state(std::vector<std::vector<int>>& b);
	int getBestMove(std::vector<std::vector<int>>& board, bool is_maximizer, int depth, int loc_score);

};


#endif