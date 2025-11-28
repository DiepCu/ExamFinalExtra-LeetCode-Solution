class Solution {    
public:
    int maxPathSum(TreeNode* root) {//creates tree with maximum as well as sut up the recursive dfs

         int Total= INT_MIN; 
        dfs(root,Total) ;
        return Total;
    }

private:

    int dfs(TreeNode* CurrN, int &Total){ //Finds the best path down left or right recursively

        if (!CurrN) 
        
    return 0;


        int LeftN  =max(0,dfs(CurrN->left,Total)) ;

        int RightN =max(0,dfs(CurrN->right,Total));

       
        Total =max(Total,CurrN->val+LeftN+RightN) ;

        
    return CurrN->val +max(LeftN,RightN);
    }
};