class Solution {

public:

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
 unordered_map<string, priority_queue<string, vector<string>, greater<string>>> AMap ;
        
    for(auto &TICK :tickets){

           AMap[TICK[0]].push(TICK[1]);
        }
        
        vector<string> PATH ;

    visit("JFK", AMap, PATH) ;
        
        
        reverse(PATH.begin(), PATH.end( ) ) ;
    return PATH;
    }


    
private:

    void visit(const string &u ,

             unordered_map<string,priority_queue<string,vector<string>,greater<string>>>& Amap,

             vector<string> &path){

        auto &Vchoice =Amap[u];
        
        
        while (!Vchoice.empty( ) ){

            string Destination = Vchoice.top();

        Vchoice.pop();       


            visit(Destination,Amap,path) ;     
        }
        
        
        path.push_back(u);



    }
};