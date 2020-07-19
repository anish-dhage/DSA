#include <iostream>

using namespace std;

class Mat{

public:
int row;
int col;
int ele[10][10];
int i,j;

void input();
void uppertriangular();
void diagsum();
void transpose();
void add(Mat a, Mat b);
void substract(Mat a, Mat b);
void multiply(Mat a, Mat b);
void saddle();

};

void Mat::input(){

	cout<<"Enter the no of rows and columns\n";
	cin>>row>>col;

	for (i=0;i<row;i++)
	{
		for (j=0;j<col;j++)
		{
		cout<<"Enter the (" << i+1<<","<<j+1 <<") element of matrix : ";
		cin>>ele[i][j];
		}
	}

}

void Mat::uppertriangular(){

int t=0;

	if(row==col)
	{	
		for (i=0;i<row;i++)
		{
			for (j=0;j<col;j++)
			{
				if(i>j && ele[i][j]==0)
				{
				t=1;
				}
				else if(i>j && ele[i][j]!=0)
				{
				t=0;
				}
			}
		}
	}


	else
	{
	cout<<"The Matrix is not upper triangular \n";
	}


	if(t==1){
	cout<<"The Matrix is upper triangular \n";}
	else{
	cout<<"The Matrix is not upper triangular \n";}

}

void Mat::diagsum()
{

int sum1,sum2;

sum1=0;
sum2=0;

for (i=0;i<row;i++)
{
	for (j=0;j<col;j++)
	{
		if(i==j)
		{
		sum1 = sum1 + ele[i][j];
		}
	}
}

for (i=0,j=col-1;i<row,j>=0;i++,j--)
{
	sum2 = sum2 + ele[i][j];
}


cout<<"Sum of Diagonals is starting from (1,1) is : "<<sum1<<endl;
cout<<"Sum of Diagonals is starting from (1,3) is : "<<sum2<<endl;
	
}

void Mat::transpose()
{

	int temp[row][col];

	for (i=0;i<row;i++)
	{
		for (j=0;j<col;j++)
		{
		temp[i][j]=ele[j][i];
		}
	}

	cout<<"Transpose is : \n";

	for (i=0;i<row;i++)
	{
		for (j=0;j<col;j++)
		{
		cout<<temp[i][j]<<"\t";
		}

	cout<<endl;
	}


}

void Mat::add(Mat a, Mat b)
{
	int sum[row][col];

	for (i=0;i<row;i++)
	{
		for (j=0;j<col;j++)
		{
		sum[i][j]=a.ele[i][j]+b.ele[i][j];
		}
	}

	cout<<"Sum is : \n";

	for (i=0;i<row;i++)
	{
		for (j=0;j<col;j++)
		{
		cout<<sum[i][j]<<"\t";
		}

	cout<<endl;
	}
				
}

void Mat::substract(Mat a, Mat b)
{
	int diff[row][col];

	for (i=0;i<row;i++)
	{
		for (j=0;j<col;j++)
		{
		diff[i][j]=a.ele[i][j]-b.ele[i][j];
		}
	}

	cout<<"Difference is : \n";

	for (i=0;i<row;i++)
	{
		for (j=0;j<col;j++)
		{
		cout<<diff[i][j]<<"\t";
		}

	cout<<endl;
	}
				
}

void Mat::multiply(Mat a, Mat b)
{
	int k;
	int mult[row][col];

	for (i=0;i<row;i++)
	{
		for (j=0;j<col;j++)
		{
			mult[i][j] = 0;
			for (k=0;k<col;k++)
			{
			mult[i][j]+=a.ele[i][k]*b.ele[k][j];
			}
		}
	}


	cout<<"Multiplication is : \n";

	for (i=0;i<row;i++)
	{
		for (j=0;j<col;j++)
		{
		cout<<mult[i][j]<<"\t";
		}

	cout<<endl;
	}

}

void Mat::saddle()
{
	int min[row],max[col];

	for (i=0;i<row;i++)
	{
	min[i]=ele[i][0];
		for (j=0;j<col;j++)
		{
		
			if(min[i]>ele[i][j])
			{
			min[i]=ele[i][j];
			}
		}
	}	

	for (j=0;j<col;j++)
	{
	max[j]=ele[0][j];
		for (i=0;i<row;i++)
		{
			if(max[j]<ele[i][j])
			{
			max[j]=ele[i][j];
			}
		}
	}	

	for (i=0;i<row;i++)
	{
		for (j=0;j<col;j++)
		{
			if(min[i]==max[j])
			{
			cout<<"Saddle point is : "<<max[j]<<"\n";
			}
		}
	}

}

int main()
{

Mat a,b;

cout<<"Enter elements of Matrix A\n";
a.input();
cout<<"Enter elements of Matrix B\n";
b.input();

a.uppertriangular();
a.diagsum();
a.transpose();
a.add(a,b);
a.substract(a,b);
a.multiply(a,b);
a.saddle();

return 0;
}









