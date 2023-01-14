/*
	NAME:: LUNGADE KIRAN SANJAY
	ROLL NO.:: 39
	BATCH:: S2
	SUBJECT:: DATA STRUCTURES AND FILES LAB
	PRACTICAL NO.:: 02
	TITLE:: DISPLAYING THE TREE IN INORDER,PREORDER AND POSTORDER BY RECURSSIVE AND NON-RECURSSIVE
*/

#include<iostream>
using namespace std;
struct node{
	int data;
	node *left,*right;
};
class binary
{
	int top;
	node *newnode, *root,*temp,*stack[15],*parent;
	public:
		binary()
		{
			root=NULL;
			top=-1;
		}
		int isempty();
		int isfull();
		void push(node *);
		node * pop();

		void  create();
		void insert(node *,node *);
		void display1();
		void inorder(node *);
		void inorder_nonrec(node *);
        void display2();
        void preorder(node *);
		void preorder_nonrec(node *);
        void display3();
        void postorder(node *);
		void postorder_nonrec(node *);
		
};
int binary::isempty()
{
	if(top==-1)
		return 1;
	return 0;
}
int binary::isfull()
{
	if(top==14)
		return 1;
	return 0;
}
void binary::push(node * d)
{
	if(!isfull())
		stack[++top]=d;
}
node * binary::pop()
{
	node * temp=stack[top];
	top--;
	return temp;
}
void binary::create()
{
	newnode=new node();
	newnode->left=NULL;
	newnode->right=NULL;
	cout<<"Enter the node value::";
	cin>>newnode->data;
	if(root==NULL)
	{
		root=newnode;
	}
	else{
		insert(root,newnode);
	}
}
void binary::insert(node *root,node *newnode)
{
	char ch;
	cout<<"On which subtree yo want to add this element::\n\tFor left press l/L and for right press r/R::";
	cin>>ch;
	if(ch=='l'||ch=='L')
	{
		if(root->left==NULL)
		{
			root->left=newnode;
		}
		else{
			insert(root->left,newnode);
		}
	}
	else{
		if(root->right==NULL)
		{
			root->right=newnode;
		}
		else{
			insert(root->right,newnode);
		}
	}
}

void binary::display1()
{
   	if(root==NULL)
	{
		cout<<"root is not created";
	}
	else
	{
	   cout<<"Reccursive inorder tree is::";
		inorder(root);
		cout<<"\nNon-Reccursive inorder tree is::";
		inorder_nonrec(root);
	}
}		
void binary::inorder(node *ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->left);
		cout<<"\t"<<ptr->data;
		inorder(ptr->right);
	}
}
void binary::inorder_nonrec(node *root)
{
	binary s;
	while(!s.isempty()||root!=NULL)
	{
		while(root!=NULL)
		{
			s.push(root);
			root=root->left;
		}
		root=s.pop();
		cout<<"\t"<<root->data;
		root=root->right;
	}
}
void binary::display2()
{
   	if(root==NULL)
	{
		cout<<"root is not created";
	}
	else
	{
		cout<<"Reccursive preorder tree is::";
		preorder(root);
		cout<<"\nNon-Reccursive preorder tree is::";
		preorder_nonrec(root);
	}
}	
	
void binary::preorder(node *ptr)
{
	if(ptr!=NULL)
	{
		cout<<"\t"<<ptr->data;
		preorder(ptr->left);
		preorder(ptr->right);
	}
}
void binary::preorder_nonrec(node *root)
{
	binary s;
	while(!s.isempty()||root!=NULL)
	{
		while(root!=NULL)
		{
			cout<<"\t"<<root->data;
			s.push(root);
			root=root->left;
		}
		root=s.pop();
		root=root->right;
	}
}
void binary::display3()
{
   	if(root==NULL)
	{
		cout<<"root is not created";
	}
	else
	{
		cout<<"Reccursive postorder tree is::";
		postorder(root);
		cout<<"\nNon-Reccursive postorder tree is::";
		postorder_nonrec(root);
	}
}
		
void binary::postorder(node *ptr)
{
	if(ptr!=NULL)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		cout<<"\t"<<ptr->data;
		
	}
}
void binary::postorder_nonrec(node *root)
{
	int i=0,str[20];
	binary s;
	while(!s.isempty()||root!=NULL)
	{
		while(root!=NULL)
		{
			str[i++]=root->data;
			s.push(root);
			root=root->right;
		}
		root=s.pop();
		root=root->left;
	}
	while(--i>=0)
	cout<<"\t"<<str[i];
}
int main()
{
	binary b;

	int choice,c,c1;
	do{
    	cout<<"\nWhich operation you want to perform on TREE::\n\t1.CREATE\t2.DISPLAY OF INORDER\t3.DISPLAYING PREORDER\t4.DISPLAYING POSTORDER\t5.EXIT"<<endl;
    	cin>>choice;
    	switch(choice)

	    {
		case 1:         //Creating the tree
		    do{
        		b.create();
       			cout<<"\n Do youb want to continue::\n\t1.YESS\t2.NOO::"<<endl;
	    		cin>>c1;
		    }while(c1!=2);
        	break;
        	
   	case 2:         //Displaying the inorder tree
	      b.display1();
	     	break;
	     	
		case 3:         //Displaying the preorder tree
         b.display2();
         break;
         
      case 4:         //Displaying the postorder tree
          b.display3();
          break;
          
      case 5:		//Exit
			cout<<"\n Do youb want to continue::\n\t1.YESS\t2.NOO::"<<endl;
			cin>>c;
	    }
	}while(c!=2);
}
