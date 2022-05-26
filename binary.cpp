#include "shared.h"
//sorts the program for the levelorder mode first root then left node right node
void levelorder(node_t *nodePtr, string fileName, int height)
{
	int j=0;
	if(nodePtr)
	{
			print(nodePtr, fileName);
				levelorder(nodePtr->leftNode, fileName, height);
				levelorder(nodePtr->rightNode, fileName, height);
	}
}
//sorts the program for the preorder mode 
void preorder(node_t *nodePtr, string fileName)
{
	if(nodePtr)
	{
		print(nodePtr, fileName);
		preorder(nodePtr->leftNode, fileName);
		preorder(nodePtr->rightNode, fileName);
	}
}

//sorts the program for the inorder mode
void inorder(node_t *nodePtr, string fileName)
{
	if(nodePtr)
	{
		inorder(nodePtr->leftNode, fileName);
		print(nodePtr, fileName);
		inorder(nodePtr->rightNode, fileName);
	}
}

//this prints to the file how you like letter then all words that go with that letter
void print(node_t *nodePtr, string fileName)
{
	string line;
	for(int i=0;i<nodePtr->level; i++)
	line.append(" ");

	line+= nodePtr-> data;
	line.append(": ");

	for(int i=((nodePtr->midNode.size())-1); i>=0; i--)
	{
		line.append(nodePtr->midNode[i]);
		line.append(" ");
	}
	line.append("\n");
	
	ofstream outFile;
	outFile.open(fileName.c_str(), ios_base::app);
	outFile << line;
	outFile.close();
}

