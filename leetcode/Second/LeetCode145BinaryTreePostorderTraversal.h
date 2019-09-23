// 给定一个二叉树，返回它的 后序 遍历。
// 示例:
// 输入: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3
// 输出: [3,2,1]
// 进阶: 递归算法很简单，你可以通过迭代算法完成吗？

#include <algorithm>
#include <deque>
#include <set>
#include <vector>

#include <stdio.h>

#include "../../common/binary_tree.h"

namespace BinaryTreePostorderTraversal1
{
using std::vector;
class Solution
{
public:
    vector<int> postorderTraversal(struct TreeNode *root)
    {
        rec_postorder(root);
        return output;
    }
    void rec_postorder(struct TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        rec_postorder(root->left);
        rec_postorder(root->right);
        output.push_back(root->val);
    }
    vector<int> output;
};

void test()
{
    int arr[] = {1, -1, 2, 3};
    int flag[] = {1, 0, 1, 1};
    Binary_Tree obj_tree(arr, flag, sizeof(arr) / sizeof(arr[0]));
    auto output = Solution().postorderTraversal(obj_tree.get_root());
    for (size_t i = 0; i < output.size(); i++)
    {
        printf("%d\t", output[i]);
    }
}
} // namespace BinaryTreePostorderTraversal1

namespace BinaryTreePostorderTraversal2
{
using std::copy;
using std::deque;
using std::set;
using std::vector;

class Solution
{
public:
    vector<int> postorderTraversal(struct TreeNode *root)
    {
        deque<int> trav_temp;
        deque<struct TreeNode *> trav_stack;
        set<struct TreeNode *> trav_set;
        if (root != NULL)
        {
            trav_stack.push_back(root);
        }
        while (!trav_stack.empty())
        {
            struct TreeNode *cur = trav_stack.back();
            trav_stack.pop_back();
            trav_temp.push_front(cur->val);
            if (cur->left != NULL)
            {
                trav_stack.push_back(cur->left);
            }
            if (cur->right != NULL)
            {
                trav_stack.push_back(cur->right);
            }
        }
        vector<int> trav_output;
        copy(trav_temp.begin(), trav_temp.end(), back_inserter(trav_output));
        return trav_output;
    }
};

void test()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int flag[] = {1, 1, 1, 1, 1, 1};
    Binary_Tree obj_tree(arr, sizeof(arr) / sizeof(arr[0]));
    struct TreeNode *root = obj_tree.get_root();

    // 测试
    auto output = Solution().postorderTraversal(root);
    for (size_t i = 0; i < output.size(); i++)
    {
        printf("%d\t", output[i]);
    }
}
} // namespace BinaryTreePostorderTraversal2

#include <stack>

namespace BinaryTreePostorderTraversal3
{
using std::copy;
using std::set;
using std::stack;
using std::vector;

class Solution
{
public:
    vector<int> postorderTraversal(struct TreeNode *root)
    {
#define LEFT 0x01
#define RIGHT 0x02
        stack<struct TreeNode *> trav_stack;
        vector<int> trav_output;
        if (root != NULL)
        {
            trav_stack.push(root);
        }
        set<struct TreeNode *> trav_set;
        while (trav_stack.empty() == false)
        {
            struct TreeNode *cur = trav_stack.top();
            int trav_found = 0x00;
            trav_found = trav_set.find(cur->left) != trav_set.end() ? trav_found | LEFT : trav_found;
            trav_found = trav_set.find(cur->right) != trav_set.end() ? trav_found | RIGHT : trav_found;
            if (cur->left != NULL && (trav_found & LEFT) != LEFT)
            {
                trav_stack.push(cur->left);
                continue;
            }
            if (cur->right != NULL && (trav_found & RIGHT) != RIGHT)
            {
                trav_stack.push(cur->right);
                continue;
            }
            if ((cur->left == NULL || (trav_found & LEFT) == LEFT) &&
                (cur->right == NULL || (trav_found & RIGHT) == RIGHT))
            {
                trav_output.push_back(cur->val);
                trav_set.insert(cur);
                trav_stack.pop();
            }
        }
        return trav_output;
    }
};

void test()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int flag[] = {1, 1, 1, 1, 1, 1};
    Binary_Tree obj_tree(arr, sizeof(arr) / sizeof(arr[0]));
    struct TreeNode *root = obj_tree.get_root();

    // 测试
    auto output = Solution().postorderTraversal(root);
    for (size_t i = 0; i < output.size(); i++)
    {
        printf("%d\t", output[i]);
    }
}
} // namespace BinaryTreePostorderTraversal3

void BinaryTreePostorderTraversal_test()
{
    BinaryTreePostorderTraversal1::test();
    BinaryTreePostorderTraversal2::test();
    BinaryTreePostorderTraversal3::test();
}
