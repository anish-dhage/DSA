#include <iostream>

using namespace std;

class Value{

	int row;
	int col;
	int val;

	public:
	Value(){
	row = 0;
	col = 0;
	val = 0;
	}
	
	friend class Smatrix;
};

class Smatrix{
	
	int n;
	Value *a;

	public:
	Smatrix(int num){
	n = num;
	a = new Value[n+1];
	}
	
	void input();
	void output();
	void fastTranspose();
	void addition(Smatrix ob);
	
};

void Smatrix::input(){

int i=0;

	cout<<"\nEnter the no of rows : ";
	cin>>a[0].row;
	cout<<"\nEnter the no of columns : ";
	cin>>a[0].col;
	cout<<"\nNo of non zero values : "<< n;
	a[0].val = n;	
	
	for(i=1; i<=a[0].val; i++){
	
		cout<<"\nEnter the "<< i <<" position row : ";
		cin>>a[i].row;
		cout<<"\nEnter the "<< i <<" position column : ";
		cin>>a[i].col;
		cout<<"\nEnter the value : ";
		cin>>a[i].val;
		
	}
}

void Smatrix::output(){

int i=0;
	
	for (i=0 ; i<=a[0].val ; i++){
	
		cout<<a[i].row<<"\t"<<a[i].col<<"\t"<<a[i].val<<"\n";	
	
	}
	
	cout<<endl;
}

void Smatrix::addition(Smatrix ob){

	int i = 1;
	int j = 1;
	int k = 1;

	Smatrix addn(n + ob.n + 1);
	
	addn.a[0].row = a[0].row;
	addn.a[0].col = a[0].col;
		
	do{
		if (a[i].row == ob.a[j].row) {
			if(a[i].col == ob.a[j].col){
				addn.a[k].row = a[i].row;
				addn.a[k].col = a[i].col;
				addn.a[k].val = a[i].val + ob.a[j].val;
				i++;
				j++;
				k++;

			}
			
			else if(a[i].col < ob.a[j].col){
				addn.a[k].row = a[i].row;
				addn.a[k].col = a[i].col;
				addn.a[k].val = a[i].val;
				i++;
				k++;
				
			}
			
			else if(a[i].col > ob.a[j].col){
				addn.a[k].row = ob.a[j].row;
				addn.a[k].col = ob.a[j].col;
				addn.a[k].val = ob.a[j].val;
				j++;
				k++;
			}
		}
		
		else if(a[i].row < ob.a[j].row){
			addn.a[k].row = a[i].row;
			addn.a[k].col = a[i].col;
			addn.a[k].val = a[i].val;
			i++;
			k++;

		}
		
		else if(a[i].row > ob.a[j].row){
			addn.a[k].row = ob.a[j].row;
			addn.a[k].col = ob.a[j].col;
			addn.a[k].val = ob.a[j].val;
			j++;
			k++;
		}
	
	}while((i <= a[0].val) && (j <= ob.a[0].val));
	
	if(i<=a[0].val){
	
		do{
		
			addn.a[k].row = a[i].row;
			addn.a[k].col = a[i].col;
			addn.a[k].val = a[i].val;
			i++;
			k++;
		
		}while(i<=a[0].val);
	
	}
	
	if(j<=ob.a[0].val){
	
		do{
			addn.a[k].row = ob.a[j].row;
			addn.a[k].col = ob.a[j].col;
			addn.a[k].val = ob.a[j].val;;
			j++;
			k++;
		
		}while(j<=ob.a[0].val);
	
	}


	addn.a[0].val = k-1;
	cout<<"Resultant Added Sparse Matrix is : "<<endl;
	addn.output();

}

void Smatrix::fastTranspose(){

Smatrix b(n);

int p,i,j;
int rowno[a[0].col];
int strpos[a[0].col];
        
        p = a[0].val;
        b.a[0].row = a[0].col;        
        b.a[0].col = a[0].row;  
        b.a[0].val = p; 
        
        for(i=0 ; i<a[0].col ;i++){               
                rowno[i] = 0;
        }
        
        for(i=1 ; i<=p ;i++){               
                rowno[a[i].col]++;
        }
        
        strpos[0] = 1;
        
        for(i=1 ; i<=a[0].col ; i++){
        
        strpos[i] = strpos[i-1] + rowno[i-1];
        
        }

               
        for(i=1 ; i<=p ; i++ ){
         
                b.a[strpos[a[i].col]].col = a[i].row;
                b.a[strpos[a[i].col]].row = a[i].col;
                b.a[strpos[a[i].col]].val = a[i].val;
        
                strpos[a[i].col]++;
                
                }
        
        cout<<"Resultant Transpose : "<<endl;
        b.output();
        
}

int main(){

int n1,n2;

cout<<"Enter number of non zero values in matrix 1 : ";
cin>>n1;

Smatrix ob1(n1);

cout<<"Enter values of Matrix : \n";
ob1.input();

cout<<"Enter number of non zero values in matrix 2 : ";
cin>>n2;

Smatrix ob2(n2);

cout<<"Enter values of Matrix : \n";
ob2.input();


ob1.output();
cout<<endl;
ob2.output();

ob1.addition(ob2);

ob1.fastTranspose();


return 0;
}









