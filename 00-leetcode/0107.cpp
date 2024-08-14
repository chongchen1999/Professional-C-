#include "tree_node.h"
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void traverse(TreeNode *root, int depth, vector<vector<int>> *res) {
        if (!root) {
            return;
        }
        if (res->size() == depth) {
            res->push_back({});
        }
        res->at(depth).push_back(root->val);
        traverse(root->left, depth + 1, res);
        traverse(root->right, depth + 1, res);
    }
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> res;
        traverse(root, 0, &res);
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    return 0;
}