#include "tree_node.h"
#include <vector>
#include <iostream>

class Solution {
public:
    TreeNode *build_tree(std::vector<int> &list, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        auto mid = left + ((right - left) >> 1);
        auto root = new TreeNode(list[mid]);
        root->left = build_tree(list, left, mid - 1);
        root->right = build_tree(list, mid + 1, right);
        return root;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        auto list = std::vector<int>();
        auto cur = head;
        while (cur) {
            list.push_back(cur->val);
            cur = cur->next;
        }
        return build_tree(list, 0, list.size() - 1);
    }
};

int main() {
    int a[] = {-10,-3,0,5,9};
    auto cur_node = new ListNode();
    auto pre_node = cur_node;
    for (int i = 0; i < 5; ++i) {
        cur_node->next = new ListNode(a[i]);
        cur_node = cur_node->next;
    }
    auto root = (new Solution())->sortedListToBST(pre_node->next);
    return 0;
}