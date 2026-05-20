#include <iostream>
//作业的要求实际上是bst

struct TreeNode {
    char data;
    TreeNode *left, *right;
    TreeNode(char x) : data(x), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, char val){
    if (root == nullptr){
        return new TreeNode(val);
    }
    if (val < root->data){
        root->left = insert(root->left, val);
    } else if (val > root->data){
        root->right = insert(root->right, val);
    }
    return root;
}

TreeNode* buildBST() {
    TreeNode* root = nullptr;
    char ch;
    std::cout<<"Enter characters to build BST (enter '#' to stop):"<<std::endl;
    while (std::cin>>ch && ch != '#'){
        root = insert(root, ch);
    }
    return root;
}

void inorderTraversal(TreeNode* root){
    if(root == nullptr) return;
    inorderTraversal(root->left);
    std::cout<<root->data<<" ";
    inorderTraversal(root->right);
}

int leavesCounter(TreeNode* root){
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) return 1;
    return leavesCounter(root->left) + leavesCounter(root->right);
}

int main(){
    TreeNode* root = buildBST();

    std::cout << "Inorder traversal result: ";
    inorderTraversal(root);
    std::cout<<std::endl;

    int leafCount = leavesCounter(root);
    std::cout << "Number of leaf nodes: "<<leafCount<<std::endl;

    return 0;
}
