#include "task.h"
#include "assignment.h"
#include "tree.h"
#include <vector>
#include <iostream>

int main(){
    /*
	std::vector<Task> all_tasks;

	Task A ("A",4,5);
	Task B ("B",4,7);
	Task C ("C",2,4);
	Task D ("D",2,3);
	Task E ("E",5,10);

	all_tasks.push_back(A);
	all_tasks.push_back(B);
	all_tasks.push_back(C);
	all_tasks.push_back(D);
	all_tasks.push_back(E);

	
	Assignment assignment;


	assignment.pending_tasks = all_tasks;
    */
    
    Tree tree;
    tree.init_from_file();

	//tree.root = assignment;
	tree.seek(&tree.root);

	tree.current_best_assignment->show();



}