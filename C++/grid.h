#include<iostream>
using namespace std;

class Grid{
  private:
    int width, height;
    char** grid;

  public:
    Grid(int width, int height):width(width),height(height){
      grid = new char*[width];
      for(int x = 0 ; x < width ; x ++){
        grid[x] = new char[height];
        for(int y = 0 ; y < height ; y ++)
          grid[x][y] = '.';
      }
    };

    void drawHorizontalLine(int x1, int y1, int width);
    void drawVerticalLine(int x1, int y1, int height);

    void findPath(int x1, int y1, int x2, int y2);

    friend ostream& operator << (ostream& out, Grid& grid);
};
