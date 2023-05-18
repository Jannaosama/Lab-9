#include<iostream>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode* left, * right;
};
TreeNode* CreateTreeNode(int val)
{
    TreeNode* NewTreeNode = new TreeNode();
    NewTreeNode->val = val;
    NewTreeNode->left = NULL;
    NewTreeNode->right = NULL;
    return (NewTreeNode);
}
bool CheckHeight(TreeNode* root, int* height)
{
    int Lheight = 0;
    int Rheight = 0;
    int l = 0;
    int r = 0;
    if (root == NULL)
    {
        *height = 0;
        return 1;
    }
    l = CheckHeight(root->left, &Lheight);
    r = CheckHeight(root->right, &Rheight);
    *height = max(Lheight, Rheight) + 1;
    if (abs(Lheight - Rheight >= 2))
        return 0;
    else
        return l && r;
}
int main()
{
    int height = 0;
    TreeNode* root = CreateTreeNode(9);
  
        TreeNode* root = CreateTreeNode(9);
        root->right = CreateTreeNode(11);
        root->right = CreateTreeNode(18);
        root->left = CreateTreeNode(9);
        root->left->left = CreateTreeNode(3);
        root->left->left->right = CreateTreeNode(6);
        root->left->right = CreateTreeNode(9);
        root->left = CreateTreeNode(6);
        root->left->right = CreateTreeNode(12);
        root->left->left->right = CreateTreeNode(3);
        root->left->left->right = CreateTreeNode(4);
        root->left->left->left = CreateTreeNode(3);
        root->left->left->left->left = CreateTreeNode(2);
        root->left = CreateTreeNode(3);
        root->left->right = CreateTreeNode(6);
        root->left->right->left = CreateTreeNode(4);
        root->right->right = CreateTreeNode(20);

    if (CheckHeight(root, &height))
        cout << "The tree is balanced";
    else
        cout << "The tree is not balanced";
}



/*
2-	Create a balanced binary search tree from the following numbers, draw it and mention its height, root, and leaf nodes.
[9,11,18,3,6,12,3,4,2,20]*/