class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int,int>>> GRAPH(n);

        for(auto &EDGE : edges){// Builds the adjacents edges the subdivides the graph

            int CurrN = EDGE[0];
            int NXT = EDGE[1]; 
            int COST = EDGE[2]+1 ;  

            GRAPH[CurrN].push_back({NXT,COST}) ;

            GRAPH[NXT].push_back({CurrN,COST}) ;

        }

        const long MAX =66666667777777 ;


        vector<long> Distance(n, MAX);

        using StateP =pair<long,int>;

        priority_queue<StateP,vector<StateP>,greater<StateP>>PrioQue;

        Distance[0] =0;

        PrioQue.push({0,0 }) ;


        while (!PrioQue.empty( )){// Mkaes ure the reach is always under the MAX

            auto [DISTANCE, CurrN] =PrioQue.top();PrioQue.pop( );

            if (DISTANCE >Distance[CurrN]) 

        continue;


            for(auto[NXT,COST] :GRAPH[CurrN]){

                long NextD =DISTANCE +COST ;

                if(NextD <Distance[NXT] && NextD <=maxMoves){

                    Distance[NXT] =NextD;

                    PrioQue.push({NextD,NXT});

            }
         }
    }

        long Total =0 ;
     
        for (int i =0; i <n;++i )//counts all of the nodes around that are reachable
            if(Distance[i] <= maxMoves)Total++;

        
        for(auto &EDGE :edges){

            int CurrN =EDGE[0] ; 

            int NXT =EDGE[1];

            int PartP =EDGE[2] ;


            long LeftR =Distance[CurrN] >maxMoves ? 0:maxMoves -Distance[CurrN];

            long RightR =Distance[NXT] >maxMoves ? 0:maxMoves -Distance[NXT] ;

            Total =Total+min<long>(PartP, LeftR+RightR) ;//counts up to the number of total subdivided nodes in part
        }

    return (int) Total;



    }
};