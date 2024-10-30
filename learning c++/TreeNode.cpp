#include <iostream>
#include <vector>
#include "Point.h"

// Tree Node class
class TreeNode {
public:
    TreeNode(Point value) : data(value) {}

    void addChild(std::shared_ptr<TreeNode>& child) {
        children.push_back(child);
    }

    const std::vector<std::shared_ptr<TreeNode>>& getChildren() {
        return children;
    }

    const Point& getData() {
        return data;
    }
    // Made the findNode function public
    /*TreeNode* findNode(int value) {
        return findNodeHelper(this, value);
    }*/

private:
    Point data;
    std::vector<std::shared_ptr<TreeNode>> children;

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
    void printTree(const std::shared_ptr<TreeNode>& node) {
        if (!node) return;
        std::cout << "(" << node->getData().getX() << ", " << node->getData().getY() << ")";
        if (!node->getChildren().empty()) {
            std::cout << " -> ";
            printTree(node->getChildren()[0]); // For simplicity, take the first path (DFS order)
        }
    }

    

    // Calling the public findNode function of TreeNode
    /*TreeNode* findNode(int value) {
        return root->findNode(value);
    }*/
};
