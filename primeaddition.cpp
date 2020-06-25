#include<iostream>
using namespace std;

int test(int x);

int main()
{
	int i,p,k;
	cout<<"Enter a positive integer: ";
	cin>>p;
		for(i=2;i<=p/2;++i)
		{
			k=p-i;
			if (test(i))
			{
				if (test(k))
				{
					cout<<p<<"="<<i<<"+"<<k<<endl;
				}
			}
		}
		return 0;
}

int test(int x)
{
	int a;
	bool t=true;
	//dividing the number by every number until we arrive to half of the input
	for(a=2;a<=x/2;++a)
	{
		if(x%a==0)
		{
			t=false;
			break;
		}
	}
	return t;
}
