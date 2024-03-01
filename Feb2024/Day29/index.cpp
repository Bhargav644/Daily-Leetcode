bool helper(TreeNode* root,unordered_map<int,vector<int>> &mp,int level){
        if(root==NULL) return true;
        if((level%2==0 && root->val%2!=1) || (level%2==1 && root->val%2!=0)) return false;
        if(mp[level].size()>0){
            if((level%2==0 && mp[level].back()>=root->val) || (level%2==1 && mp[level].back()<=root->val)) return false;
        }
      
        mp[level].push_back(root->val);
        return helper(root->left,mp,level+1) and helper(root->right,mp,level+1);
}

bool isEvenOddTree(TreeNode* root) {
    unordered_map<int,vector<int>> mp;
    return helper(root,mp,0);
}