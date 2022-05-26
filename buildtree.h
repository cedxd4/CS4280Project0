//this is to setup the buildtree program
#ifndef BUILDTREE_H
#define BUILDTREE_H

#include "node.h"

class BuildTree
{
private:
void insert(node_t *&, node_t *&);

public:
node_t *root;

BuildTree()
{
root=NULL;
}

void insertNode(char, std::string, int);
int searchTree(char, node_t *, std::string);
};

#endif

