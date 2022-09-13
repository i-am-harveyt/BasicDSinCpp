#include <iostream>
#include <vector>

using namespace std;

// declaration of quicksort and helper function, i.e., partition
void quicksort(int l, int r, vector<int> &nums);
void partition(int l, int r, vector<int> &nums);

/*
 * To implement the part of making numbers into "right" region.
 * Pivot will be in the absolutely right position.
 * @param l: left bound
 * @param r: right bound
 * @param nums: The array that is wanted to be sorted
 */
void partition(int l, int r, vector<int> &nums)
{
  // set pivotindex as l
  int pivotindex = l, pivot = nums[l];
  int p = l, q = r;

  // while p and q have not collided
  while (p < q)
  {
    // if they have not meet the one should not belongs left/right.
    while(nums[p] < pivot) p++;
    while(nums[q] > pivot) q--;
    // handle condition
    if (p > q)
      break;
    // make them placed into right position
    swap(nums[p], nums[q]);
    p++, q--; // update index
  }
  // put pivot into right position
  swap(nums[pivotindex], nums[p-1]);

  // divide
  quicksort(l, p - 2, nums);
  quicksort(p, r, nums);
}


/*
 * To handle the flow of quicksort.
 * Pivot will be in the absolutely right position.
 * @param l: left bound
 * @param r: right bound
 * @param nums: The array that is wanted to be sorted
 */
void quicksort(int l, int r, vector<int> &nums)
{
  if (r <= l)
    return;
  partition(l, r, nums);
}

// main function
int main (int argc, char *argv[])
{
  int arr[] = {3, 1, 2, 6, 3, 7, 9, 4};
  vector<int> vec;
  for (int i = 0 ; i < sizeof(arr)/sizeof(arr[0]); i++)
    vec.push_back(arr[i]);
  
  for (int n : vec)
    cout << n << " ";
  cout << endl;

  quicksort(0, vec.size()-1, vec);

  for (int n : vec)
    cout << n << " ";
  cout << endl;

  return 0;
}
