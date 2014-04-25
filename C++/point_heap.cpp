#include <stdio.h>
#include <iostream>
#include "point_heap.h"

void PointHeap::insert(Point* p){
  if(pos >= max - 1) double_size();
  ++pos;
  data[pos] = p;
  heapify_down(pos);
}

void PointHeap::heapify_down(int node){
  int p = node;
  int prev = node;
  while(p != 0){
    prev = p;
    p = (p - 1) / 2;

    if(data[p]->dist > data[prev]->dist){
      int t = data[p]->dist;
      int x = data[p]->x;
      int y = data[p]->y;
      data[p]->dist = data[prev]->dist;
      data[p]->x = data[prev]->x;
      data[p]->y = data[prev]->y;
      data[prev]->dist = t;
      data[prev]->x = x;
      data[prev]->y = y;
    }
  }
}

bool PointHeap::decrease(int x, int y, int dist){
  bool b = false;
  for(int i = 0; i < pos + 1; i++){
    if(data[i]->x == x && data[i]->y == y){
      if(dist < data[i]->dist){
        data[i]->dist = dist;
        b = true;
      }
      break;
    }
  }
  for(int i = 0; i < pos + 1; i++)
    heapify_down(i);
  return b;
}

Point* PointHeap::min(){
  if(pos == -1) return NULL;
  return data[0];
}

void PointHeap::pop_min(){
  if(pos < 0) return;

  data[0] = data[pos];
  --pos;

  for(int i = 0; i < pos + 1; i++)
    heapify_down(i);
}

void PointHeap::double_size(){
  if(data == NULL){
    max = 1;
    data = new Point*[max];
    return;
  }

  max *= 2;
  Point** temp = new Point*[max];
  for(int i = 0; i < pos + 1; i++)
    temp[i] = data[i];
  delete []data;

  data = temp;
}
