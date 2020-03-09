#include "assignment.h"

void Assignment::update_score(){
	delay_score = 0;
	for (std::list<Task>::iterator it=task_list.begin(); it != task_list.end(); ++it){
		delay_score += it->deadline - it->end_time;
	}
}

void Assignment::add_task(Task task){
	Task to_add(task);

	if( task_list.size() == 0 ){
		to_add.end_time = to_add.duration;
		task_list.push_back(to_add);
	}else{
		std::list<Task>::iterator last = task_list.end();
		to_add.end_time = last->end_time + to_add.duration;
		task_list.push_back(to_add);
	}

}