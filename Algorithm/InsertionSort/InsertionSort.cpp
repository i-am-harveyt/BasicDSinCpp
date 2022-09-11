#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &vec)
{
  // from second index to the end
  for (int i = 1 ; i < vec.size() ; i++)
  {
    int j = i;
    // swap to front until found where to place
    while (j) // to handle the index condition
    {
      if (vec[j] < vec[j-1]) // if current is smaller, swap
        swap(vec[j], vec[j-1]);
      else
        break;
      j--; // update index
    }
  }
  return;
}

int main(void)
{
  int arr[] = {5, 3, 1, 2, 7, 8, 9, 0, 7};
  vector<int> vec;
  for (int i : arr)
    vec.push_back(i);
  insertionSort(vec);

  cout << "Unsorted: ";
  for (int n : arr)
    cout << n << " ";
  cout << endl;

  cout << "Sorted: ";
  for (int n : vec)
    cout << n << " ";
  cout << endl;

  return 0;
}
