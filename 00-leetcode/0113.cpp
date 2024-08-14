#include <vector>
#include <algorithm>
#include "tree_node.h"

class Solution {
public:
    void dfs(
        TreeNode *root, const int &targetSum, 
        int cur_sum, 
        std::vector<int> *const &cur_path,
        std::vector<std::vector<int>> *const &res
    ) {
        if (!root) {
            return;
        }
        cur_sum += root ->val;
        cur_path->push_back(root ->val);

        if (!root ->left && !root ->right && cur_sum == targetSum) {
            res->push_back(*cur_path);
        }
        dfs(root->left, targetSum, cur_sum, cur_path, res);
        dfs(root->right, targetSum, cur_sum, cur_path, res);
        cur_path->pop_back();
    }
    std::vector<std::vector<int>> pathSum(TreeNode *root, int targetSum) {
        auto res = new std::vector<std::vector<int>>();
        auto cur_path = new std::vector<int>();
        dfs(root, targetSum, 0, cur_path, res);
        return *res;
    }
};

int main() {
    
    return 0;
}