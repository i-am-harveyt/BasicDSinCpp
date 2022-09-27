#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void radixsort(int digit, int arrlen, int *arr)
{
  // init
  int tablelen = 10, base = 1;
  vector<queue<int> > table(tablelen, queue<int>());

  for (int i = 0 ; i < digit ; i++)
  {
    // push into table
    for (int j = 0 ; j < arrlen ; j++)
      table[(arr[j] / base) % tablelen].push(arr[j]);

    // load back to arr
    int idx = 0;
    for (int j = 0 ; j < tablelen ; j++)
    {
      while (!table[j].empty()) // use of Queue's FIFO property
      {
        arr[idx++] = table[j].front();
        table[j].pop();
      }
    }
    base *= tablelen;
  }
}

void print(int arrlen, int arr[])
{
  for (int i = 0 ; i < arrlen ; i++)
    cout << arr[i] << " ";
  cout << "\n";
}

int main (int argc, char *argv[])
{
  // init and calculate len
  int arr[] = {1, 5, 32, 67, 8, 100, 54, 23, 57, 96, 100, 13, 65, 77};
  int arrlen = sizeof(arr) / sizeof(arr[0]);

  print(arrlen, arr);

  radixsort(3, arrlen, arr);

  print(arrlen, arr);

  return 0;
}
