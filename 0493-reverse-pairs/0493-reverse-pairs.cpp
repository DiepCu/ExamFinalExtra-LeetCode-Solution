class Solution {
public:
    int reversePairs(vector<int>& nums) { 

    return mergeSort(nums, 0, nums.size() - 1);
    } 
    


private:
    int mergeSort(vector<int>& nums, int left, int right){ //declareing the mergesort and preping the reversal

        if(left >=right ) 
    return 0;
        


        int MIDpoint =left +(right -left)/2 ;

        int TOTAL =mergeSort(nums,left,MIDpoint) +mergeSort(nums, MIDpoint+1, right) ;
        
        
        for(int IdxL=left,IdxR=MIDpoint+1; IdxL<=MIDpoint;IdxL++){ //counts the total amount of reversed pairs

            while (IdxR <=right && nums[IdxL]/ 2.0>nums[IdxR ] ) 

            IdxR++ ;
            TOTAL =TOTAL+IdxR-(MIDpoint+1) ;
        }
        
        
        sort(nums.begin( ) +left,nums.begin( )+right+1);//does a starad merge at the very end
    return TOTAL ;
    }
};