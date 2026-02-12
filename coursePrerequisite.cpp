#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isCycle(int curr, vector<bool>&vis, vector<bool>&recPath, vector<vector<int>>& prerequisites){
        vis[curr] = true;
        recPath[curr] = true;

        for(int i = 0; i < prerequisites.size(); i++){
            int v = prerequisites[i][0];
            int u = prerequisites[i][1];

            if(u == curr){
                if(!vis[v]){
                    if(isCycle(v, vis, recPath, prerequisites)){
                        return true;
                    }
                    
                }
                else if(recPath[v]){
                    return true;
                }
            }
        }

        recPath[curr] = false; 
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool>vis(numCourses, false);
        vector<bool>recPath(numCourses, false);

        for(int i = 0; i < numCourses; i++){
            if(!vis[i]){
                if(isCycle(i, vis, recPath, prerequisites)){
                    return false;
                }
            }
        }
        return true;
    }
};

int main(){
    
    return 0;
}