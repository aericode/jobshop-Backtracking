#ifndef task_h
#define task_h

class Task{
public:
	int duration;
	int deadline;
	int end_time;

	Task();
	Task(int, int);
	Task(const Task&);
};


#endif