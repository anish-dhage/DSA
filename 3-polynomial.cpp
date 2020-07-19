/* 
Improve Multiplication Function
*/

#include<iostream>

using namespace std;

class Polynomial;

class Term{
	
	private:
	int constant;
	int exp;

	public:
	friend istream &operator >> (istream &input, Polynomial &A);
	friend ostream &operator << (ostream &output, Polynomial &A);

	friend class Polynomial;

};

class Polynomial{

	Term *ele;
	int n;

	public:
	Polynomial(int num){
	n = num;
	ele = new Term[n];
	} 
	
	void input();
	void output();
	void eval();
	void add(Polynomial);
	void multiply(Polynomial);


	friend istream &operator >> (istream &input, Polynomial &A);
	friend ostream &operator << (ostream &output, Polynomial &A);
	
};


void Polynomial::eval(){

	int x,i,j;
	int value=0;
	int px;

	cout<<"\nInput the value of x : ";
	cin>>x;
	
	for(i=0;i<n;i++){
	px=1;
		for(j=0;j<ele[i].exp;j++){
		px=px*x;
		}
		value = value + ele[i].constant*px;
	}
	
	cout<<"\nEvaluation is : ";
	cout<<value<<endl;
}

void Polynomial::add(Polynomial b){

cout<<"\nAddition is : "; 

int con[20], i=0, j=0 ,k=0;

	do{
		if(ele[i].exp==b.ele[j].exp)
		{
		con[k]=ele[i].constant+b.ele[j].constant;
		cout<<con[k]<<"x^"<<ele[i].exp<<" + ";
		i++;
		j++;
		k++;
		}
		
		else if(ele[i].exp>b.ele[j].exp)
		{
		con[k]=ele[i].constant;
		cout<<con[i]<<"x^"<<ele[i].exp<<" + ";
		i++;
		k++;
		}

		else
		{
		con[k]=b.ele[j].constant;
		cout<<con[k]<<"x^"<<b.ele[j].exp<<" + ";
		j++;
		k++;
		}
		
	}while(i<n && j<b.n);

	if(i<n){
		do{
			con[k]=ele[i].constant;
			cout<<con[k]<<"x^"<<ele[i].exp<<" + ";
			i++;
			k++;
		}while(i<n);		
	}

	if(j<b.n){
		do{
		con[k]=b.ele[j].constant;
		cout<<con[k]<<"x^"<<b.ele[j].exp<<" + ";
		j++;
		k++;
		}while(j<b.n);
	}

	cout<<"0\n";
}

void Polynomial::multiply(Polynomial b){

int i,j;
int cpro[100];
int esum[100];

cout<<"\nMultiplication Is : ";

int p=0;

	for(i=0;i<n;i++){
		for(j=0;j<b.n;j++){
		cpro[p] = ele[i].constant * b.ele[j].constant;
		esum[p] = ele[i].exp + b.ele[j].exp;
		cout<<cpro[p]<<"x^"<<esum[p]<<" + ";
		p++;
		}
	} 

/*
	for(i=0;i<n;i++){
		for(j=i+1;j<b.n;j++){
			if(esum[i]==esum[j]){	
			cpro[i] = cpro[i]+cpro[j];
			cpro[j]=0;
			esum[j]=0;	
			}				
		}
	}
	
	for(i=0;i<n;i++){
		cout<<cpro[i]<<"x^"<<esum[i]<<" + ";	
	}
*/	

cout<<"0\n";

}

istream &operator >> (istream &input, Polynomial &A){
	
	int i;

	for(i=0;i<A.n;i++){
		cout<<"Enter the "<<i+1<<" constant"<<endl;
		input>>A.ele[i].constant;
		cout<<"Enter the "<<i+1<<" exponent"<<endl;
		input>>A.ele[i].exp;
	}

	return input;

}

ostream &operator << (ostream &output, Polynomial &A){
	
	int i;

	for(i=0;i<A.n;i++){
		output<<A.ele[i].constant<<"x^"<<A.ele[i].exp<<" + ";
	}

	cout<<"0\n";
	return output;

}


int main(){


int num1,num2;
cout<<"Enter number of elements in polynomial : ";
cin>>num1;
cout<<endl;
Polynomial a(num1);
cin>>a;

cout<<"Enter number of elements in polynomial : ";
cin>>num2;
cout<<endl;
Polynomial b(num2);
cin>>b;

cout<<endl;
cout<<a;
cout<<b;

a.eval();
a.add(b);
a.multiply(b);

return 0;
}




