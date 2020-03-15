#include "task.h"
#include "assignment.h"
#include <vector>

int main(){

	std::vector<Task> all_tasks;

	Task A (3,5);
	Task B (4,7);
	Task C (2,4);
	Task D (2,3);
	Task E (5,10);

	all_tasks.push_back(A);
	all_tasks.push_back(B);
	all_tasks.push_back(C);
	all_tasks.push_back(D);
	all_tasks.push_back(E);

	Assignment assignment;

	assignment.pending_tasks = all_tasks;

	assignment.make_next_states();

}