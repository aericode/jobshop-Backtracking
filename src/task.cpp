#include "task.h"

Task::Task(){};

Task::Task(const Task& other){
	this->duration = other.duration;
	this->deadline = other.deadline;
}