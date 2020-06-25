#include<string>
#include<iostream>
using namespace std;
int main()
{
	int n;
	int a[5];
	cout<<"Enter Elements: ";
	
	for(n=0;n<5;n++)
	{
		cin>>a[n];
		cout<<endl;
	}
	cout<<"You entered: ";
	for(n=0;n<5;n++)
	{
		cout<<a[n]<<endl;
	}
	return 0;
}
