#include <iostream>
#include <array>
#include "Snake.h"
#include "TreeNode.cpp"

using namespace std;

const int width = 5, heigth = 5;

int arr[5][5] = {
    {1,1,1,1,1},
    {1,0,0,0,1},
    {1,1,1,0,1},
    {1,0,0,0,1},
    {1,1,1,1,1}
};

TreeNode makeTree(TreeNode *TN) {

}

Tree makeTreeOfArr(Point start)
{
    bool terminated = false;
    Tree tree(start);
    TreeNode X(start);
    while (!terminated)
    {
        for (size_t i = 0; i < 4; i++)
        {
            int ax = tree.root->data.getX();
            int ay = tree.root->data.getY();

              if (!(ax < 1) && !(arr[ax - 1][ay] == 1))
              {
                  tree.root->addChild(&TreeNode(Point(ax - 1,ay)));
              }
              if (!(ax > width-1) && !(arr[ax + 1][ay] == 1))
              {
                  tree.root->addChild(&TreeNode(Point(ax + 1,ay)));
              }
              if (!(ax < 1) && !(arr[ax][ay - 1] == 1))
              {
                  tree.root->addChild(&TreeNode(Point(ax, ay - 1)));
              }
              if (!(ay > heigth - 1) && !(arr[ax][ay + 1] == 1))
              {
                  tree.root->addChild(&makeTree(tree.root));
              }
        }
        
    }
    return tree;
}
Tree makePath(int arr[width][heigth], Point start, Point end) {

}

int main() {

    Tree tree(Point(5,5));
    //makeTreeOfArr(&arr[5][5], Point(1, 1))

    //tree.printTree();

    
   

    return 0;
}