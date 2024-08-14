#include "tree_node.h"
#include <vector>

using namespace std;

class Solution {
public:
    using IntIterator = vector<int>::iterator;

    TreeNode *build_tree(
        IntIterator inBegin, IntIterator inEnd, 
        IntIterator postBegin, IntIterator postEnd, 
        vector<int> &inorder, vector<int> &postorder
    ) {
        if (inBegin == inEnd) {
            return nullptr;
        }
        auto root_val = *(postEnd - 1);
        auto root = new TreeNode(root_val);

        for (auto it = inBegin; it != inEnd; ++it) {
            if (*it == root_val) {
                root->left = build_tree(inBegin, it, postBegin, postBegin + (it - inBegin), inorder, postorder);
                root->right = build_tree(it + 1, inEnd, postBegin + (it - inBegin), postEnd - 1, inorder, postorder);
                break;
            }
        }
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.empty()) {
            return nullptr;
        }
        return build_tree(inorder.begin(), inorder.end(), postorder.begin(), postorder.end(), inorder, postorder);
    }
};

int main() {
    Solution s;
    return 0;
}