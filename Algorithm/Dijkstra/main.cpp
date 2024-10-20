#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

#define MAX INT_MAX

using namespace std;

typedef pair<int, int> Edge;

void dijkstra(const vector<vector<Edge>> &graph, char src) {
  cout << "Dijkstra's Algorithm" << endl;
  int cur = src - 'A';
  vector<int> dist = vector<int>(graph.size(), MAX);
  dist[cur] = 0;

  priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
  pq.push({cur, 0});

  while (!pq.empty()) {
    int next = pq.top().first;
    pq.pop();

    for (const Edge &edge : graph[next]) {
      int vertex = edge.first;
      int weight = edge.second;

      if (dist[next] + weight < dist[vertex]) {
        dist[vertex] = dist[next] + weight;
        pq.push({vertex, dist[vertex]});
      }
    }
  }

  for (int i = 0; i < graph.size(); i++)
    cout << "Dist from node " << src << " to node " << char(i + int('A'))
         << " is " << dist[i] << endl;
}

int main(void) {
  vector<vector<Edge>> graph(5);
  graph[0].push_back({1, 5});
  graph[0].push_back({2, 1});
  graph[1].push_back({0, 5});
  graph[1].push_back({2, 6});
  graph[1].push_back({3, 7});
  graph[1].push_back({4, 20});
  graph[2].push_back({0, 1});
  graph[2].push_back({1, 6});
  graph[2].push_back({3, 15});
  graph[3].push_back({1, 7});
  graph[3].push_back({2, 15});
  graph[3].push_back({4, 2});
  graph[4].push_back({1, 20});
  graph[4].push_back({3, 2});
  dijkstra(graph, 'A');
  exit(EXIT_SUCCESS);
}
