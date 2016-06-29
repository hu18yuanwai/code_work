class Tree {
public:
	void findNode(TreeNode* root,int &minVal,int &maxVal){
		if(root==NULL) return;
		if(root->left==NULL && root->right == NULL){
			if(root->val < minVal) minVal = root->val;
			if(root->val > maxVal) maxVal = root->val;
		}
		findNode(root->left,minVal,maxVal);
		findNode(root->right,minVal,maxVal);
	}

	void findPath(TreeNode* root, int num, vector<int> temp,vector<int>&path){
		if(root==NULL) return;
		if(root->left==NULL && root->right==NULL){
			if(num==root->val){
				for(int i=0;i<temp.size();i++)
					path.push_back(temp[i]);
			}
			return;
		}
		temp.push_back(0);
		findPath(root->left,num,temp,path);
		temp[temp.size()-1]=1;
		findPath(root->right,num,temp,path);
	}
    int getDis(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 0;
        int minVal=INT_MAX;
        int maxVal=INT_MIN;
        findNode(root,minVal,maxVal);
        vector<int>temp,minPath,maxPath;
        findPath(root,minVal,temp,minPath);
        findPath(root,maxVal,temp,maxPath);

        int len1=minPath.size(),len2=maxPath.size();
        int samepath=0,i=0;
        while(i<minPath.size() && i<maxPath.size() && minPath[i]==maxPath[i]){
        	samepath++;
        	i++;
        }

        return len1+len2-2*samepath;
    }
};