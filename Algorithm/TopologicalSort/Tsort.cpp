#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef unordered_set<int> uset;
typedef unordered_map<int, vector<int>> mp;

stack<int> st;

void tsort(mp &g, uset &visited, int cur) {
  // if visited, do nothing
  if (visited.find(cur) != visited.end())
    return;

  // otherwise insert
  visited.insert(cur);

  // traverse all edges
  for (int i = 0; i < g[cur].size(); i++)
    tsort(g, visited, g[cur][i]);

  st.push(cur);
}

int main(void) {
  mp graph;
  graph[1] = vector<int>({2, 3, 4});
  graph[2] = vector<int>({5});
  graph[3] = vector<int>({5, 6});
  graph[4] = vector<int>({5, 6});
  graph[5] = vector<int>({});
  graph[6] = vector<int>({});

  uset visited;
  tsort(graph, visited, 1);

  while (st.size()) {
    cout << st.top();
    st.pop();
  }
  cout << endl;

  return 0;
}
