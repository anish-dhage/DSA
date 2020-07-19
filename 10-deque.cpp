//============================================================================
// Name        : deque.cpp
// Author      : Anish
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Deque{
	
	int a[50];
	int front;
	int rear;
	int size;
	
public:
	Deque(int s){
		size = s;
		front = -1;
		rear = -1;
	}
	
	void push_front(){
	
		int data;
		cout<<"Enter the data : ";
		cin>>data;
		cout<<endl;	
		
		if (front == -1){
			front++;
			rear++;
			a[front] = data;
		}
		
		else if (front == 0 && rear == size-1){
			cout<<"Overflow\n";
		}
		
		else if (front == 0 ){
			int i;
			for(i=rear; i >=front; i--){
				a[i+1] = a[i];
			}
			rear = rear + 1;
			a[front] = data;			
		}
		
		else{
			front--;
			a[front] = data;
		}		
		
	}
	
	void push_rear(){
		
		int data;
		cout<<"Enter the data : ";
		cin>>data;
		cout<<endl;	
		
		if(front == -1){
			front++;
			rear++;
			a[rear] = data;
		}
		
		else if(rear >= size-1){
			cout<<"Overflow\n";
		}
		
		else if(front!=0 && rear == size-1){
			int i;
			for(i=front - 1; i <=rear; i++){
				a[i] = a[i+1];
			}
			front = front -1;
			a[rear] = data;		
		}
		
		else{
			rear++;
			a[rear] = data;
		}
				
	}
	
	void pop_front(){
		if(front == -1){
			cout<<"Underflow\n";
		}
		
		else if(front == rear){
			front = -1;
			rear = -1;
		}
		
		else{
			front++;
		}
	}
	
	void pop_rear(){
		if (rear == -1){
			cout<<"Underflow\n";
		}
		
		else if (rear == front){
			front = -1;
			rear = -1;
		}
		
		else{
			rear--;
		}
	}
	
	void display(){
		int i ;
		
		cout<<"Deque : ";
		for(i=front; i<=rear; i++){
			cout<<a[i]<<"\t";
		}
		
	}
	


};

int main() {

	Deque A(50);
	
	int op;
	
	do{
		cout<<"\n1.Push Front\n2.Push Rear\n3.Pop Front\n4.Pop Rear\n5.Display\n6.Exit\nEnter the option : ";
		cin>>op;
		cout<<endl;
		
		switch(op){
			case 1: A.push_front();
					break;
			
			case 2:A.push_rear();
				        break;
			
			case 3:A.pop_front();
					break;
					
			case 4:A.pop_rear();
					break;
			
			case 5:A.display();
					break;
			
			case 6:break;
			
			default : cout<<"Invalid Option";
					break;
		}	
		
	}while(op != 6);

	return 0;
}







