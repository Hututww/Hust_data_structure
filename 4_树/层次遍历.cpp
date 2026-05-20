#include <iostream>
#include <queue>

struct TreeNode {
    char data;
    TreeNode *left, *right;
    TreeNode(char x) : data(x), left(nullptr), right(nullptr){}
};

TreeNode* createTree(){
    char ch;
    std::cin>>ch;
    if (!ch || ch == '#'){
        return nullptr;
    }
    TreeNode *root = new TreeNode(ch);
    root->left = createTree();
    root->right = createTree();
    return root;
}

void levelOrderTraversal(TreeNode* root){
    if (root == nullptr) return;
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()){
        TreeNode* current = q.front();
        q.pop();
        std::cout<<current->data<<" ";
        if(current->left) q.push(current->left);
        if(current->right) q.push(current->right);
    }
}

int main(){
    std::cout<<"Please enter the preorder traversal sequence (use '#' for null nodes):"<<std::endl;
    TreeNode* root = createTree();

    std::cout << "Level order traversal result: ";
    levelOrderTraversal(root);
    std::cout<<std::endl;

    return 0;
}
