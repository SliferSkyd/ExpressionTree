#include<iostream>
#include<vector>
#ifndef LAB2_TREE_H
#define LAB2_TREE_H
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

#endif //LAB2_TREE_H
