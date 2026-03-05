
https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int V = adj.size();
        vector<int> bfsResult;
        vector<bool> visited(V, false);
        queue<int> q;
        
        //start bfs from node 0
        q.push(0);
        visited[0] = true;
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            bfsResult.push_back(front);
            
            for(auto neighbour : adj[front]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
        return bfsResult;
    }
};


https://leetcode.com/problems/number-of-provinces/

class Solution {
public:
    void dfs(int city, vector<vector<int>>& isConnected, vector<bool> &isVisited){
        //Mark the curr city as visited
        isVisited[city] = true;

        for(int neighbourCity = 0; neighbourCity < isConnected.size(); neighbourCity++){
            if(isConnected[city][neighbourCity] == 1 && !isVisited[neighbourCity]){
                dfs(neighbourCity, isConnected, isVisited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> isVisited(n, false);
        int provinceCount = 0;

        //Loop over all the cities
        for(int i = 0; i < n;i++){
            if(!isVisited[i]){
                dfs(i, isConnected, isVisited);
                provinceCount++;
            }
        }
        return provinceCount;
    }
};




https://leetcode.com/problems/flood-fill/

class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& image, int originalColor, int newColor){
        int n = image.size();
        int m = image[0].size();

        if(r < 0 || r >= n || c < 0 || c >= m) return;
        if(image[r][c] != originalColor) return;
        image[r][c] = newColor;
        //top
        dfs(r-1, c, image, originalColor, newColor);
        //bottom
        dfs(r+1, c, image, originalColor, newColor);
        //left
        dfs(r, c-1, image, originalColor, newColor);
        //right
        dfs(r, c+1, image, originalColor, newColor);



    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];

        if(originalColor == color) return image;

        dfs(sr, sc, image, originalColor, color);

        return image;
    }
};



https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
class Solution {
  public:
    bool bfs(int start, vector<vector<int>> &adj, vector<bool> &visited){
        queue<int> q;
        unordered_map<int, int> parent;
        
        visited[start] = true;
        q.push(start);
        parent[start] = -1;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int neighbour : adj[node]){
                if(!visited[neighbour]){
                    visited[neighbour] = true;
                    q.push(neighbour);
                    parent[neighbour] = node; //set parent of neighbour
                }
                else if(parent[node] != neighbour) return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto &i : edges){
            int u = i[0];
            int v = i[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(V, false);
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                if(bfs(i, adj, visited)){
                    return true;
                }
            }
        }
        return false;
    }
};



https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
class Solution {
  public:
  
  bool dfs(int node, vector<vector<int>> &adj,vector<bool> &visited,
  unordered_map<int,int>& parent){
      visited[node] = true;
      
      for(int neighbour : adj[node]){
          if(!visited[neighbour]){
            parent[neighbour] = node;
            if(dfs(neighbour, adj, visited, parent)) return true;
            
          }
          else if(parent[node] != neighbour) return true;

      }
      return false;
  }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
         vector<vector<int>> adj(V);
        for(auto &i : edges){
            int u = i[0];
            int v = i[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(V, false);
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                unordered_map<int,int> parent;
                parent[i] = -1;
                if(dfs(i, adj, visited, parent)){
                    return true;
                }
            }
        }
        return false;
    }
};




https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

class Solution {
  public:
  
    bool dfs(int node, vector<vector<int>>& adj, vector<bool> &visited, vector<bool> &rec){
        visited[node] = true;
        rec[node]= true;
        
        for(int neighbour : adj[node]){
            if(!visited[neighbour]){
                if(dfs(neighbour, adj, visited, rec)){
                    return true;
                }
 
            }
            else if(rec[neighbour]){
                    return true;
            }
        }
        rec[node] = false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        
        for(auto &i : edges){
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            
        }
        
        vector<bool> visited(V, false);
        vector<bool> rec(V, false);
        for(int i = 0 ; i< V; i++){
            if(!visited[i]){
                if(dfs(i, adj, visited, rec)){
                    return true;
                }
            }
        }
        return false;
    }
};




https://www.geeksforgeeks.org/problems/topological-sort/1

class Solution {
  public:
    void dfs(int node, vector<vector<int>> &adj,
    vector<bool> &visited,stack<int>& st){
        visited[node] = true;
        
        for(auto neighbour : adj[node]){
            if(!visited[neighbour]){
                dfs(neighbour, adj, visited, st);
            }
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto &i : edges){
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
        }
        
        vector<bool> visited(V, false);
        stack<int> st;
        
        //call dfs for all unvisted nodes
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                dfs(i, adj, visited, st);
            }
        }
        vector<int> result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        
        return result;
        
        
    }
};




https://www.geeksforgeeks.org/problems/topological-sort/1
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        //Compute indegree of every node
        
        //push all the nodes with indegree = 0 in the queue
        //Remove nodes one by one from queue, and add them to your answer
        //for each removed node, decrease the indegree of its neighbours by 1
        //if any neighbour becomes indegree == 0, push that in queue 
        
        //number of visited nodes != number of vertices ->cycle exist
        vector<vector<int>> adj(V);
        for(auto &i : edges){
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
        }
        
        //create indegree vector
        vector<int> indegree(V, 0);
        for(int i = 0; i < V; i++){
            for(auto j : adj[i]){
                indegree[j]++;
            }
        }
        
        //push all vertices with indegree 0 in the queue
        queue<int> q;
        for(int i =0;i<V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> result;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            result.push_back(node);
            
            for(auto neighbour : adj[node]){
                indegree[neighbour]--;
                
                if(indegree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }
        
        if(result.size() != V){
            return {};
        }
        
        return result;
        
        
        
    }
};


