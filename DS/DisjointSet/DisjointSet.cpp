#include <iostream>
#include <vector>

class DisjointSet {
public:
  std::vector<int> data;

  // constructor
  DisjointSet(int size) { data = std::vector<int>(size, -1); }

  // methods
  void Union_By_Size(int i, int j) {
    int p1 = Find(i), p2 = Find(j); // get root of two nodes
    if (p1 == p2) // if they share same root, nothing to do with
      return;
    if (data[p1] >= data[p2]) {
      data[p1] += data[p2]; // append size
      data[p2] = p1;        // update parent
    } else {
      data[p2] += data[p1];
      data[p1] = p2;
    }
  }
  int Find(int x) {
    if (data[x] < 0)
      return x;
    data[x] = Find(data[x]); // update parent as root, path compression
    return data[x];
  }
};
