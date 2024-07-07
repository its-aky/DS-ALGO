class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        
        // we need a priority queue(min_heap) with weight,v,parent(u)  and a visited array
        // Here visited will be marked after choosing fron the min heap(greedy intuition)
        // priority_queue<int,vector<int>,greater<int>>;Normal min heap initialisation
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        
        vector<int> visited(V,0);
        
        // initial config
        pq.push({0,{0,-1}});
        int mstWt=0;
        
        while(!pq.empty()){
            
            int wt=pq.top().first;
            
            int v=pq.top().second.first;
            
            int u=pq.top().second.second;
            
            
            
            pq.pop();
            
            if(visited[v]==1)continue;
            
            visited[v]=1;
            
            mstWt+=wt;
            
            for(auto &it:adj[v]){
                if(visited[it[0]]==0)pq.push({it[1],{it[0],v}});
            }
        }
        
        return mstWt;
        
        
        
        
    }
};
