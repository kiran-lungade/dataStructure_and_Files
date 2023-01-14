/*
	NAME:: LUNGADE KIRAN SANJAY
	ROLL NO.:: 39
	BATCH:: S2
	SUBJECT:: DATA STRUCTURES AND FILES LAB
	TITLE:: IMPLEMENT THREADED BINARY TREE
*/

#include<iostream>
#define MAX_VALUE 65555;
using namespace std;
class node
{
	public:
		int key;
		node *left,*right;
		bool lthread,rthread;
};
class threadbst
{
	private:
		node *root;
	public:
		threadbst()
		{
			root=new node();
			root->right=root->left=root;
			root->lthread=true;
			root->key=MAX_VALUE;
		}
	void insert(int key)			//Insertion of elements
	{
		node *p=root;
		for(;;)						//infinite loop
		{
			if(p->key < key)
			{
				if(p->rthread)
					break;
				p=p->right;
			}
			else if(p->key > key)
			{
				if(p->lthread)
					break;
				p=p->left;
			}
			else{
				return;
			}
		}
		node *temp=new node();
		temp->key=key;
		temp->lthread=temp->rthread=true;
		if(p->key < key)
		{
			temp->right=p->right;
			temp->left=p;
			p->right=temp;
			p->rthread=false;
		}
		else
		{
			temp->right=p;
			temp->left=p->left;
			p->left=temp;
			p->lthread=false;
		}
	}
	void display()
	{
		node *temp=root,*p;
		for(;;)
		{
			p=temp;
			temp=temp->right;
			if(!p->rthread)
			{
				while(!temp->lthread)
				{
					temp=temp->left;
				}
			}
			if(temp==root)
				break;
			cout<<temp->key<<"  ";
		}
		cout<<endl;
	}
	bool search(int key)
	{
		node *temp=root->left;
		for(;;)
		{
			if(temp->key < key)
			{
				if(temp->rthread)
					return false;
				temp=temp->right;
			}
			else if(temp->key > key)
			{
				if(temp->lthread)
					return false;
				temp=temp->left;
			}
			else{
				return true;
			}
		}
	}
};
int main()
{
	int value,ch,c1,ch1;
	threadbst t;
	do{
		cout<<"\nEnter the operation you want to perform::\n\t1.INSERT\t2.Display\t3.SEARCH::\t4.EXIT\t";
		cin>>ch;
		switch(ch)
		{
			case 1:            //Inserting the thread
			do{
				cout<<"Enter the node :: ";
				cin>>value;
        		t.insert(value);
        		cout<<value<<" inserted on a tree";
       			cout<<"\n Do you want to continue::\n\t1.YESS\t2.NOO::"<<endl;
	    		cin>>c1;
		    }while(c1==2);

		  		break;
		  	
		  	case 2:					//Displaying the tree
		  		t.display();
		  		break;
		  		
		  	case 3:            //Searching the element
		  		cout<<"Enter the searching element";
		  		cin>>value;
		  		if(t.search(value)==true)
		  			cout<<value<<" Element is present on tree";
		  		else
		  			cout<<value<<" Element is absent";
		  		break;
		  		
		  	case 4:
		  		cout<<"\nDo you want to continue::\t";
		  	   cin>>ch1;
		  	break;
		 } 		

		}while(ch!=4);
}
