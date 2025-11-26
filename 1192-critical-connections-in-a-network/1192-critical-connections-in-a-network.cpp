class Solution {

public:

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
vector<vector<int>> GRAPH(n)//starts making the graph
;

        for (auto &Edge : connections){




            GRAPH[Edge[0]].push_back(Edge[1]) ;

            GRAPH[Edge[1]].push_back(Edge[0]) ;
        }

        vector<int> TIMEdisc(n,-1),LowerVAL(n,-1);

        vector<vector<int>>TOTbridges;

        int tem = 0;

        function<void(int,int)> VISIT =[&](int CurrN, int ParentN) {



            TIMEdisc[CurrN] =LowerVAL[CurrN] =tem++; //declares the discovery time while also intializing the lower 

            for (int NXT :GRAPH[CurrN]){

                if (NXT ==ParentN) 
                
            continue;


                if (TIMEdisc[NXT] ==-1){

                    VISIT(NXT, CurrN);

                    LowerVAL[CurrN] =min(LowerVAL[CurrN],LowerVAL[NXT] );//updats the lower value/link whenever the child comes back


                    if (LowerVAL[NXT] > TIMEdisc[CurrN]) TOTbridges.push_back({CurrN,NXT}) ;

                } 
                
                else {


                    LowerVAL[CurrN]=min(LowerVAL[CurrN],TIMEdisc[NXT ]); 


                }
            }
        };


        VISIT(0,-1);



    return TOTbridges ;




    }
};