class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph){


         int COUNT =graph.size( );

        if (COUNT ==1) 
        
    return 0;              

        int ALLmask =(1 << COUNT) -1;     

       
        vector<vector<int>> DST(COUNT, vector<int>(1 <<COUNT,-1) ) ; //this DST finds the shortest distance to reack the mask

        queue<pair<int,int>> QUE ;

        
        for(int i =0; i<COUNT;++i) {

            int CurrM =1 <<i;

            DST[i][CurrM] =0;

            QUE.push({i, CurrM});
        }

        while (!QUE.empty()) {//keeps going until the que is empty


            auto [CurrN,CurrM] =QUE.front( );

            QUE.pop() ;

            int CurrD =DST[CurrN][CurrM] ;


            for(int NXT:graph[CurrN]) {//checks all of the neiboring nodes

                int nxtM =CurrM |(1<<NXT);   


                if (DST[NXT][nxtM]!=-1) 

            continue ;  

                DST[NXT][nxtM] =CurrD +1 ;

                if (nxtM ==ALLmask)     

            return CurrD +1;


                QUE.push({NXT,nxtM}) ;

            }
        }




    return -1 ;
    }



};