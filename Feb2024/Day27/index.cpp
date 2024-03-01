int diameter(TreeNode* root,int &d){
        
    if(root==NULL){
        return 0;
    }
    
    int ld=diameter(root->left,d);
    int rd=diameter(root->right,d);
    
    d=max(ld+rd,d);
    
    return max(ld,rd)+1;
}
int diameterOfBinaryTree(TreeNode* root) {
    
    int d=0;
    diameter(root,d);
    return d;
}