class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) { //constructs the and preps the merege


        if (lists.empty( ))

        return nullptr ;

        return mergeKLists(lists, 0,lists.size( ) -1) ;
    }
    
private:

    ListNode* mergeKLists(vector<ListNode*>& lists, int start, int end){// divides the list of linked list startong from first to last

        if(start ==end) 

    return lists[start ] ;



        if(start >end) 

    return nullptr ;
        

        int MIDpoint =start+(end-start)/2 ;

        ListNode* LeftL =mergeKLists(lists,start,MIDpoint);

        ListNode* RightL =mergeKLists(lists,MIDpoint +1,end) ;
        

    return merge(LeftL,RightL);
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2){//merges the too linked list together

        ListNode TEM(0 ) ;

        ListNode* CurrN =&TEM;
        
        while(l1 &&l2){

            if(l1->val <l2->val){

                CurrN->next =l1 ;

                l1 =l1->next ;


            }
            
        else {
                CurrN-> next=l2;

                l2 =l2->next ;
            }
            CurrN=CurrN-> next;
        }
        
        CurrN->next =l1 ?l1:l2 ; //connectes the last reamin node or nodes




    return TEM.next ;



}

};