#include <iostream>
#include <array>
#include "Snake.h"
#include "TreeNode.cpp"
#include <vector>
#include <memory>

using namespace std;

const int width = 5, heigth = 5;

vector<vector<char>> labyrinth = {
        {' ', ' ', '#', ' ', ' '},
        {'#', ' ', '#', ' ', '#'},
        {' ', ' ', ' ', '#', ' '},
        {'#', '#', ' ', ' ', ' '},
        {' ', ' ', '#', '#', ' '}
};

const int ROW_DIRECTIONS[] = { -1, 1, 0, 0 };
const int COL_DIRECTIONS[] = { 0, 0, -1, 1 };

std::shared_ptr<TreeNode> constructTree(vector<vector<char>>& labyrinth, Point start, Point end) {
    if (start.getX() < 0 ||
        start.getY() < 0 ||
        start.getX() >= labyrinth.size() ||
        start.getY() >= labyrinth[0].size() ||
        labyrinth[start.getX()][start.getY()] == '#' ||
        labyrinth[start.getX()][start.getY()] == '*') {

        return nullptr;
    }
    auto node = std::make_shared<TreeNode>(Point(start.getX(), start.getY()));

    labyrinth[start.getX()][start.getY()] = '*';

    if (start.getX() == end.getX() && start.getY() == end.getY()) {
        return node;
    }

    for (int i = 0; i < 4; ++i) {
        int newX = start.getX() + ROW_DIRECTIONS[i];
        int newY = start.getY() + COL_DIRECTIONS[i];

        // Recursively build the path tree
        auto childNode = constructTree(labyrinth, Point(newX, newY), end);
        if (childNode) {
            node->addChild(childNode);
        }
    }

    return !node->getChildren().empty() || (start.getX() == end.getX() && start.getY() == end.getY()) ? node : nullptr;
}

void printPath(std::shared_ptr<TreeNode> node) {
    if (!node) return;
    std::cout << "(" << node->getData().getX() << ", " << node->getData().getY() << ")";
    if (!node->getChildren().empty()) {
        std::cout << " -> ";
        printPath(node->getChildren()[0]); // For simplicity, take the first path (DFS order)
    }
}

int main() {

    Tree tree(Point(5,5));
    
    auto path = constructTree(labyrinth, Point(0,0), Point(5,5));
    printPath(path);
    
   

    return 0;
}