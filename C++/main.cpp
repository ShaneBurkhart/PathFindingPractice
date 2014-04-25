#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <climits>
#include "point_heap.h"


int main(){
  const int WIDTH = 50;
  const int HEIGHT = 30;
  const int INIT_X = 0;
  const int INIT_Y = 0;
  const int FINAL_X = 49;
  const int FINAL_Y = 20;

  PointHeap ph;
  char grid[WIDTH][HEIGHT];
  Point* prev[WIDTH][HEIGHT];


  for(int x = 0; x < WIDTH; x++){
    for(int y = 0; y < HEIGHT; y++)
      grid[x][y] = ' ';
  }

  for(int x = 0; x < WIDTH; x++){
    for(int y = 0; y < HEIGHT; y++){
      Point* p = new Point;
      p->x = x;
      p->y = y;
      if(x == INIT_X && y == INIT_Y){
        p->dist = 0;
      }else
        p->dist = SHRT_MAX;
      ph.insert(p);
    }
  }

  Point* p;
  while(ph.min() != NULL){
    p = ph.min();
    ph.pop_min();

    if(p->x == FINAL_X && p->y == FINAL_Y) break;

    grid[p->x][p->y] = '.'; //Visited

    int x = p->x, y = p->y;
    int alt = p->dist + 1;
    if(x + 1 < WIDTH){
      if(ph.decrease(x + 1, y, alt))
        prev[x + 1][y] = p;
    }
    if(x - 1 >= 0){
      if(ph.decrease(x - 1, y, alt))
        prev[x - 1][y] = p;
    }
    if(y + 1 < HEIGHT){
      if(ph.decrease(x, y + 1, alt))
        prev[x][y + 1] = p;
    }
    if(y - 1 >= 0){
      if(ph.decrease(x, y - 1, alt))
        prev[x][y - 1] = p;
    }
    if(x + 1 < WIDTH && y + 1 < HEIGHT){
      if(ph.decrease(x + 1, y + 1, alt))
        prev[x + 1][y + 1] = p;
    }
    if(x + 1 < WIDTH && y - 1 >= 0){
      if(ph.decrease(x + 1, y - 1, alt))
        prev[x + 1][y - 1] = p;
    }
    if(x - 1 >= 0 && y + 1 < HEIGHT){
      if(ph.decrease(x - 1, y + 1, alt))
        prev[x - 1][y + 1] = p;
    }
    if(x - 1 >= 0 && y - 1 >= 0){
      if(ph.decrease(x - 1, y - 1, alt))
        prev[x - 1][y - 1] = p;
    }
  }

  while(p->x != INIT_X || p->y != INIT_Y){
    grid[p->x][p->y] = 'P';
    p = prev[p->x][p->y];
  }

  grid[INIT_X][INIT_Y] = 'S';
  grid[FINAL_X][FINAL_Y] = 'E';

  for(int y = 0; y < HEIGHT; y++){
    for(int x = 0; x < WIDTH; x++)
      printf("%c ", grid[x][y]);
    printf("\n");
  }

  return 0;
}
