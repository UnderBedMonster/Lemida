#include <iostream>
#include <vector>
#include "Point.h"

// Tree Node class
class TreeNode {
public:
    Point data;
    std::vector<TreeNode*> children;

    TreeNode(Point value) : data(value) {}

    void addChild(TreeNode* child) {
        children.push_back(child);
    }

    // Made the findNode function public
    /*TreeNode* findNode(int value) {
        return findNodeHelper(this, value);
    }*/

private:
    // Renamed the findNode function to findNodeHelper to make it private
    /*TreeNode* findNodeHelper(TreeNode* node, Point value) {
        if (node->data == value) {
            return node;
        }

        for (TreeNode* child : node->children) {
            TreeNode* found = findNodeHelper(child, value);
            if (found != nullptr) {
                return found;
            }
        }

        return nullptr;
    }*/
};

// Tree class
class Tree {
public:
    TreeNode* root;


    Tree(Point rootValue) {
        root = new TreeNode(rootValue);
    }

    // Recursive function to print the tree
    void printTree(TreeNode* node, int level = 0) {
        std::cout << std::string(level, '\t') << node->data.toString() << std::endl;
        for (TreeNode* child : node->children) {
            printTree(child, level + 1);
        }
    }

    void printTree() {
        printTree(root);
    }

    // Calling the public findNode function of TreeNode
    /*TreeNode* findNode(int value) {
        return root->findNode(value);
    }*/
};
