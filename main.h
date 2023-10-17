#ifndef UNTITLED_MAIN_H
#define UNTITLED_MAIN_H

#include <iostream>
#include <vector>
#include <map>
#include <ctime>
#include <cstdlib>
#include <fstream>
#define MAX_HEIGHT 200
#define MAX_WIDTH 81

class Graph
{
private:

    std::vector<std::vector<std::pair<int, int>>> all_ver;
    std::vector<std::vector<std::pair<int, int>>> empty_ver;
    std::vector<std::vector<std::pair<int, int>>> without_empty_ver;

    int tree_height = 0;
    int without_empty_count = 0, empty_count = 0;
    int capacity = 2;

public:
    Graph(int, int, int, int, int);
    void write_in_file();
    void create_tables();
    void print(std::vector<std::vector<std::pair<int, int>>>);
};


#endif //UNTITLED_MAIN_H
