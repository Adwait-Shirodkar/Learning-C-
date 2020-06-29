#include<iostream>
#include<string.h>
#include<conio.h>
#include<cstdlib>
#include<cstdio>
#include<iomanip>
using namespace std;
int main()
{
	FILE *fp,*ft;
	char another, choice;
	struct student
	{
		char first_name[50], last_name[50];
		char course[100];
		int section;
	};
	struct student e;
	char xfirst_name[50], xlast_name[50];
	long int recsize;
	
	fp= fopen("users.txt","rb+");
	if(fp==NULL)
	{
		fp=fopen("users.txt","wb+");
		if(fp==NULL)
		{
			puts("cannot open file");
			return 0;
		}
	}
	
	recsize=sizeof(e);
	
	while(1)
	{
		system("cls");
		
		cout<<"\t\t========== STUDENT DATABASE MANAGEMENT SYSTEM ==========";
		cout<<endl<<endl<<"                                       ";
		cout<<endl<<endl;
		cout<<endl<<"\t\t\t 1. Add Records.";
		cout<<endl<<"\t\t\t 2. List Records.";
		cout<<endl<<"\t\t\t 3. Modify Records.";
		cout<<endl<<"\t\t\t 4. Delete Records.";
		cout<<endl<<"\t\t\t 5. Exit Program.";
		cout<<endl<<endl;
		cout<<"\t\t\t Select Your Choice: \t";
		fflush(stdin);
		choice=getche();
		switch(choice)
		{
			case '1':
				fseek(fp,0,SEEK_END);
				another = 'Y';
				while(another == 'Y' || another == 'y')
				{
					system("cls");
					cout<<"Enter the first name: ";
					cin>>e.first_name;
					cout<<"Enter the last name: ";
					cin>>e.last_name;
					cout<<"Enter the Course: ";
					cin>>e.course;
					cout<<"Enter the Section: ";
					cin>>e.section;
					fwrite(&e,recsize,1,fp);
					cout<<endl<<"Add Another Record (Y/N)";
					fflush(stdin);
					another = getchar();
				}
				break;
				
				case '2':
					system("cls");
					rewind(fp);
					cout<<"=== View the records in the database ===";
					cout<<endl;
					while (fread(&e,recsize,1,fp)==1)
					{
						cout<<endl;
						cout<<endl<<e.first_name<<setw(10)  <<e.last_name;
						cout<<endl<<endl<<e.course<<setw(10)  <<e.section;
					}
					cout<<endl<<endl;
					system("pause");
					break;
					
				case '3':
				system("cls");
				another = 'Y';
				while (another == 'Y' || another == 'y')
				{
					cout<<endl<<"Enter the last name of the student: ";
					cin>> xlast_name;
					
					rewind(fp);
					while (fread(&e,recsize,1,fp) == 1)
					{
						if (strcmp(e.last_name,xlast_name)==0)
						{
							cout<<"Enter new First Name: ";
							cin>>e.first_name;
							cout<<"Enter new Last Name: ";
							cin>>e.last_name;
							cout<<"Enter new Course: ";
							cin>>e.course;
							cout<<"Enter new Section: ";
							cin>>e.section;
							fseek(fp, - recsize,SEEK_CUR);
							fwrite(&e,recsize,1,fp);
							break;
						}
						else
						cout<<"record not found.";	
					}
					cout<<endl<<"Modify Another Record (Y/N)";
					fflush(stdin);
					another = getchar();
					}	
					break;
					
					case '4':
						system("cls");
						another = 'Y';
						while (another == 'Y' || another == 'y')
						{
							cout<<endl<<"Enter the last name of the student to delete the record: ";
							cin>>xlast_name;
							
							ft=fopen("temp.dat","wb");
							
							rewind(fp);
							while(fread (&e,recsize,1,fp)==1)
							{
								if (strcmp(e.last_name,xlast_name)!=0)
								{
									fwrite(&e,recsize,1,ft);
								}
								fclose(fp);
								fclose(ft);
								remove("users.txt");
								remove("temp.dat","users.txt");
							
							fp=fopen("users.txt","rb+");
							
							cout<<endl<<"Delete another record (Y/N)";
							fflush(stdin);
							another = getchar();
							}
							break;
						}
		}
		return 0;
	}
}
