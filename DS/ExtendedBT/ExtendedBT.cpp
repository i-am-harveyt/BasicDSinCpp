#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int val = -1){ 
        data = val;
        left = nullptr, right = nullptr;
    }
};

class BT {
public:
    /*
     * Constructor
     * Init by a vector of int, use bfs method.
     */
    BT(vector<int> &nums) {
        if (nums.size() == 0)
            return;

        queue<Node *> q;
        root = new Node(nums[0]);
        q.push(root), treeSize++;
        // use bfs method to build a binary tree
        int idx = 1, vsize = nums.size();
        while (!q.empty()) {
            int qsize = q.size();
            while (qsize) {
                Node *cur = q.front();
                q.pop(), qsize--;
                if (idx < vsize && nums[idx] != 0) {
                    cur->left = new Node(nums[idx]);
                    q.push(cur->left);
                    treeSize++;
                }
                idx++;
                if (idx < vsize && nums[idx] != 0) {
                    cur->right = new Node(nums[idx]);
                    q.push(cur->right);
                    treeSize++;
                }
                idx++;
            }
        }
    }

    /*
     * size(void)->int
     * Return size of the binary tree
     */
    int size(void) {
        return treeSize;
    }

    /*
     * internalPath(void)->int
     * Calculate internal path and return it
     */
    int internalPath(void) {
        int ret = 0;
        // use bfs method
        queue<Node *> q;
        q.push(root);
        int weight = 0;
        while (!q.empty()) {
            int qsize = q.size();
            while (qsize) {
                Node *cur = q.front();
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
                ret += weight;
                q.pop(), qsize--;
            }
            weight++;
        }
        return ret;
    }

    /*
     * externalPath(void)->int
     * Calculate external path and return it
     */
    int externalPath(void) {
        int ret = 0;
        // use bfs method
        queue<Node *> q;
        q.push(root);
        int weight = 1;
        while (!q.empty()) {
            int qsize = q.size();
            while (qsize) {
                Node *cur = q.front();
                if (cur->left)
                    q.push(cur->left);
                else
                    ret += weight;
                if (cur->right)
                    q.push(cur->right);
                else
                    ret += weight;
                q.pop(), qsize--;
            }
            weight++;
        }
        return ret;
    }

private:
    Node *root;
    int treeSize;
};


int main(void) {
    int arr[] = {1, 2, 3, 4, 0, 0, 0, 0, 5, 0};
    vector<int> nums(arr, arr+sizeof(arr)/sizeof(arr[0]));
    BT bt = BT(nums);
    cout << "Internal Path: " << bt.internalPath() << endl;
    cout << "External Path: " << bt.externalPath() << endl;
    cout << "Complete" << endl;
    return 0;
}
