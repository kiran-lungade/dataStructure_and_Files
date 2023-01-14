/*
					CIA PRESENTATION 2
			SUBJECT:: DATA STRUCTURES AND FILES
			TITLE:: INSERT OPERATION ON HASH TABLE WITH REPLACEMENT
			NAME::  01- ADHAV VIRAJ
					26- HON SAURABH
					30- JAPE DIPJYOT
					39- LUNGADE KIRAN
*/

#include<iostream>
using namespace std;

int insert(int data[30],int flag[30],int x,int b)           //b=max_size
{
    int h;
    int count=0;
    h=x%b;  //hash function

    if (flag[h]==0)     // Element not present at start position
    {
        data[h]=x;
        flag[h]=1;   
    }

    else if (data[h]%b==x%b)      //element present but both are giving same mod
    {
        count=0;
        int j=h;                                    //find empty position
        while (flag[j]==1 && count < b)
        {
            j=(j+1)%b;
            count++;
        }
         if (count==b)
        {
            cout<<"HASH TABLE FULL";
            return 0;
        }


        data[j]=x;
        flag[j]=1;  
        
    }

    else   //element present but both are in different mod so here we will replace element
    {
        int j=h;
        while (flag[j]==1 && count <b)
        {
            j=(j+1)%b;
            count++;
        }
        if (count==b)
        {
            cout<<"HASH TABLE FULL";
            return 0;    
        }
       int i=data[h]%b;

        data[j]=data[h];
        flag[j]=1;

        data[h]=x;
    }   
    return 0;
} 

int display(int data[30],int flag[30],int x,int b)
{
    cout<<"\nHASH TABLE WITH REPLACEMENT";
	cout<<"\n--------------------";
    cout<<"\nINDEX"<<"\t\tDATA";
    cout<<"\n--------------------";
    for (int i = 0; i < b; i++)
    {
        if (flag[i]==1)
        {
            cout<<"\n"<< i<<"\t\t"<<data[i];

        }
        else
            cout<<"\n"<< i<<"\t\t"<<"-1";
        
    }
    cout<<"\n--------------------"<<endl;
    return 0;
}

int main()
{
    int ch,b,x,i,j;
    int data[30],flag[30];
    cout<<"\n ENTER SIZE ON HASH TABLE:: ";
    cin>>b;

    for (i = 0; i < b; i++)
    {
        flag[i]=0;
    }
    
    do
    {
        cout<<"\t1)INSERT \t2)DISPLAY \nENTER THE CHOICE:: ";
        cin>>ch;

        switch (ch)
        {
        case 1:
                cout<<"\nENTER THE DATA:: ";
                cin>>x;
                insert(data,flag,x,b);

            break;
        case 2:
            display(data,flag,x,b);
            break;
           
        }
    } while (ch!=3);

}
