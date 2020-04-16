#ifndef tree_h
#define tree_h

#include "assignment.h"

class Tree{
public:
	Assignment root;

	Assignment* current_best_assignment;
	int current_best_score;
	
	Tree();

	//void initialize();
    void init_from_file();
	void seek(Assignment*);


};


#endif