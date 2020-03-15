#include "task.h"
#include "assignment.h"
#include <vector>
#include <iostream>

int main(){

	std::vector<Task> all_tasks;

	Task A ("A",5,5);
	Task B ("B",4,7);
	Task C ("C",2,4);
	Task D ("D",2,3);
	Task E ("E",5,10);

	all_tasks.push_back(A);
	all_tasks.push_back(B);
	all_tasks.push_back(C);
	all_tasks.push_back(D);
	all_tasks.push_back(E);



	//std::cout<<"Tag "     <<A.tag<<std::endl;
	//std::cout<<"duration "<<A.duration<<std::endl;
	//std::cout<<"deadline "<<A.deadline<<std::endl;
	//std::cout<<"endtime " <<A.end_time<<std::endl;

	
	Assignment assignment;

	assignment.add_task(A);

	assignment.calc_score();

	std::cout << assignment.delay_score << std::endl;

	/*
	assignment.show();

	assignment.calc_score();

	std::cout << assignment.delay_score << std::endl;
	*/


}