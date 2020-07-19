//============================================================================
// Name        : searching.cpp
// Author      : pratiksha
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class RollNo_search{
	int a[100];
	int num;

public:
	void input(){
		cout<<"Enter the number of elements : ";
		cin>>num;
		cout<<endl;

		int i;
		for(i=0 ; i<num ; i++){
			cout<<"Enter the "<<i<<" element : ";
			cin>>a[i];
		}
		cout<<endl;
	}

	int retNum(){
		return num;
	}

	void display(){
		int i;
		cout<<"Array is : ";
		for(i=0 ; i<num ; i++){
			cout<<a[i]<<"\t";
		}
		cout<<endl;
	}

	void linearSearch(int x){
		int i;
		for(i=0 ; i<num ;i++){
			if(x == a[i]){
				cout<<"Found at position : "<<i<<endl;
				return;
			}
		}
		cout<<"Not Found\n";
	}

	void binarySearch(int x, int low , int high){
		int mid;
		mid = (high+low)/2;
			if(x == a[mid]){
				cout<<"Found at position : "<<mid<<endl;
				return;
			}
			else if(x == a[high]){
				cout<<"Found at position : "<<high<<endl;
				return;
			}
			else if(low == mid){
				cout<<"Not Found\n";
				return;
			}
			else if(x > a[mid]){
				binarySearch(x , mid , high);
			}
			else if(x < a[mid]){
				binarySearch(x , low , mid);
			}
	}

	void fibonacciSearch(int x){
		int m2 = 1;
		int m1 = 1;
		int m0 = 0;

		int offset;
		offset = -1;

		while(m2 < num){
			int t1;
			int t2;
			t1 = m1;
			t2 = m2;

			m2 = t1 + t2;
			m1 = t2;
			m0 = t1;
		}

		int i;

		while(m2!=0){
			if((offset+m0)>(num-1)){
				i = num-1;
			}
			else{
				i = offset + m0;
			}

			if(a[i] == x){
				cout<<"Found at position : "<<i<<endl;
				return;
			}
			else if(x < a[i]){
				int t0;
				int t1;
				t0 = m0;
				t1 = m1;

				m2 = t1;
				m1 = t0;
				m0 = m2 - m1;
			}
			else if(x > a[i]){
				offset = i;
				int t0;
				int t1;
				t0 = m0;
				t1 = m1;

				m2 = t0;
				m1 = t1 - t0;
				m0 = m2 - m1;
			}
		}

		if(a[num-1]==x){
			cout<<"Found at position : "<<num-1<<endl;
		}

	}

	void sentinalSearch(int x){
		a[num] = x;
		int i = 0;
		while(a[i] != x){
			i++;
        }
        if(i == num){
            cout<<"Not Found";
        }
        else{
            cout<<"Found at position : "<<i;
        }
	}

};
int main() {
	RollNo_search A;
	int x;
	A.input();
	cout<<"Enter element to be searched : ";
	cin>>x;
	A.binarySearch(x,0,A.retNum()-1);
	A.linearSearch(x);
	A.fibonacciSearch(x);
	A.sentinalSearch(x);


	return 0;
}
