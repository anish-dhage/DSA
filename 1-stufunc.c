#include <stdio.h>

struct grade
{
	char name[30];
	int rollno;
	int marks[5];
}student[100];

int i,j,k;	

void average();
void percentage();
void absentees();
void mode();
void minmax();

int main()
{

printf("Enter number of students : ");
scanf("%d",&j);

for(i=0;i<j;i++)
{
printf("Enter name of student : ");
scanf("%s",student[i].name);
printf("Enter rollno of student : ");
scanf("%d",&student[i].rollno);

	for(k=0;k<5;k++){
	printf("Enter marks of student in subject %d : ",k+1);
	scanf("%d",&student[i].marks[k]);
	}
}
int v;
do{
v=0;
printf("\n1.Average\n2.Percentage\n3.Absentees\n4.Mode\n5.Highest and Lowest\n6.Exit\n");
printf("Input Your Choice : ");
scanf("%d",&v);

switch(v){
 
case 1: average() ;continue;
case 2: percentage() ;continue;
case 3: absentees() ;continue;
case 4: mode() ;continue;
case 5: minmax() ;continue;

}
} while(v!=6);

return 0;

}


void average(){
float avg,total;

total=0;
avg=0;

//calculating avg
for(i=0;i<j;i++)
{
	for(k=0;k<5;k++){
	total+=student[i].marks[k];
	}
}

avg=(total)/j;
printf("Average of class is : %.2f \n",avg);
}

void percentage(){
//calculating percentage
float perct[j],ptotal;

for(i=0;i<j;i++)
{
ptotal=0;

	for(k=0;k<5;k++){
	ptotal+=student[i].marks[k];
	}

perct[i]=(ptotal/500)*100;
printf("Percentage of student %s is : %.2f \n",student[i].name,perct[i]);

}
}

void minmax(){

float perct[j],ptotal;

for(i=0;i<j;i++)
{
ptotal=0;

	for(k=0;k<5;k++){
	ptotal+=student[i].marks[k];
	}

perct[i]=(ptotal/500)*100;
}

float max=perct[0];
for(i=1;i<j;i++)
{
	if (max<perct[i]){
		max=perct[i];
	}
}	

float min=perct[0];
for(i=1;i<j;i++)
{
	if (min>perct[i]){
		min=perct[i];
	}
}	

printf("Maximum marks were %.2f\n %",max);
printf("Minimum marks were %.2f\n %",min);

}

void absentees(){
//calculating absentees
for(i=0;i<j;i++)
{
	for(k=0;k<5;k++){
		if(student[i].marks[k]==0){
		printf("RollNo %d was absent for exam %d \n",student[i].rollno,k+1);
		}
	}
}
}

void mode(){
//calculating mode
int p, q, arr[100] = {0}, n, brr[100] = {0}, r = 0, mxm = 0, mode;

int d=0;
n=j*5;
for (i=0;i<j;i++)
{
	for (p=d,k=0;p<n,k<5;k++,p++)
	{
		arr[p]=student[i].marks[k];
		d++;
	}
}

int tem=0,c=1;
for(i=0;i<n;i++)
{
	for(k=i+1;k<n;k++)
	{
		if(arr[i]>arr[k])
		{
		tem=arr[i];
		arr[i]=arr[k];
		arr[k]=tem;
		}
	}
}	

	for (p=0;p<n;p++)
	{
		printf("%d \t",arr[p]);
	}



for (p=0; p<n-1; p++)
{
	mode = 0;

        for (q=p+1; q<n; q++)
        {
            if (arr[p] == arr[q]) {
                mode++;
            }
        }

        if ((mode>mxm)&&(mode!=0)) {
            r=0;
	    mxm = mode;
            brr[r] = arr[p];
            r++;
        }
}

	printf("\nMode\t= ");
	for (p = 0; p < r; p++)
	printf("%d\n ",brr[p]);

}














	


