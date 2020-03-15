#ifndef assignment_h
#define assignment_h

#include <list>
#include "task.h"
#include <vector>

class Assignment{
public:

	std::list<Task> task_list;

	std::vector<Task> pending_tasks;	
	std::vector<Assignment*> next_states;


	int delay_score;

	void calc_score();
	void add_task(Task);

	void make_next_states();

	Assignment();
};


#endif