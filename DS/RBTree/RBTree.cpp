#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// TreeNode class
class TreeNode {
public:
    int val;
    bool red;
    TreeNode *left, *right;
    TreeNode (int value) {
        val = value;
        red = true;
        left = nullptr, right = nullptr;
    }
};

// RB Tree class
class RBTree {
public:
    TreeNode *root;
    RBTree () { root = nullptr; }
    
    /*
     * insert(int val) -> void
     * @param val insert number
     * Insert val into RB Tree
     */
    void insert(int val) {
        if (!root) {
            root = new TreeNode(val);
            root->red = false;
            return;
        }
        vector<TreeNode *> path;
        TreeNode *cur = root;
        // search for place and adjustment
        while (cur) {

            // both children are red-colored
            if (cur->left && cur->left->red &&
                    cur->right && cur->right->red) {
                color_change(cur);
                path.push_back(cur);
                tackle_seq_red(path);
                cur = path.back();
            } else {
                path.push_back(cur);
            }

            // just a binary search part
            if (val < cur->val)
                cur = cur->left;
            else
                cur = cur->right;
        }
        // "really" insert
        cur = path.back();
        if (val < cur->val) {
            cur->left = new TreeNode(val);
            path.push_back(cur->left);
        } else {
            cur->right = new TreeNode(val);
            path.push_back(cur->right);
        }
        // re-check if violate no continuous red node property
        tackle_seq_red(path);
        // root is always black
        root->red = false;
    }

    /*
     * all(void)->void
     * Use level-order traversal to traverse & print all nodes
     */
    void all() {
        queue<TreeNode*> q;
        q.push(root);
        // level order traversal
        while (!q.empty()) {
            int size = q.size();
            TreeNode *cur;
            while (size) {
                cur = q.front();
                q.pop();
                cout << cur->val << ":" << cur->red << " " << endl;
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
                size--;
            }
            cout << endl;
        }
    }
private:
    // Rotations
    void llRotate(TreeNode *gp, TreeNode *p, TreeNode *q) {
        gp->left = p->right;
        p->right = gp;
        gp->red = true;
        p->red = false;
        q->red = true;
    }
    void lrRotate(TreeNode *gp, TreeNode *p, TreeNode *q) {
        p->right = q->left;
        gp->left = q->right;
        q->right = gp;
        q->left = p;
        gp->red = true;
        p->red = true;
        q->red = false;
    }
    void rlRotate(TreeNode *gp, TreeNode *p, TreeNode *q) {
        p->left = q->right;
        gp->right = q->left;
        q->left = gp;
        q->right = p;
        gp->red = true;
        p->red = true;
        q->red = false;
    }
    void rrRotate(TreeNode *gp, TreeNode *p, TreeNode *q) {
        gp->right = p->left;
        p->left = gp;
        gp->red = true;
        p->red = false;
        q->red = true;
    }

    /*
     * color_change(TreeNode *x)->void
     * Set X's two children black, and red itself
     */
    void color_change(TreeNode *x) {
        x->left->red = false;
        x->right->red = false;
        x->red = true;
    }

    /*
     * tackle_seq_red(vector<TreeNode *> &path)->void
     * Check if there're continuous red node in path.
     * If yes, adjust them.
     */
    void tackle_seq_red(vector<TreeNode *> &path) {
        cout << "tackle" << endl;
        if (path.size() < 3)
            return;

        int size = path.size();
        TreeNode *q = path[size-1];
        TreeNode *p = path[size-2];
        TreeNode *gp = path[size-3];

        if (!(q->red && p->red)) 
            // if not all red
            return;

        cout << "Rotation" << endl;

        // if is needed to adjust.
        path.pop_back();
        path.pop_back();
        path.pop_back();

        // to detect rotation type
        bool l1 = false, l2 = false;
        if (p == gp->left)
            l1 = true;
        if (q == p->left)
            l2 = true;

        TreeNode *ggp;
        if (path.size() > 0)
            ggp = path.back();
        else
            ggp = nullptr;

        // rotation
        if (l1 && l2) {
            llRotate(gp, p, q);
            path.push_back(p);
        } else if (l1 && !l2) {
            lrRotate(gp, p, q);
            path.push_back(q);
        } else if (!l1 && l2) {
            rlRotate(gp, p, q);
            path.push_back(q);
        } else {
            rrRotate(gp, p, q);
            path.push_back(p);
        }

        // upate grandgrandparent's child
        if (!ggp) {
            root = path.back();
        } else {
            if (gp == ggp->left)
                ggp->left = path.back();
            else
                ggp->right = path.back();
        }
    }
};

int main(void) {
    RBTree rbt = RBTree();
    int seq[] = {3, 1, 2, 9, 6, 7, 4, 5, 8, 10};
    int size = sizeof(seq)/sizeof(seq[0]);
    for (int i = 0 ; i < size ; i++)
        rbt.insert(seq[i]);
    rbt.all();
    return 0;
}
