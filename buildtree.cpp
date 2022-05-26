//I pulled this from an old program of mine I believe it came from geekstogeeks website, but was unable to find again.
#include "buildtree.h"
using namespace std;
//this is used to find the root node and start building the tree
void BuildTree::insertNode(char ch, string str, int index)
{
	node_t *newNode = NULL;
	newNode = new node_t;
	newNode->data=ch;
	newNode->leftNode=newNode->rightNode=NULL;
	newNode->midNode.push_back(str);
	newNode->level=index;

	insert(root, newNode);
}

//this is to insert nodes where they belong
void BuildTree::insert(node_t *&nodePtr, node_t *&newNode)
{
	if(nodePtr==NULL)
	{
		nodePtr=newNode;
	}
	else if(newNode->data < nodePtr->data)
	{
		insert(nodePtr->leftNode, newNode);
	}
	else
	{
		insert(nodePtr->rightNode, newNode);
	}
}

//this is to check the level of the tree and see whats going on
int BuildTree::searchTree(char ch, node_t *root, string word)
{
	node_t *nodePtr=root;
	int index=0;
	
	while(nodePtr)
	{
		if(nodePtr->data==ch)
		{
			nodePtr->midNode.push_back(word);
			return 1;
		}
		else if(ch < nodePtr->data)
		{
			nodePtr= nodePtr->leftNode;
			index++;
		}
		else
		{
			nodePtr = nodePtr->rightNode;
			index++;
		}
	}
	insertNode(ch, word, index);
	return 0;
}

