class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
 vector<vector<int>> GRAPH(n);

        for (auto &EDGE : edges){

            GRAPH[EDGE[0]].push_back(EDGE[1]) ;//adds both directions to the graph by placing the edges

            GRAPH[EDGE[1]].push_back(EDGE[0]) ;
        }

        int Total = INT_MAX;

        for(int Beginning =0; Beginning <n;Beginning++){ //trying to do the BFS for every node

            vector<int> Distance(n,-1),parentN(n,-1) ;

            queue<int> QUE;

            Distance[Beginning] =0;

            QUE.push(Beginning);


            while (!QUE.empty( )){ //goes until the node is empty

                int CurrN =QUE.front();QUE.pop() ;

                for(int NXT:GRAPH[CurrN]){

                    if(Distance[NXT] ==-1) {

                    Distance[NXT] =Distance[CurrN] +1 ;

                    parentN[NXT] =CurrN;

                    QUE.push(NXT);


                    } 
                    else if(parentN[CurrN] !=NXT) {

                    Total =min(Total,Distance[CurrN ]+Distance[NXT] +1) ; //cycle the length f both distances to get the answer

                    }
                }
            }
        }

    return Total ==INT_MAX? -1:Total;


    }
};