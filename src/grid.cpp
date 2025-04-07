#include <raylib.h>
#include "grid.hpp"
#include <iostream>
void Grid::draw()
{
    Color color;
    for(int row = 0; row<rows; ++row)
    {  
        for(int collumn = 0; collumn<collumns;++collumn)
        {
            if (cells[row][collumn]==0)
            {
                color=Color{ 33, 47, 61,255 };
            }
            else{
                color=Color{  176, 58, 46 ,255 };
            }


            DrawRectangle(collumn*cellSize,row*cellSize,cellSize-2,cellSize-2,color);

        }
            
    }
}

void Grid::setvalue(int row, int collumn, int value)
{
    if(row>=0 && row<rows && collumn>=0 && collumn<collumns )
    {

        cells[row][collumn] =value;
    }
}

void Grid::DieOrLive()
{
    for(int row=0;row<rows;row++)
    {
        for(int collumn=0;collumn<collumns;++collumn)
        {
            if(adjacent[row][collumn]>3)
            {
                setvalue(row,collumn,0);
            }
            if(adjacent[row][collumn]<2)
            {
                setvalue(row,collumn,0);

            }
            if(adjacent[row][collumn]==3)
            {
                setvalue(row,collumn,1);
                
            }
        }
    }
}

void Grid::count()
{
    for(int row=0;row<rows;++row)
        {
            for(int collumn=0;collumn<collumns;++collumn)
            {
                for(int i=-1;i<=1;++i)
                    {
                        for(int j=-1;j<=1;++j)
                        {
                            
                            adjacent[row][collumn]+=addcount(row+i,collumn+j);
                        }
                    }
                
                adjacent[row][collumn]-=cells[row][collumn];
            }
    }
}
void Grid::resetcount()
{
    for(int row=0;row<rows;row++)
        {
            for(int collumn=0;collumn<collumns;++collumn)
            {
                adjacent[row][collumn]=0;
            }
        }   
}
void Grid::placecell()
{
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        int x = GetMouseX()/cellSize;
        int y = GetMouseY()/cellSize;
        int value =0;
        if (cells[y][x]==1){
            value=0;
        }
        else{
            value=1;
        }
        setvalue(y,x,value);
    }
}
int Grid::addcount(int row, int collumn)
{
    if(collumn< collumns && collumn >=0 && row<rows && row>=0){
        if(cells[row][collumn]==1)
            {
                return 1;
            }
    }
    return 0;
}