#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class SMMH {
public:
    // constructor, since root as no data, I init it's len = len+1
    SMMH (void) { data = vector<int>(1, -1); }
    SMMH (int len) { data = vector<int>(len+1, -1); }
    SMMH (vector<int> &vec) {
        data = vector<int>(vec.size()+1, -1);
        for (int i = 0 ; i < vec.size(); i++)
            data[i+1] = vec[i];
    }

    /*
     * insert(int x)-> void
     * Insert x into SMMH
     */
    void insert(int x) {
        data.push_back(x);
        verify(data.size()-1);
    }

    /*
     * deleteMin(void)-> void
     * Remove minumum from SMMH
     */
    void deleteMin(void) {
        int size = data.size();
        if (size == 1)
            return;
        int x = data[size-1];
        data.pop_back();
        if (size <= 2) {
            data[1] = x;
            return;
        }
        int s = 1, sib = 2;
        while (true) {
            // property1
            if (s % 2) { // s is left child
                sib = s + 1;
                if (x > data[sib]) {
                    swap(data[s], data[sib]);
                    int tmp = s;
                    s = sib;
                    sib = tmp;
                }
            } else { // s is right child
                sib = s - 1;
                if (x < data[sib]) {
                    swap(data[s], data[sib]);
                    int tmp = s;
                    s = sib;
                    sib = tmp;
                }
            }
            int lchild = 2*s+1, siblc = 2*sib+1;
            if (size > lchild) {
                int mm = data[lchild], mmidx = lchild;
                if (data.size() > siblc) {
                    if (data[lchild] < data[siblc]) {
                        mm = data[lchild];
                        mmidx = lchild;
                    } else {
                        mm = data[siblc];
                        mmidx = siblc;
                    }
                }
                if (x < mm) { // where X belongs to
                    data[s] = x;
                    break;
                } else {
                    data[s] = mm;
                    s = mmidx;
                }
            } else { // where X belongs to
                data[s] = x;
                break;
            }
        }
    }

    /*
     * void all(void)-> void
     * Print all element in data
     */
    void all(void) {
        for (int i = 0 ; i < data.size() ; i++)
            cout << data[i] << " ";
        cout << endl;
    }
private:
    vector<int> data;
    /*
     * getParent(int idx)->int
     * Return parent of idx
     */
    int getParent(int idx) {
        return (idx - 1) / 2;
    }
    /*
     * verify(int idx)->void
     * To varify and adjust to valid SMMH when inserting
     */
    void verify(int idx) {
        // property1: left child < right child
        if (idx % 2 == 0) { // if x is a right child
            if (data[idx] < data[idx-1]) {
                swap(data[idx], data[idx-1]);
                idx--;
            }
        }
        int parent = getParent(idx);
        if (parent) { // if parent is not root
            if (parent % 2) { // parent is left child
                int ps = parent + 1;
                if (data[idx] > data[ps]) { 
                // property 3: smaller that grandparent's right child
                    swap(data[idx], data[ps]);
                    verify(ps);
                } else if (data[idx] < data[parent]) { 
                // property 2: larger than grandparent's left child
                    swap(data[idx], data[parent]);
                    verify(parent);
                }
            } else { // parent is right child
                int ps = parent - 1;
                if (data[idx] < data[ps]) { 
                // property 3: smaller that grandparent's right child
                    swap(data[idx], data[ps]);
                    verify(ps);
                } else if (data[idx] > data[parent]) { 
                // property 2: larger than grandparent's left child
                    swap(data[idx], data[parent]);
                    verify(parent);
                }
            }
        }
    }
};

int main(void) {
    vector<int> init(2, -1);
    init[0] = 5, init[1] = 8;

    cout << "Before: ";
    SMMH smmh = SMMH(init);
    smmh.all();

    smmh.insert(10);
    smmh.insert(4);
    smmh.insert(6);
    smmh.insert(3);
    smmh.insert(15);
    smmh.insert(20);
    smmh.insert(2);
    smmh.insert(32);
    cout << "After insertion: ";
    smmh.all();

    smmh.deleteMin();
    smmh.deleteMin();
    cout << "After deletion: ";
    smmh.all();


    return 0;
}
