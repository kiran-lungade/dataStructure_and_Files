/*
         NAME:: LUNGADE KIRAN SANJAY
         SUBJECT:: DATA STRUCTURES AND FILES LAB
         ROLL NO.:: 39
         PRACTICAL:: 01
         TILTE:: IMPLEMENTATION OF BINARY TREE AS ADT
*/


#include<iostream>
using namespace std;
struct node{
	int data;
	node *left,*right;
};
class binary
{
	node *newnode, *root;
	public:
		binary()
		{
			root=NULL;
		}
		void  create();
		void insert(node *,node *);
		void display();
		void inorder(node *);
        void leaf();
        void display_leaves(node *temp);
        void longestpath();
        int depth(node *);
};
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

void binary::display()
{
   	if(root==NULL)
	{
		cout<<"root is not created";
	}
	else
	{
		inorder(root);
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

void binary::leaf()
{
        display_leaves(root);
}
void binary::display_leaves(node *temp)
{
        if(root==NULL)
        {
            cout<<"Tree is not created";
        }
        if(temp!=NULL)
        {
            if((temp->left==NULL)&&(temp->right==NULL))
            {
                cout<<"\t"<<temp->data;
            }
            else{
                display_leaves(temp->left);
                display_leaves(temp->right);
            }
        }
}

void binary::longestpath()
{
        if(root==NULL)
            cout<<"Tree is empty";
        else{
             int ldepth=depth(root);
             int rdepth=depth(root);
             if(ldepth>rdepth)
                  cout<<"Depth of treee is::"<<ldepth;
             else
                  cout<<"Depth of tree is::"<<rdepth;
        }
}
int binary::depth(node *root)
{
        if(root==NULL)
            return 0;
        else{
              int ldepth=depth(root->left);
              int rdepth=depth(root->right);
              if(ldepth>rdepth)
                  return (ldepth+1);
              else
                  return (rdepth+1);
        }
}

int main()
{
	binary b;

	int choice,c,c1;
	do{
    	cout<<"\nWhich operation you want to perform on TREE::\n\t1.CREATE\t2.DISPLAY OF INORDER\t3.LEAVES\t4.HEIGHT\t5.EXIT"<<endl;
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
		        cout<<"Inorder tree is ::"<<endl;
		        b.display();
	        	break;
		case 3:         //Displaying the leaves
			cout<<"Leaves of tress are::";
                        b.leaf();
                        break;
                case 4:         //Displaying the depth
                        b.longestpath();
                        break;
                case 5:		//Exit
			cout<<"\n Do youb want to continue::\n\t1.YESS\t2.NOO::"<<endl;
			cin>>c;
	    }
	}while(c!=2);
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~OUTPUT~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    
Which operation you want to perform on TREE::
	1.CREATE	2.DISPLAY OF INORDER	3.LEAVES	4.HEIGHT	5.EXIT
1
Enter the node value::10

 Do youb want to continue::
	1.YESS	2.NOO::
1
Enter the node value::20
On which subtree yo want to add this element::
	For left press l/L and for right press r/R::l

 Do youb want to continue::
	1.YESS	2.NOO::
1
Enter the node value::30
On which subtree yo want to add this element::
	For left press l/L and for right press r/R::r

 Do youb want to continue::
	1.YESS	2.NOO::
1
Enter the node value::40
On which subtree yo want to add this element::
	For left press l/L and for right press r/R::l
On which subtree yo want to add this element::
	For left press l/L and for right press r/R::l

 Do youb want to continue::
	1.YESS	2.NOO::
1
Enter the node value::50
On which subtree yo want to add this element::
	For left press l/L and for right press r/R::l
On which subtree yo want to add this element::
	For left press l/L and for right press r/R::r

 Do youb want to continue::
	1.YESS	2.NOO::
1
Enter the node value::60
On which subtree yo want to add this element::
	For left press l/L and for right press r/R::r
On which subtree yo want to add this element::
	For left press l/L and for right press r/R::r

 Do youb want to continue::
	1.YESS	2.NOO::
2

Which operation you want to perform on TREE::
	1.CREATE	2.DISPLAY OF INORDER	3.LEAVES	4.HEIGHT	5.EXIT
2
Inorder tree is ::
	40	20	50	10	30	60
Which operation you want to perform on TREE::
	1.CREATE	2.DISPLAY OF INORDER	3.LEAVES	4.HEIGHT	5.EXIT
3
Leaves of tress are::	40	50	60
Which operation you want to perform on TREE::
	1.CREATE	2.DISPLAY OF INORDER	3.LEAVES	4.HEIGHT	5.EXIT
4
Depth of tree is::3
Which operation you want to perform on TREE::
	1.CREATE	2.DISPLAY OF INORDER	3.LEAVES	4.HEIGHT	5.EXIT
5

 Do youb want to continue::
	1.YESS	2.NOO::
2

*/
