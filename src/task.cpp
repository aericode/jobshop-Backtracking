#include "task.h"

Task::Task(){};

Task::Task(int duration, int deadline){
	this->duration = duration;
	this->deadline = deadline;
}

Task::Task(const Task& other){
	this->duration = other.duration;
	this->deadline = other.deadline;
}