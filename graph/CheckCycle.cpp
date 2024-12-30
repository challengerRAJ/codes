bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        int n = V;
        // vector<int> ans;
        int count;
        vector<int> indegree(n, 0);
        for(int u=0;u<n;u++)
        {
            for(int v=0;v<adj[u].size();v++)
            {
                indegree[adj[u][v]]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
                count++;
            }
        }
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            // ans.push_back(u);
            for(int v=0;v<adj[u].size();v++)
            {
                indegree[adj[u][v]]--;
                if(indegree[adj[u][v]]==0)
                {
                    q.push(adj[u][v]);
                    count++;
                }
            }
        }
        if(count==n)
            return 0;
        return 1;
}
