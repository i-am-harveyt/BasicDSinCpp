#include <iostream>
#include <vector>

using namespace std;

void quicksort(vector<int> &vec, int l, int r)
{
  // if there is only one element or less, do nothing
  if (l >= r)
    return;
  // set pivot as rightest element
  int pivot = vec[r];
  int i = l-1;

  // scan, if there is something smaller, move to pivot's left
  for (int j = l ; j < r ; j++)
    if (vec[j] <= pivot)
      swap(vec[++i], vec[j]);

  // put pivot into absolutly right place
  swap(vec[r], vec[++i]);
  
  // divide and conquer
  quicksort(vec, l, i - 1);
  quicksort(vec, i + 1, r);
}

int main (int argc, char *argv[])
{
  // init
  int arr[] = {2, 8, 7, 1, 3, 5, 6, 4};
  for (int i = 0 ; i < sizeof(arr)/sizeof(arr[0]) ; i++)
    cout << arr[i] << " ";

  // put into vector
  vector<int> vec;
  for (int i = 0 ; i < sizeof(arr) / sizeof(arr[0]) ; i++)
    vec.push_back(arr[i]);

  // sort
  quicksort(vec, 0, vec.size()-1);

  // print all
  for (int i = 0 ; i < sizeof(arr)/sizeof(arr[0]) ; i++)
    cout << vec[i] << " ";
  cout << endl;

  return 0;
}