https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    void dfs(int row, int col, vector<vector<char>> &grid){
        int m = grid.size();
        int n = grid[0].size();

        //row/col out of bound
        //if curr cell is water -> 0
        if(row < 0 || col < 0 || row >= m || col >= n || grid[row][col] == '0'){
            return;
        }
        //otherwise mark current cell as visited by setting it to '0'
        //it avoids revisiting again
        grid[row][col] = '0';

        dfs(row-1, col, grid);
        dfs(row+1, col, grid);
        dfs(row, col - 1, grid);
        dfs(row, col + 1, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int isLandCount = 0;

        for(int i = 0; i < m ;i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    dfs(i, j, grid);
                    isLandCount++;
                }
            }
        }
        return isLandCount;

    }
};




https://www.geeksforgeeks.org/problems/prerequisite-tasks/1

class Solution {
  public:
  bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int> &rec){
      visited[node] = 1;
      rec[node] = 1;
      
      for(auto neighbour : adj[node]){
          if(!visited[neighbour]){
              if(dfs(neighbour, adj, visited, rec)){
                  return true;
              }
          }
          else if(rec[neighbour]){
              return true;
          }
      }
      rec[node] = 0;
      return false;
  }
    bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
        // Code here
        vector<vector<int>> adj(N);
        
        for(auto &i : prerequisites){
            int u = i.first;
            int v = i.second;
            
            adj[v].push_back(u);
        }
        
        vector<int> visited(N, 0);
        vector<int> rec(N, 0);
        
        for(int i = 0; i < N; i++){
            if(!visited[i]){
                if(dfs(i, adj, visited, rec)){
                    return false;
                }
            }
        }
        return true;
    }
};



https://www.geeksforgeeks.org/problems/prerequisite-tasks/1

class Solution {
  public:
    bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
        // Code here
        vector<vector<int>> adj(N);
        
        for(auto &i : prerequisites){
            int u = i.first;
            int v = i.second;
            
            adj[v].push_back(u);
        }
        
        vector<int> indegree(N, 0);
        for(int i = 0; i < N; i++){
            for(auto neighbour : adj[i]){
                indegree[neighbour]++;
            }
        }
        
        queue<int> q;
        
        for(int i = 0; i < N; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        int count = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            count++;
            
            for(auto& neighbour : adj[node]){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }
        if(count == N) return true;
        
        return false;
    }
};




https://www.naukri.com/code360/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTabValue=PROBLEM


#include<unordered_map>
#include<list>
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here
	unordered_map<int, list<int>> adj;
	for(int i = 0; i < edges.size(); i++){
		int u = edges[i].first;
		int v = edges[i].second;

		adj[u].push_back(v);
		adj[v].push_back(u);

	}
	unordered_map<int, bool> visited;
	unordered_map<int, int> parent;
	queue<int> q;

	q.push(s);
	parent[s] = -1;
	visited[s] = true;

	while(!q.empty()){
		int front = q.front();
		q.pop();

		for(auto i : adj[front]){
			if(!visited[i]){
				visited[i] = true;
				parent[i] = front;
				q.push(i);
			}
		}

	}
	vector<int> ans;
	int currNode = t;
	ans.push_back(t);

	while(currNode != s){
		currNode = parent[currNode];
		ans.push_back(currNode);
	}
	reverse(ans.begin(), ans.end());

	return ans;


}




https://www.naukri.com/code360/problems/shortest-path-in-dag_8381897?leftPanelTabValue=PROBLEM

void dfs(int node, vector<vector<pair<int,int>>> &adj, vector<int> &visited,stack<int> &st){
    visited[node] = 1;

    for(auto &i : adj[node]){
        int neighbour = i.first;
        if(!visited[neighbour]){
            dfs(neighbour, adj, visited, st);
        }
    }
    //after visited all neighbours, push current node into stack(from here i cannot go furthur to any neighbour)
    st.push(node);

}

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<pair<int,int>>> adj(n);

    for(int i = 0; i < m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adj[u].push_back({v,w});

    }
    vector<int> visited(n, 0);
    stack<int> st;

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i, adj, visited, st);
        }
    }

    vector<int> dist(n, INT_MAX);
    dist[0] = 0;

    while(!st.empty()){
        int node = st.top();
        st.pop();

    if(dist[node] != INT_MAX){
        for(auto &edge: adj[node]){
            int neighbour = edge.first;
            int weight = edge.second;

            if(dist[node] + weight < dist[neighbour]){
                dist[neighbour] = dist[node] + weight;
            }
        }
    }

    }
    for(int i = 0; i < n; i++){
        if(dist[i] == INT_MAX){
            dist[i] = -1;
        }
    }
    return dist;

}










