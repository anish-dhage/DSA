#include <iostream>

using namespace std;

template <class T>
class Stack;

class Expression;

template <class T1>
class Node{

	T1 data;
	Node <T1> *next;

	public:
	Node(){
		next = NULL;
	}

template <class T>
friend class Stack;
friend class Expression;
};

template <class T>
class Stack{

	public:
	Node <T> *top;
	Stack(){
		top = NULL;
 	}

 	void push(T x){

 		Node <T> *new1 = new Node<T>;
 		new1->data = x;

 		if(top == NULL){
 			top = new1;
 			top->next = NULL;
 		}

 		else{
 			new1->next = top;
 			top = new1;
 		}
 	}

	char pop(){

		char a = top->data;

 		Node <T> *curr;
 		curr = top;
 		top = top->next;
 		curr->next = NULL;
 		delete curr;
 		curr = NULL;

 		return a;

 	}

};

class Expression{

char exp[100];
char pofix[100];

public:
/*
	Expression(){
		exp = " ";
		pofix =" ";

	}*/
	void input(){
		cout <<"Enter the expression : ";
		cin >>exp;
		cout<<endl;
		int i = 0;
		while(exp[i] != '\0'){
			i++;
		}

		exp[i++]= ')';
		exp[i]= '\0';

	}

	void output(){
		cout<<"In-fix expression is : "<<exp<<endl;
		cout<<"Post-fix expression is : "<<pofix<<endl;
	}

	int precedence(char x, char y){
		if(x =='*' && y =='-'){
			return 0;
		}
		else if(x =='*' && y =='+'){
			return 0;
		}
		else if(x =='/' && y =='*'){
			return 0;
		}
		else if(x =='/' && y =='+'){
			return 0;
		}
		else if(x =='/' && y =='-'){
			return 0;
		}
		else{
			return 1;
		}
	}

	void convert(){
		Stack <char> A;
		A.push('(');
		int i=0;
		int j=0;
		char a;

		while(exp[i] != '\0'){
			if(exp[i] == '(' || exp[i] == ')' ){

				if(exp[i] == '('){
					A.push('(');
					i++;
				}

				else if(exp[i] == ')'){
					while( A.top->data != '('){
						a = A.pop();
						pofix[j] = a;
						j++;

					}
					a=A.pop();
					i++;
					//pofix[j] = a;
					//j++;
				}
			}

			else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' ){

				if(precedence(exp[i],A.top->data) == 1){
					while(precedence(exp[i],A.top->data) != 1 || A.top->data != '('){
						a = A.pop();
						pofix[j] = a;
						j++;
					}
					if(exp[i] != '('){
					A.push(exp[i]);
					i++;
					}
				}

				else if(precedence(exp[i],A.top->data) == 0){
				A.push(exp[i]);
				i++;
				}
			}

			else{
				pofix[j] = exp[i];
				i++;
				j++;
			}
		}
		pofix[j] = '\0';
	}
	void evaluate(){
		int i = 0;
		int num;
		int var1;
		int var2;
		int res;

		Stack <int> A;

		while(pofix[i] != '\0'){
			if( (pofix[i]>=65 && pofix[i]<=90) || (pofix[i]>=97 && pofix[i]<=122) ){
				cout<<"Enter the value of "<<pofix[i]<<" : ";
				cin>>num;
				cout<<endl;
				A.push(num);
			}

			else{
				var1 = A.pop();
				var2 = A.pop();
				res = 0;

				if(pofix[i] == '+'){
					res = var1 + var2;
					A.push(res);
				}
				else if(pofix[i] == '-'){
					res = var2 - var1;
					A.push(res);
				}
				else if(pofix[i] == '*'){
					res = var2 * var1;
					A.push(res);
				}
				else if(pofix[i] == '/'){
					res = var2 / var1;
					A.push(res);
				}

			}
			i++;
		}
		res = A.pop();
		cout<<"Result is : "<<res<<endl;
	}


};


int main(){

Expression ob1;
ob1.input();
ob1.convert();
ob1.output();
ob1.evaluate();

return (0);
}









