#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &r, vector<int> &p, vector<int> &q)
{
  // two pointers
  int i = 0, j = 0;
  while (i < p.size() && j < q.size())
  {
    if (p[i] <= q[j])
      r.push_back(p[i++]);
    else
      r.push_back(q[j++]);
  }

  // put the left element(s) in
  while (i < p.size())
    r.push_back(p[i++]);
  while (j < q.size())
    r.push_back(q[j++]);

}

vector<int> mergeSort(vector<int> &vec, int l, int r)
{
  // init and check condition
  vector<int> ret;
  if (l == r) // if there is only one element
  {
    ret.push_back(vec[l]);
    return ret;
  }

  // divide, recursive call
  int mid = l + (r - l) / 2;
  vector<int> p = mergeSort(vec, l, mid);
  vector<int> q = mergeSort(vec, mid+1, r);
  merge(ret, p, q); // merge them
  return ret;
}

int main (int argc, char *argv[])
{
  // init
  int arr[] = {26, 5, 77, 1, 61, 11, 59, 15, 48, 19};
  vector<int> vec;
  for (int i = 0 ; i < sizeof(arr) / sizeof(arr[0]) ; i++)
  {
    cout << arr[i] << " ";
    vec.push_back(arr[i]);
  }
  cout << endl;

  // sort
  vec = mergeSort(vec, 0, vec.size()-1);

  // print all
  for (int i = 0 ; i < vec.size() ; i++)
    cout << vec[i] << " ";
  cout << endl;

  return 0;
}
