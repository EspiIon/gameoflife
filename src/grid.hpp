#pragma once;
#include <vector>

class Grid{
    public:
        Grid(int width, int height,int cellSize)
        : rows(height/cellSize), collumns(width/cellSize), cellSize(cellSize), cells(rows,std::vector<int>(collumns,0)),adjacent(rows,std::vector<int>(collumns,0)){};
        void draw();
        void setvalue(int row,int collumn, int value);
        void DieOrLive();
        void count();
        void resetcount();
        void placecell();
    private:
        int rows;
        int collumns;
        int cellSize;
        std::vector<std::vector<int>> cells;
        std::vector<std::vector<int>> adjacent;
        int addcount(int collumn,int row);
};        
