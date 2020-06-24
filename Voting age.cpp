#include<iostream>
using namespace std;
int main()
{
	int age;
	cout<<"The minimum voting age in INDIA is 18 years. Check your vote eligibility here"<<endl;
	cout<<"Please enter your Age: ";
	cin>>age;
	cout<<endl;
	
	if(age<18)
	{
		cout<<"Sorry, you are not eligible to vote.";
	}
	else
	{
		cout<<"You are eligible to vote. Thank you for your contribution!";
	}
	
	return 0;
}
