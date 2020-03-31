#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;
int V, E;

// topological sorting algorithm using BFS
bool topological_sort(vector<vector<int>>& graph, vector<int>& result){
	// count the indegrees of all the nodes
	// push all the nodes with 0-indegrees into the queue
	// take those nodes out of the queue,
	// as we do that, remove those nodes' edges to the other nodes
	// if there is any node with 0 indegree, push that node onto the queue

	vector<int> indegrees(V+1, 0);
	priority_queue<int, vector<int>, greater<int> > zero_indegree;

	for(int u = 1; u <= V; ++u){
		vector<int>::iterator it;
		for(it = graph[u].begin(); it != graph[u].end(); ++it){
			indegrees[*it]++;
		}
	}

	for(int u = 1; u <= V; ++u){
		if(indegrees[u] == 0) zero_indegree.push(u);
	}

	while(!zero_indegree.empty()){
		int u = zero_indegree.top();
		zero_indegree.pop();

		result.push_back(u);
		vector<int>::iterator it;
		for(it = graph[u].begin(); it != graph[u].end(); ++it){
			indegrees[*it]--;
			if(indegrees[*it] == 0) zero_indegree.push(*it);
		}
	}

	//check for cycle
	if(result.size() != V) return false;
	return true;
}

void dfs(int u, vector<vector<int>> &graph, vector<bool> &visited, vector<int> &result){
	visited[u] = true;

	for(int i = 0; i < graph[u].size(); ++i){
		int v = graph[u][i];
		if(!visited[v]){
			dfs(v, graph, visited, result);
		}
	}

	result.push_back(u);
}

void topological_sort_dfs(vector<vector<int>> &graph, vector<int> &result){
	vector<bool> visited(V, false);

	for(int i = 0; i < V; ++i){
		if(!visited[i]){
			dfs(i, graph, visited, result);
		}
	}

	reverse(result.begin(), result.end());
}



int main() {

	return 0;
}
