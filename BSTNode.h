#ifndef BST_BSTNODE_H
#define BST_BSTNODE_H


class BSTNode {
public:
    int key; 	    // can be called value or data too
    BSTNode *left;  // left child of the current TreeNode
    BSTNode *right; // right child of the current TreeNode

    BSTNode (int val, BSTNode *left=nullptr, BSTNode *right=nullptr){
        this->key = val;
        this->left = left;
        this->right = right;
    }
};

#endif //BST_BSTNODE_H