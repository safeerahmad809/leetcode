class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int ans=0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            int minn = q.front().second;
            int first,last;
            for(int i=0;i<size;i++){
                long long current_id = q.front().second - minn;
                TreeNode* node = q.front().first;
                q.pop();
                if(i==0) first = current_id; 
                if(i==size-1) last = current_id;
                if(node->left){
                    q.push({node->left,current_id*2+1});
                }
                if(node->right){
                    q.push({node->right,current_id*2+2});
                }
            }
            ans = max(ans, last-first+1);
        }
        return ans;
    }
};
