int depth=INT_MIN;
void filterDepthWise(unordered_map<int,vector<int>> &mp,int d,TreeNode* root){
    if(root==NULL) return;
    depth=max(depth,d);
    mp[d].push_back(root->val);
    filterDepthWise(mp,d+1,root->left);
    filterDepthWise(mp,d+1,root->right);
}
int findBottomLeftValue(TreeNode* root) {
    unordered_map<int,vector<int>> mp;
    filterDepthWise(mp,0,root);

    return mp[depth][0];
    
}