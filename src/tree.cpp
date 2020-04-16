#define INT_MAX 2147483647

#include "tree.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

Tree::Tree(){
	current_best_score = INT_MAX;
}

void Tree::init_from_file(){
    std::vector<Task> all_tasks;
    Task next_task;
    
    std::string tag;
    std::string duration_str;
    std::string deadline_str;
    
    int duration;
    int deadline;
    
    std::ifstream file ("./input/tasklist.csv");
    
    if(!file.is_open()) std::cout<<"Error opening file"<<std::endl;
    
    while(!file.eof()){
        getline(file,tag,',');
        getline(file,duration_str,',');
        getline(file,deadline_str,'\n');
        
        duration = std::stoi(duration_str);
        deadline = std::stoi(deadline_str);
        
        next_task.tag      = tag;
        next_task.duration = duration;
        next_task.deadline = deadline;
        
        
        all_tasks.push_back(next_task);
    }
    
    file.close();
    
    root.pending_tasks = all_tasks;
    
}

void Tree::seek(Assignment* seek_node){
	if(seek_node->is_leaf()){
		seek_node->calc_score();

		if(seek_node->delay_score < current_best_score){
			current_best_score = seek_node->delay_score;
			current_best_assignment = seek_node;
		}

	}else{

		seek_node->make_next_states();

		int num_states = seek_node->get_num_next_states();

		for(int i = 0; i < num_states; i++){
			seek(seek_node->next_states[i]);
		}

	}
}

