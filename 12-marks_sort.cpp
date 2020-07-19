//============================================================================
// Name        : marks_sort.cpp
// Author      : Anish
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Marks_sort{
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

	void selectionSort(){
		int i,j,temp;
		int min;
		for(i=0 ; i<num-1 ; i++){
			min = i;
			for(j=i+1 ; j<num ; j++){
				if(a[min] > a[j]){
					min = j;
				}
			}
			temp = a[min];
			a[min] = a[i];
			a[i] = temp;
		}
		display();
	}

	void bubbleSort(){
		int i,j;
		int temp = 0;
		for(i=0 ; i<num ; i++){
			for(j=0 ; j<num-i-1 ; j++){
				if(a[j] > a[j+1]){
					temp = a[j];
					a[j] = a[j+1];
					a[j+1] = temp;
				}
			}
		}
		display();
	}

	void insertionSort(){
		int i,j;
		int temp;
		for(i=0 ; i<num ; i++){
			j = i-1;
			temp = a[i];
			while(a[j]>temp && j>=0){
				a[j+1] = a[j];
				j--;
			}
			a[j+1] = temp;
		}
		display();
	}

    void shellSort()
    {
        int i, j, gap, temp;
        for(gap = num/2; gap > 0; gap = gap/2)
        {
            for(i = gap; i < num; i++)
            {
                for(j = i-gap; j >= 0; j = j-gap)
                {
                    if(a[j+gap] >= a[j]){
                        break;
                    }
                    else
                    {
                        temp = a[j];
                        a[j] = a[j+gap];
                        a[j+gap] = temp;
                    }
                }
            }
        }
        display();
    }

	void quickSort(int low ,int high){
		if(low >= high){
			return;
		}
		int p = low;
		int i = low + 1;
		int j = high;
		int temp;
		do{
			while(a[p]>a[i] && i<= high){
				i++;
			}
			while(a[p]<a[j] && j>= low){
				j--;
			}
			if(i < j){
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				i++;
				j--;
			}
		}while(i <= j);

		if (i > j){
			temp = a[p];
			a[p] = a[j];
			a[j] = temp;
		}

		quickSort(j+1 , high);
		quickSort(low , j-1);
	}
};

int main() {

	Marks_sort A;
	A.input();


    cout<<"\nInsertion Sort : \n";
	A.insertionSort();

	cout<<"\nBubble Sort : \n";
	A.bubbleSort();

	cout<<"\nSelection Sort : \n";
	A.selectionSort();

	cout<<"\nQuick Sort : \n";
	A.quickSort(0 , (A.retNum()-1));
	A.display();

    cout<<"\nShell Sort : \n";
	A.shellSort();

	return 0;
}
