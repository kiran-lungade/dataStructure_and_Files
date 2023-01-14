/*
	NAME:: LUNGADE KIRAN SANJAY
	ROLL NO:: 39
	BATCH:: S2
	SUBJECT:: DATA STRUCTURES AND FILES
	PRACTICAL NO.:: 05
	TITLR:: HEAP 
*/

#include<iostream>
using namespace std;
int H[12];
int size=-1;

int parent(int i)
{
	return(i-1)/2;
}

int leftChild(int i)
{
	return((2*i)+1);
}

int rightChild(int i)
{
	return((2*i)+2);
}

void shiftUp(int i)
{
	while(i>0 && H[parent(i)]<H[i])
	{
		swap(H[parent(i)],H[i]);
		i=parent(i);
	}
}

void shiftDown(int i)
{
	int maxIndex=i;
	int l=leftChild(i);
	if(l<=size && H[l]>H[maxIndex])
	{
		maxIndex=l;
	}
	int r=rightChild(i);
	if(r<=size && H[r]>H[maxIndex])
	{
		maxIndex=r;
	}
	if(i!=maxIndex)
	{
		swap(H[i],H[maxIndex]);
		shiftDown(maxIndex);
	}
}

void insert(int p)
{
	size=size+1;
	H[size]=p;
	shiftUp(size);
}

int extractMax()
{
	int result=H[0];
	H[0]=H[size];
	size=size-1;
	shiftDown(0);
	return result;
}

void changePriority(int i,int p)
{
	int oldp=H[i];
	H[i]=p;
	if(p>oldp)
	{
		shiftUp(i);
	}
	else{
		shiftDown(i);
	}
}

int getMax()
{
	return H[0];
}

void remove(int i)
{
	H[i]=getMax()+1;
	shiftUp(i);
	extractMax();
}

int main()
{
	insert(45);
	insert(35);
	insert(12);
	insert(30);
	insert(32);
	insert(10);
	insert(5);
	insert(25);
	insert(24);
	insert(30);
	insert(31);
	insert(6);
	insert(4);
	
	int i=0;
	cout<<"Priority Queue is::"<<"\n";
	while(i<=size)
	{
		cout<<H[i]<<"\t";
		i++;
	}
	cout<<"\nNode with maximum priority is::"<<extractMax()<<"\n";
	cout<<"Priority queue after extracting maximum element is::"<<"\n";
	
	int j=0;
	while(j<=size)
	{
		cout<<H[j]<<"\t";
		j++;
	}
	cout<<"\n";
	changePriority(3,50);
	cout<<"PriorityQueue after priority change is::"<<"\n";
	
	int k=0;
	while(k<=size)
	{
		cout<<H[k]<<"\t";
		k++;
	}
	cout<<"\n";
	remove(3);
	cout<<"Priority Queue after removing element is::"<<"\n";
	
	int l=0;
	while(l<=size)
	{
		cout<<H[l]<<"\t";
		l++;
	}
	return 0;
}
