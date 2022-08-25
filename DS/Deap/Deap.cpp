#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

/*
 * Since our index started from 0
 * Threrefore, 
 * leftchild of i = 2i+1
 * rightchild of i = 2i+2
 * parent of i = (i-1)/2
 */

class Deap {
public: 
    // constructor
    Deap() { data = vector<int>(1, 0); }
    Deap(int len) { data = vector<int>(len+1); }
    Deap(vector<int> &init) {
        data.push_back(-1);
        for (int i = 0 ; i < init.size() ; i++)
            data.push_back(init[i]);
    }

    /*
     * getMin(void)->int
     * Return min element in Deap
     */
    int getMin(void) {
        return data[1];
    }

    /*
     * getMax(void)->int
     * Return max element in Deap
     */
    int getMax(void) {
        return data[2];
    }

    /*
     * getParent(int index)->int
     * Return data[index]'s parent
     */
    int getParent(int idx) {
        return (idx - 1) / 2;
    }

    /*
     * getLeftChild(int index)->int
     * Return data[index]'s left child
     */
    int getLeftChild(int idx) {
        return 2 * idx + 1;
    }
    /*
     * getRightChild(int index)->int
     * Return data[index]'s right child
     */
    int getRightChild(int idx) {
        return 2 * idx + 2;
    }

    /*
     * getLayer(int index)->int
     * Return data[index]'s layer(starts from 1)
     */
    int getLayer(int idx) {
        return log2(idx + 1) + 1;
    }

    /*
     * getRightCorrespond(int index)->int
     * Return data[index]'s correspond in max heap
     */
    int getRightCorrespond(int idx) {
        int layer = getLayer(idx);
        int delegate = idx + pow(2, layer-2);
        if (data.size() > delegate)
            return delegate;
        return getParent(delegate);
    }

    /*
     * getLeftCorrespond(int index)->int
     * Return data[index]'s correspond in min heap
     */
    int getLeftCorrespond(int idx) {
        int layer = getLayer(idx);
        return idx - pow(2, layer-2);
    }

    /*
     * insert(int x)->void
     * To insert x into deap 
     */
    void insert(int x) {
        data.push_back(x);
        int idx = data.size()-1;
        int layer = getLayer(idx);
        // get the rightest in max heap
        int leftist = pow(2, layer-1)-1;
        int bdy = leftist + pow(2, layer-2);

        int crd;
        if (idx < bdy) { // if idx is in min heap
            crd = getRightCorrespond(idx);
            if (x > data[crd]) {
                data[idx] = data[crd];
                insertMaxHeap(crd, x);
            } else {
                insertMinHeap(idx, x);
            }
        } else { // idx is in max heap
            crd = getLeftCorrespond(idx);
            if (x < data[crd]) {
                data[idx] = data[crd];
                insertMinHeap(crd, x);
            } else {
                insertMaxHeap(idx, x);
            }
        }
        
    }

    /*
     * insertMaxHeap(int idx, int x)->void
     * Insert x into Max Heap with index = idx
     */
    void insertMaxHeap(int idx, int x) {
        while (idx > 2) {
            int parent = getParent(idx);
            if (x > data[parent]) {
                data[idx] = data[parent];
                idx = parent;
            } else {
                break;
            }
        }
        data[idx] = x;
    }
    /*
     * insertMinHeap(int idx, int x)->void
     * Insert x into Min Heap with index = idx
     */
    void insertMinHeap(int idx, int x) {
        while (idx > 1) {
            int parent = getParent(idx);
            if (x < data[parent]) {
                data[idx] = data[parent];
                idx = parent;
            } else {
                break;
            }
        }
        data[idx] = x;
    }

    /*
     * deleteMin(void)->void
     * Delete minimum from deap
     */
    void deleteMin(void) {
        int x = data[data.size()-1];
        data.pop_back();
        int size = data.size();
        int idx = 1;
        // to move the space to leaf
        while (idx < size) {
            int l = getLeftChild(idx), r = getRightChild(idx);
            if (r < size && data[r] < data[l]) {
                    data[idx] = data[r];
                    idx = r;
            } else if (l < size)  {
                data[idx] = data[l];
                idx = l;
            } else {
                break;
            }
        }

        // to verify the structure, just like insert
        int layer = getLayer(idx);
        int leftist = pow(2, layer-1)-1;
        int bdy = leftist + pow(2, layer-2);
        if (idx < bdy) {
            int crd = getRightCorrespond(idx);
            if (x > data[crd]) {
                data[idx] = data[crd];
                insertMaxHeap(crd, x);
            } else
                insertMinHeap(idx, x);
        } else {
            int crd = getLeftCorrespond(idx);
            if (x < data[crd]) {
                data[idx] = data[crd];
                insertMinHeap(crd, x);
            } else
                insertMaxHeap(idx, x);
        }
    }

    /*
     * all(void)->void
     * Print all element in data
     */
    void all(void) {
        for (int i = 0 ; i < data.size() ; i++)
            cout << data[i] << " ";
        cout << endl;
    }

private:
    vector<int> data;
};

int main (void) {
    vector<int> init;
    init.push_back(8);
    init.push_back(15);
    init.push_back(10);
    init.push_back(12);
    Deap d = Deap(init);
    cout << "Before: ";
    d.all();

    d.insert(6);
    d.insert(20);
    d.insert(4);
    d.insert(30);
    d.insert(45);
    d.insert(2);
    cout << "After Insertions: ";
    d.all();

    d.deleteMin();
    d.deleteMin();
    d.deleteMin();
    d.deleteMin();
    d.deleteMin();
    d.deleteMin();
    d.deleteMin();
    cout << "After Deletions: ";
    d.all();
    return 0;
}
