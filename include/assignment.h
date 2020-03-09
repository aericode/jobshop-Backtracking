#ifndef assignment_h
#define assignment_h

#include <list>
#include "task.h"

class Assignment{
public:
	std::list<Task> task_list;
	int delay_score;

	void update_score();
	void add_task(Task);

};


#endif