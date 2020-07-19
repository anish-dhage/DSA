#include <iostream>

using namespace std;

class Stack;

class Node{

	char data;
	Node *next;

	public:
	Node(){
		next = NULL;
	}

friend class Stack;
};

class Stack{

	Node *top;
	public:
	Stack(){
		top = NULL;
 	}

 	void push(char x){

 		Node *new1 = new Node;
 		new1->data = x;

 		if(top == NULL){
 			top = new1;
 		}

 		else{
 			new1->next = top;
 			top = new1;
 		}
 	}

	char pop(){

		char a = top->data;

 		Node *curr;
 		curr = top;
 		top = top->next;
 		curr->next = NULL;
 		delete curr;
 		curr = NULL;

 		return a;

 	}

};

void checkPara(char expr[50], Stack A){

 	int flag;
 	int i = 0;

 	while(expr[i] != '\0'){

 		if(expr[i] == '{' || expr[i] == '[' || expr[i] == '('){

 		A.push(expr[i]);


 		}

 		else if(expr[i] == '}' ||expr[i] == ']' ||expr[i] == ')'){
 			char a = A.pop();

 			if((a == '{' && expr[i] == '}') || (a == '[' && expr[i] == ']') || (a == '(' && expr[i] == ')')){

 				flag = 0;

 			}

 			else{

 				flag = 1;

 			}


 		}
 		i++;


 	}

 	if(flag == 1){
 		cout << "Error in Syntax ";
 	}

 	else {
 	cout<<"No Error";
 	}

}


int main(){

char expr[50];

cout<<"Enter the expression : ";
cin>>expr;
cout<<endl;

Stack A;

checkPara(expr, A);

return 0;
}




