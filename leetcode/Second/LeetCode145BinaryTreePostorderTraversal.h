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

#include <vector>

#include <stdio.h>

namespace BinaryTreePostorderTraversal1
{
using std::vector;
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        DoPostorderTraversal(root);
        return output;
    }
    void DoPostorderTraversal(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        output.push_back(root->val);
    }
    vector<int> output;
};

void test()
{
    TreeNode node0(1);
    TreeNode node1(2);
    TreeNode node2(3);
    node0.right = &node1;
    node1.left = &node2;
    Solution obj;
    auto output = obj.postorderTraversal(&node0);
    for (size_t i = 0; i < output.size(); i++)
    {
        printf("%d\t", output[i]);
    }
}
} // namespace BinaryTreePostorderTraversal1

#include <deque>
#include <set>

namespace BinaryTreePostorderTraversal2
{
using std::deque;
using std::set;
using std::vector;
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> output;
        deque<TreeNode *> stack;
        set<TreeNode *> collect;
        if (root != NULL)
        {
            stack.push_back(root);
        }
        while (!stack.empty())
        {
            TreeNode *cur = stack.back();
            if (cur->left != NULL && collect.find(cur) == collect.end())
            {
                stack.push_back(cur->left);
                collect.insert(cur);
            }
            else if (cur->right != NULL && collect.find(cur) == collect.end())
            {
                stack.push_back(cur->right);
                collect.insert(cur);
            }
            else
            {
                output.push_back(cur->val);
                stack.pop_back();
            }
        }
        return output;
    }
};

void test()
{
    TreeNode node0(1);
    TreeNode node1(2);
    TreeNode node2(3);
    node0.right = &node1;
    node1.left = &node2;
    Solution obj;
    auto output = obj.postorderTraversal(NULL);
    for (size_t i = 0; i < output.size(); i++)
    {
        printf("%d\t", output[i]);
    }
}
} // namespace BinaryTreePostorderTraversal2

void BinaryTreePostorderTraversal_test()
{
    // BinaryTreePostorderTraversal1::test();
    BinaryTreePostorderTraversal2::test();
}