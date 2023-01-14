/*
					CIA PRESENTATION 
		SUBJECT: DATA STRUCTURE AND FILES
		TITLE: HUFFMAN's ALGORITHM
		NAME: 01- ADHAV VIRAJ
			  26- HON SAURABH
			  30- JAPE DIPJYOT
			  39- LUNGADE KIRAN
*/


#include <iostream>
#include <queue>					// using Priority Queue
#define MAX_SIZE 100				// Maximum Height of Huffman Tree.
using namespace std;

class HuffmanTreeNode 
{
	public:
    	char data;					// Stores character
 		int freq;					// Stores frequency of the character
 		
    HuffmanTreeNode* left;			 // Left child of the current node
 	HuffmanTreeNode* right;			// Right child of the current node

    HuffmanTreeNode(char character,int frequency)		// Initializing the current node
    {
        data = character;
        freq = frequency;
        left = right = NULL;
    }
};
 
// Comparator class

class Compare 
{
	public:
    	bool operator()(HuffmanTreeNode* a,HuffmanTreeNode* b)

    {
		return a->freq > b->freq;			// Defining priority on the basis of frequency
    }
};
 
HuffmanTreeNode* generateTree(priority_queue<HuffmanTreeNode*,vector<HuffmanTreeNode*>,Compare> pq)		// Function to generate Huffman Encoding Tree
{
    while (pq.size() != 1) 					// We keep on looping till only one node remains in the Priority Queue
	{
        HuffmanTreeNode* left = pq.top();		// Node which has least frequency
        pq.pop();								// Remove node from Priority Queue
        HuffmanTreeNode* right = pq.top();		// Node which has least frequency
        pq.pop();								// Remove node from Priority Queue
 

        // A new node is formed with frequency left->freq + right->freq
        // We take data as 'Z' because we are only concerned with the frequency

        HuffmanTreeNode* node = new HuffmanTreeNode('Z', left->freq + right->freq);
        node->left = left;
        node->right = right;
        pq.push(node);							// Push back node created to the Priority Queue
    }
    return pq.top();
}
 
// Function to print the huffman code for each character 
// It uses arr to store the codes
void printCode(HuffmanTreeNode* root, int arr[], int top)
{
	int i;
    if (root->left) 				// Assign 0 to the left node and recur
	{
        arr[top] = 0;
        printCode(root->left, arr, top + 1);
    }

    if (root->right) 				// Assign 1 to the right node and recur
	{
        arr[top] = 1;
        printCode(root->right, arr, top + 1);
    }

    if (!root->left && !root->right) 	//If this is leaf node, then we print root->data & also print code for this character from arr
	{
        cout<<root->data<<""<<" =\t"<<root->freq<<""<<" =\t";
        for (i = 0; i < top; i++) 
		{
            cout << arr[i];
        }
        cout << endl;
    }
}

void HuffmanCode(char data[], int freq[], int size)
{
    // Declaring priority queue using comparator
    priority_queue<HuffmanTreeNode*, vector<HuffmanTreeNode*>,Compare>pq;

    for (int i = 0; i < size; i++) 					//priority queue
	{
        HuffmanTreeNode* newNode = new HuffmanTreeNode(data[i], freq[i]);
        pq.push(newNode);
    }
 
    HuffmanTreeNode* root = generateTree(pq);			// Generate Huffman Encoding Tree and get the root node

    int arr[MAX_SIZE], top = 0;							// Print Huffman Codes
    printCode(root, arr, top);
}

int main()
{
	int i,size;
	cout<<"Enter no. of entries: ";
    cin>>size;
    char data[size];
    int freq[size];
    cout<<"Enter the data: ";
    for(i=0;i<size;i++)
    {
    	cin>>data[i];
	}
    cout<<"Enter the frequency: ";
    for(i=0;i<size;i++)
    {
    	cin>>freq[i];
	}
	cout<<"\n -----------Output-------------"<<endl;
    HuffmanCode(data, freq, size);

    return 0;
}
