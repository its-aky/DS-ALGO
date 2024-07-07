// It uses DisjointSet data structure and sorted(according to weight) edges list
//Refer to GFG articles for time complexity analysis
class DisjointSet {
    vector<int> rank, parent, size; 
public: 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // making the adjacency list for sorting according to the weight
        vector<pair<int,pair<int,int>>> adjacency(V);
        
        for(int node=0;node<V;node++){
            
            
            for(auto &it:adj[node]){
                
                int wt=it[1];
                int conn=it[0];
                
                
                adjacency.push_back({wt,{node,conn}});
                
            }
            
        }
        
        sort(adjacency.begin(),adjacency.end());
        
        //choosing edges using greedy approach(intuition)
        int mstWt=0;
        DisjointSet ds(V);
        
        for(auto &it:adjacency){
            
            int wt= it.first;
            int u=it.second.first;
            int v=it.second.second;
            
            if(ds.findUPar(u)!=ds.findUPar(v)){//mst dont have extra edges(not cyclic)
                mstWt+=wt;
                ds.unionBySize(u,v);
            }
        }
        
        return mstWt;
    }
};
