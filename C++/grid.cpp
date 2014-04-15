#include<iostream>
#include<vector>
#include "grid.h"
using namespace std;


void Grid::drawHorizontalLine(int x1, int y1, int width){
  for(int i = 0 ; i < width ; i ++){
    grid[x1 + i][y1] = 'W';
  }
}

void Grid::drawVerticalLine(int x1, int y1, int height){
  for(int i = 0 ; i < height; i ++){
    grid[x1][y1 + i] = 'W';
  }
}

void Grid::findPath(int x1, int y1, int x2, int y2){
  vector<int> queue;
  vector<int> path;
  vector<int> paths;
  int x, y;

  queue.push_back(x1);
  queue.push_back(y1);
  path.push_back(x1);
  path.push_back(y1);

  while(queue.size()){
    x = queue.front();
    queue.erase(0);
    y = queue.front();
    queue.erase(0);

    // Go right
    if(x + 1 < width)
    path.push_back(x);
    path.push_back(y);
  }

  grid[x1][y1] = 'S';
  grid[x2][y2] = 'E';
}

ostream& operator << (ostream& out, Grid& grid){
  for(int y = 0 ; y < grid.height ; y ++){
    for(int x = 0 ; x < grid.width ; x ++)
      out << grid.grid[x][y] << " ";
    out << endl;
  }
  return out;
}
