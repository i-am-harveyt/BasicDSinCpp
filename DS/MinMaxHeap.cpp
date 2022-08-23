#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class MinMaxHeap {
private:
    vector<int> data; 
    /* 
     * Since our starging index is 0, 
     * our parent index is (curIndex-1)/2
     * out grandparent index is ((curIndex-1)/2-1)/2.
     * Also, layer is log2(curIndex+1), root is in layer 0
     */

public:
    // constructors
    MinMaxHeap(void) { data = vector<int>(0); }
    MinMaxHeap(vector<int> &init) { data = vector<int>(init); }

    /*
     * getMax(void)-> Max of the MinMaxHeap.
     */
    int getMax(void) {
        if (data.size() > 2) {
            if (data.size() > 3 && data[2] > data[1])
                return data[2];
            return data[1];
        }
        return data[0];
    }

    /*
     * getMin(void)->Min of the MinMaxHeap.
     */
    int getMin(void) {
        if (data.size())
            return data[0];
        return 0;
    }

    /*
     * getLayer(int curIndex)->(int)layer
     * Since we started from index 0, our layer is log2(curIndex+1)
     */
    int getLayer(int x) {
        return (int)log2(x + 1);
    }

    /*
     * getParent(int curIndex)->(int)parentIndex
     * Since we started from index 0, our parentIndex is (x-1)/2
     */
    int getParent(int x) {
        return (x - 1) / 2;
    }

    /*
     * verifyMin(int curIndex)->void
     * A function that mantain the Min heap part.
     */
    void verifyMin(int cur) {
        int layer = getLayer(cur);
        if (layer == 0) // if it is already in root layer
            return;
        // else, challenge with it's grandparent
        int gp = getParent(getParent(cur));
        if (data[cur] >= data[gp])
            return;
        swap(data[cur], data[gp]);
        verifyMin(gp);
    }

    /*
     * verifyMax(int curIndex)->void
     * A function that mantain the Max heap part.
     */
    void verifyMax(int cur) {
        int layer = getLayer(cur);
        if (layer == 1) // already in highest max layer
            return;
        // else, challenge with it's grandparent
        int gp = getParent(getParent(cur));
        if (data[cur] <= data[gp])
            return;
        swap(data[cur], data[gp]);
        verifyMax(gp);
    }

    /*
     * insert(int num)->void
     * Insert x into MinMaxHeap;
     */
    void insert(int x) {
        data.push_back(x);
        int cur = data.size() - 1;
        int parent = getParent(cur);
        if (getLayer(parent) % 2 == 0) { // parent is in Min level
            if (x < data[parent]) {
                swap(data[cur], data[parent]);
                verifyMin(parent);
                return;
            }
            verifyMax(cur);
        } else { // parent is in Max level
            if (x > data[parent]) {
                swap(data[cur], data[parent]);
                verifyMax(parent);
                return;
            }
            verifyMin(cur);
        }
    }

    /*
     * DelMin(int rootIndex)->void
     * Delete Minimum data from MinMaxHeap
     */
    void DelMin(int root) {
    }

    void all(void) {
        for (int i = 0 ; i < data.size() ; i++)
            cout << data[i] << " ";
        cout << endl;
    }
};


int main(void) {
    vector<int> init;
    int list[] = {7, 12, 15, 9, 8};
    for (int i = 0 ; i < sizeof(list)/sizeof(int); i++)
        init.push_back(list[i]);
    MinMaxHeap h = MinMaxHeap(init);
    cout << "Before: ";
    h.all();
    h.insert(6);
    h.insert(18);
    h.insert(20);
    h.insert(5);
    h.insert(3);
    h.insert(40);
    cout << "After: ";
    h.all();
    return 0;
}
