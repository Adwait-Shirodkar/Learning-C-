#include<iostream>
using namespace std;

class time{
	public:
		int h;
		int m;
		int s;
};

class seconds : public time
{

	public:
		intos()
		{
			
			cout<<"Enter time: "<<endl;
			cout<<" Hours? ";
			cin>>h;
			cout<<endl;
			cout<<" Minutes? ";
			cin>>m;
			cout<<endl;
			cout<<" Seconds? ";
			cin>>s;
			cout<<endl;
		}
};

int main()
{
	float s1, s2, st;
	seconds a;
	a.intos();
	cout<<" The time is = "<<a.h<<" : "<<a.m<<" : "<<a.s<<endl;
	s1= a.h*3600;
	s2= a.m*60;
	st= s1+ s2+ a.s;
	cout<<" Time in total seconds: "<<st;
	return 0;
}

