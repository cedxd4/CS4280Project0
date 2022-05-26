//this is the basics for adding nodes to the trees
#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>

struct node_t
{
        char data;
        struct node_t *leftNode;
        struct node_t *rightNode;
        std::vector<std::string> midNode;
        int level;
};

#endif

