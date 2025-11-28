
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
       

          ListNode* CurrN =head ;


        int CNT =0 ;
        
      
        while(CurrN !=nullptr && CNT!=k){ //checks and goas through to make sure we have k amount of nodes


        CNT++;
        CurrN =CurrN->next;
        }
        
        //if the CNT and K are equal reverse the nodes
        if (CNT ==k){

            CurrN =reverseKGroup(CurrN,k) ;
            
            
            while(CNT--> 0){ //reverses all the currennt nodes of K

                ListNode* TMP =head->next;

                head-> next =CurrN ;
                CurrN =head ;
                head =TMP ;
            }
        head = CurrN;

        }
        

    return head;
 }


};