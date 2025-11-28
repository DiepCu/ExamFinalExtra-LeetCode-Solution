class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {

          int SIZE = nums.size();//setting up the que with the givens size

        vector<int> MAXsum(SIZE);

        deque<int> DEQUE;

        int Total =INT_MIN;
        
        for (int i =0; i <SIZE;i++) {
            

            while (!DEQUE.empty( ) && i -DEQUE.front( ) >k)//remove elements the dont meet the criteria

                DEQUE.pop_front() ;
            
           
            MAXsum[i] =(DEQUE.empty( ) ? 0:max(0,MAXsum[DEQUE.front()])) +nums[i];

            Total = max(Total, MAXsum[i]);

            
            
            while(!DEQUE.empty( ) &&MAXsum[DEQUE.back()]<=MAXsum[i] ) //makes sure the queue is always decreasing

                DEQUE.pop_back() ;

            
            DEQUE.push_back(i) ;
        }
        

    return Total;



   }
};