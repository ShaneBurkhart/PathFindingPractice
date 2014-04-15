#include<iostream>
#include "grid.h"
using namespace std;

int main(){

  Grid g(50, 30);

  g.drawHorizontalLine(20, 20, 9);
  g.drawHorizontalLine(20, 10, 9);
  g.drawVerticalLine(20, 10, 10);

  g.findPath(5, 5, 40, 25);

  cout << g;

  return 0;
}
