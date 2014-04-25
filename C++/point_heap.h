typedef struct Point{
  int x, y, dist;
} Point;


class PointHeap{
public:
  PointHeap():pos(-1), max(0){
    data = NULL;
  }

  void insert(Point* p);
  Point* min();
  void pop_min();
  bool decrease(int x, int y, int dist);

private:
  int pos, max;
  Point** data;

  void double_size();
  void heapify_down(int node);
};
