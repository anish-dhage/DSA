//============================================================================
// Name        : jobQueue.cpp
// Author      : Anish
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Queue;

class Node{

        //int priority;
          int job_num;        
        Node *next; 
        
        public:
        Node(){
        
        next = NULL;                
        }
        
friend class Queue;

};

class Queue{

        Node *front;
        Node *rear;
        
        public : 
        Queue(){
		front = NULL;
		rear = NULL;
        }
        
        void insert(){
        	Node *new1 = new Node;
        	cout<<"Enter the job Number : ";
        	cin>>new1->job_num;
        	
        	if(front == NULL){
        		front = new1;
        		rear = new1;
        	}
        	
        	else if(front->next == NULL){
        		front->next = new1;
        		rear = new1;
        		rear->next = NULL;
        	}
        	
        	else{
        		rear->next = new1;
        		rear = new1;
        		rear->next = NULL;
        	}
        }
        
        void display(){
        	Node *new1 = front;
        	 cout<<"Queue is : ";
        	 while(new1 != NULL){
        	 	cout<< new1->job_num <<"\t";
        	 	new1 = new1->next;      	 	
        	 }
        }
        
        void delete_node(){
        
        	if(front == NULL){
        	
        		cout<<"\nQueue is Empty\n";
        		/*Node *curr = front;
        		delete curr;
        		front = NULL;
        		cout<<"\nUnderflow\n";*/
        	}
        	Node *curr = front;
        	front = front->next;
        	curr->next = NULL;
        	delete curr;
        	curr = NULL;
        }
        
};

int main() {

	Queue A;
	
	char op = 'y';
	int ch;
	
	do{

	cout<<"\n1.Insert Job\n2.Remove Job\n3.Display\n4.Exit\nEnter Option : ";	
	cin>>ch;
	
	cout<<endl;
	switch(ch){
	
	case 1:	do{
				A.insert();

				cout<<"Do you want to continue (y/n) : ";
				cin>>op;
			}
			while(op == 'y');
		
			cout<<endl;
			break;
		
	case 2: do{
			       A.delete_node();
			    cout<<"Deleted!\n";
				cout<<"Do you want to continue deletion(y/n) : ";
				cin>>op;
			}
			while(op == 'y');
			break;
	
	case 3: A.display();
			cout<<endl;
		    break;
		
	case 4: break;

	default : cout<<"Invalid Input\n";
			
	}
	
}while(ch!=4);


	return 0;
}
