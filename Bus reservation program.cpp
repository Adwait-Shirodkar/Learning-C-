#include<iostream>
#include<string.h>
#include<conio.h>
#include<cstdlib>
#include<cstdio>
using namespace std;

static int p=0;

class content
{
	char busno[5],driver[10],arrival[5],departure[5],from[10],to[10],seat[8][4][10];
	
	public:
		void install();
		void allotment();
		void empty();
		void show();
		void avail();
		void position(int l);
}

bus[10];
void vline(char ch)
{
	for (int i=80;i>0;i--)
	cout<<ch;
}

void content::install()
{
	cout<<"Enter the bus no. ";
	cin>>bus[p].busno;
	
	cout<<endl<<"Enter Bus driver's name: ";
	cin>>bus[p].driver;
	
	cout<<endl<<"Enter arrival time: ";
	cin>>bus[p].arrival;
	
	cout<<endl<<"Enter Departure: ";
	cin>>bus[p].departure;
	
	cout<<endl<<"Enter From: ";
	cin>>bus[p].from;
	
	cout<<endl<<"Enter to: ";
	cin>>bus[p].to;
	
	bus[p].empty();
	p++;
}

void content::allotment()
{
	int seat;
	char number[5];
	
	top:
		cout<<"Bus no.: ";
		cin>>number;
		
		int n;
		for(n=0;n<=p;n++)
		{
			if(strcmp(bus[n].busno, number)==0)
			break;
		}
		
		while(n<=p)
		{
			cout<<endl<<"Seat number: ";
			cin>>seat;
			
			if(seat>32)
			{
				cout<<endl<<"There are only 32 seats available in the bus.";
			}
			else
			{
				if(strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)
				{
					cout<<"Enter passanger name: ";
					cin>>bus[n].seat[seat/4][(seat%4)-1];
					break;
				}
				else
				cout<<"This no. seat is already reserved: "<<endl;
			}
			
			if(n>p)
			{
				cout<<"Enter correct bus no.: "<<endl;
				goto top;
			}
		}
}

void content::empty()
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<4;j++)
		{
			strcpy(bus[p].seat[i][j], "Empty");
		}
	}
}

void content::show()
{
	int n;
	char number[5];
	cout<<"Enter bus no.: ";
	cin>>number;
	
	for(n=0;n<=p;n++)
	{
		if(strcmp(bus[n].busno, number)==0)
		break;
	}
	
	while(n<=p)
	{
		vline('*');
		cout<<"Bus no: \t"<<bus[n].busno<<endl<<"driver: \t"<<bus[n].driver<<endl<<"Arrival time: \t"<<bus[n].arrival<<endl<<"Departure time: \t"<<bus[n].departure<<endl<<"From: \t"<<bus[n].from<<endl<<"To: \t"<<bus[n].to<<endl;
		vline('*');
		int j;
		bus[0].position(n);
		int a=1;
		for(int i=0;i<8;i++)
		{
			a++;
			if(strcmp(bus[n].seat[i][j], "Empty")!=0)
			cout<<endl<<"The seat no. "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";
		}
			break;
	}

	
	if(n>p)
	cout<<"Enter correct bus no. :";
}

void content::position(int l)
{
	int s=0, p=0;
	for(int i=0;i<8;i++)
	{
		cout<<endl;
		for(int j=0;j<4;j++)
		{
			s++;
			if(strcmp(bus[l].seat[i][j], "Empty")==0)
			{
				cout.width(5);
				cout.fill(' ');
				cout<<s<<".";
				cout.width(10);
				cout.fill(' ');
				cout<<bus[1].seat[i][j];
				p++;
			}
			
			else
			{
				cout.width(5);
			    cout.fill(' ');
			    cout<<s<<".";
			    cout.width(10);
			    cout.fill(' ');
			    cout<<bus[l].seat[i][j];
			}
		}
	}
	cout<<endl<<endl<<"There are "<<p<<" seats empty in Bus no. "<<bus[l].busno;
}

void content::avail()
{
	int n;
	vline('*');
	cout<<"Bus no: \t"<<bus[n].busno<<endl<<"driver: \t"<<bus[n].driver<<endl<<"Arrival time: \t"<<bus[n].arrival<<endl<<"Departure time: \t"<<bus[n].departure<<endl<<"From: \t"<<bus[n].from<<endl<<"To: \t"<<bus[n].to<<endl;
	vline('*');
	vline('-');
	
}

int main()
{
	system("cls");
	int w;
	while(1)
	{
		cout<<endl<<endl<<endl<<endl<<endl;
	    cout<<"\t\t\t1.Install."<<endl<<"\t\t\t"<<"2.Reservation."<<endl<<"\t\t\t3. Show."<<endl<<"\t\t\t4.Buses available."<<endl<<"\t\t\t5. Exit";
	    cout<<endl<<"\t\t\tEnter your choice: ";
	    cin>>w;
	    switch(w)
	    {
	    	case 1: bus[p].install();
	    			break;
	    			
	    	case 2: bus[p].allotment();
	    			break;
					
			case 3: bus[0].show();
	    			break;
					
			case 4: bus[0].avail();
	    			break;
					
			case 5: exit(0);								
		}
	}
	return 0;
}

