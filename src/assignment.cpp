#include "assignment.h"
#include <vector>

Assignment::Assignment(){}

void Assignment::calc_score(){
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

void Assignment::make_next_states(){
	//cria uma cópia do vetor de tarefas pendentes (para manter intacto o atual)
	//deleta o copiado de trás pra frente e cria Assignments filhos atualizando suas tarefas e pendências
	std::vector<Task> pending_tasks_cpy;
	pending_tasks_cpy = this->pending_tasks;

	//Lista de controle das tarefas a serem adicionadas
	std::vector<Task> pending_tasks_update;

	//numero de estados a ser gerado na próxima iteração
	int num_next = pending_tasks_cpy.size();

	//Auxiliar para criação de tarefas
	Assignment* created_assig;

	//nº do nó filho, varia de 0 a (n-1)
	//cada um adiciona recebe um elemento da lista pendência à lista de ativos
	int insertion_index;

	//inserts backwards (preserves Task order without using searchs)
	//also creates more predictable trees
	insertion_index = pending_tasks_cpy.size() - 1;

	for(int i=0;i < num_next;i++){
		//resets the pending task list
		pending_tasks_update = this->pending_tasks;

		//creates a new empty task object
		created_assig = new Assignment();

		//copies current tasks
		created_assig->task_list = this->task_list;

		//adds one task from the pending list
		created_assig->add_task(pending_tasks_cpy.back());
		pending_tasks_cpy.pop_back();

		//using tree order, it's possible to know which pending task should be missing on the new assignment
		//the same vector that was used to create the new node now is removed from it's pending list
		pending_tasks_update.erase(pending_tasks_update.begin() + insertion_index);

		//sets the new list to the new assignment
		created_assig->pending_tasks = pending_tasks_update;


		//inserts the created assignment backwards (to preserve the tree order)
		next_states[insertion_index] = created_assig;
		insertion_index--;

	}

}

