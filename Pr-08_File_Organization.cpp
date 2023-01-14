/*
	NAME:: LUNGADE KIRAN SANJAY
	ROLL NO.:: 39
	BATCH:: S2
	SUBJECT:: DATA STRUCTURES AND FILES LAB
	TITLE:: IMPLEMENT OF FILE ORGANIZATION
*/

#include<iostream>
#include<fstream>
using namespace std;
struct student{
	int rollno;
	char name[50];
	float per;
}s;
int main()
{
	int ch,c,rno,flag;
	ofstream outf,outf1;
	outf.open("stud.txt");
	ifstream inf;
	do{
		cout<<"\n1.ADD RECORD \t2.DISPLAY RECORD \t3.DELETE RECORD \t4.MODIFY RECORD";
		cout<<"\nENTER THE CHOICE::  ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				do{
					cout<<"\nENTER ROLL NO, NAME & PERCENTAGE::  ";
					cin>>s.rollno>>s.name>>s.per;
					outf<<"\t"<<s.rollno;
					outf<<"\t"<<s.name;
					outf<<"\t"<<s.per;
					cout<<"\nDo u want to continue::  ";
					cin>>c; 
				}while(c==1);
				cout<<"\nRECORD ADDED SUCCESSFULLY";
				outf.close();
				break;
				
			case 2:
				inf.open("stud.txt");
				while(!inf.eof())
				{
					cout<<"\n";
					inf>>s.rollno;
					inf>>s.name;
					inf>>s.per;
					cout<<"\nROLL NO IS:: "<<s.rollno;
					cout<<"\nNAME IS: "<<s.name;
					cout<<"\nPERCENTAGE IS: "<<s.per;
				}
				inf.close();
				break;
				
			case 3:
				outf1.open("student.txt");
				inf.open("stud.txt");
				cout<<"\nENTER ROLL NO WHICH U WANT TO DELETE::  ";
				cin>>rno;
				flag=0;
				while(!inf.eof())
				{
					inf>>s.rollno;
					inf>>s.name;
					inf>>s.per;
					if(rno==s.rollno)
					{
						flag=1;
						cout<<"\nRECORD DELETED SUCCESSFULLY";
					}
					else if(rno!=s.rollno)
					{
						outf1<<"\t"<<s.rollno;
						outf1<<"\t"<<s.name;
						outf1<<"\t"<<s.per;
					}
				}
				if(flag==0)
				{
					cout<<"\nRECORD NOT PERSENT";
				}
				inf.close();
				outf1.close();
				remove("stud.txt");
				rename("student.txt","stud.txt");
				break;
				
			case 4:
				outf1.open("student.txt");
				inf.open("stud.txt");
				cout<<"\nENTER ROLL NO WHICH U WANT TO MODIFY::  ";
				cin>>rno;
				flag=0;
				while(!inf.eof())
				{
					inf>>s.rollno;
					inf>>s.name;
					inf>>s.per;
					if(rno==s.rollno)
					{
						cout<<"\nENTER ROLL NO, NAME & PERCENTAGE::  ";
						cin>>s.rollno>>s.name>>s.per;
						outf1<<"\t"<<s.rollno;
						outf1<<"\t"<<s.name;
						outf1<<"\t"<<s.per;
						flag=1;
					}
					else if(rno!=s.rollno)
					{
						outf1<<"\t"<<s.rollno;
						outf1<<"\t"<<s.name;
						outf1<<"\t"<<s.per;
					}
				}
				inf.close();
				outf1.close();
				if(flag==0)
				{
					cout<<"\nRECORD NOT PERSENT";
				}
				remove("stud.txt");
				rename("student.txt","stud.txt");
				break;
		}
		cout<<"\n\tWhat to continue::  ";
		cin>>c;
	}while(c==1);
	return 0;
}
