#include <iostream>

using namespace std;

class String{
	
	int len,i;
	char strn[30];

	public:
	void input();
	void length();
	void strcopy(String s1);
	void strconc(String s1);

	void substr(String s1);
	void equal();
	void reverse();
	void frequency();
	void cut();
	void removechar();
	void replace();
	void palindrome();

};

void String::input(){

	cout<<"Enter the string : ";
	cin>>strn;

}

void String::length(){

	len = 0;
	for (i=0;strn[i]!='\0';i++){
	len++;
	}
	
	cout<<"Length of string is : "<<len<<endl;;

}

void String::strcopy(String s1){

	for(i=0;i<len;i++){
	s1.strn[i]=strn[i];
	}

	strn[len]='\0';

	cout<<"Copied string : "<<s1.strn<<endl;

}

void String::strconc(String s1){

	char str[60];
	int p=0;

	for(i=0;i<len;i++){
	strn[len+i]=s1.strn[i];
	p++;
	}
	
	strn[len+p]='\0';

	cout<<"Concatenaded String is : "<<strn<<endl;	
	
}

void String::substr(String s1){

	

}

int main(){

char copy[30];

String s1,s2,s3;

s1.input();
s2.input();
s1.length();
s1.strcopy(s3);
s1.strconc(s2);

}

















