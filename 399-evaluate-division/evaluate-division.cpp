class Solution {
public:
    void dfs(string dividend, string divisor, unordered_map<string, unordered_map<string, double>>& graph, double& tempAns, double tempCount, unordered_set<string>& visited) {
        if (visited.find(dividend) != visited.end()) {
            return;
        }
        visited.insert(dividend);
        if (dividend == divisor) {
            tempAns = tempCount;
            return;
        }
        for (auto& [nextDividend, value] : graph[dividend]) {
            dfs (nextDividend, divisor, graph, tempAns, tempCount * value, visited);
        }
    }

    unordered_map<string, unordered_map<string, double>> buildGraph(vector<vector<string>>& equations, vector<double>& values) {
        unordered_map<string, unordered_map<string, double>> graph;
        for (int i = 0; i < equations.size(); i++) {
            graph[equations[i][0]][equations[i][1]] = values[i];
            graph[equations[i][1]][equations[i][0]] = 1.0 / values[i];
        }
        return graph;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph = buildGraph(equations, values);
        vector<double> ans;
        for (auto& query : queries) {
            string dividend = query[0];
            string divisor = query[1];
            if (graph.find(dividend) == graph.end() || graph.find(divisor) == graph.end()) {
                ans.push_back(-1.0);
            }
            else {
                unordered_set<string> visited;
                double tempAns = -1.0, tempCount = 1.0;
                dfs (dividend, divisor, graph, tempAns, tempCount, visited);
                ans.push_back(tempAns);
            }
        }
        return ans;
    }
};