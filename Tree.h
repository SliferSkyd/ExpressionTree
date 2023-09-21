#include<iostream>
#include<vector>
#ifndef _TREE_H
#define _TREE_H
int count = 0;
class Tree{
public:
    int id;
    std::string node;
    std::vector<Tree> children;

    Tree(std::string node){
        this->node = node;
        this->id = count++;
    }
    Tree(std::string node, std::vector<Tree> children){
        this->node = node;
        this->id = count++;
        this->children = children;
    }
};

#endif //_TREE_H
