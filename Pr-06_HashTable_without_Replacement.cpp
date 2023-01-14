/*
	NAME:: LUNGADE KIRAN SANJAY
	ROLL NO.:: 39
	BATCH:: S2
	SUBJECT:: DATA STRUCTURESA AND FILES LAB
	TITLE:: LINEAR PROBING WITHOUT REPLACEMENT
*/


#include<iostream>
using namespace std;
#define MAX 10
#define SIZE 10
struct hashtable
{
	int chain;
	long key;
	char name;
}s[MAX];
class hasht
{
	public:
		int hash(int telno);
};
int hasht :: hash(int telno)
{
	int h;
	h=telno % MAX;
	return h;
}
int main()
{
	int i,flag1=0,ch,no1,h,c,index;
	int data[SIZE],flag[SIZE],chain[SIZE],j;
	char sname;
	hasht t;
	for(i=0;i<MAX;i++)
	{
		s[i].key=-1;
		s[i].chain=-1;
		s[i].name='-';
	}
	do{
		for(j=0;j<MAX;j++)
		{
			if(s[j].key==-1)
			break;
		}
		if(j==-MAX)
		{	
			cout<<"\nHASH TABLE IS FULL";
			break;
		}
		cout<<"ENTER TELEPHONE NUMBER :: ";
		cin>>no1;
		cout<<"ENTER NAME :: ";
		cin>>sname;
		h=t.hash(no1);
		c=-1;
		index=h;
		do{
			if(s[h].key==-1)
			{
				flag1=1;
				s[h].key=no1;
				s[h].name=sname;
				if(c!=-1)
					s[c].chain=h;
			}
			else if(t.hash(s[h].key)==index)
			c=h;
			h=t.hash(h+1);
		}while(flag1==0 && h<MAX);
		flag1=0;
		cout<<"\n---------------------------------------------------";
		cout<<"\nINDEX"<<"\t"<<"TELEPHONE"<<"\t"<<"NAME"<<"\t"<<"CHAIN"<<"\n";
		cout<<"---------------------------------------------------\n";
		for(i=0;i<MAX;i++)
			cout<<i<<"\t"<<s[i].key<<"\t\t"<<s[i].name<<"\t"<<s[i].chain<<"\n";
			cout<<"----------------------------------------------------";
			cout<<"\nDO YOU WANT TO CONTINUE :: ";
			cin>>ch;
	}while(ch==1);
	return 0;
}
