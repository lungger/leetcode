class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> leftMinHeap;
        priority_queue<int, vector<int>, greater<int>> rightMinHeap;
        int l, r;
        long long total = 0;

        for (l = 0; l < candidates; l++) {
            leftMinHeap.push(costs[l]);
        }
        for (r = costs.size() - 1; r > costs.size() - 1 - candidates;  r--) {
            if (r < l)
                break;
            rightMinHeap.push(costs[r]);
        }

        for (int i = 0; i < k; i++) {
            if (!leftMinHeap.empty() && !rightMinHeap.empty()) {
                int lMin = leftMinHeap.top();
                int rMin = rightMinHeap.top();

                if  (lMin <= rMin) {
                    total += lMin;
                    leftMinHeap.pop();
                    if (l <= r)
                        leftMinHeap.push(costs[l++]);
                }
                else {
                    total += rMin;
                    rightMinHeap.pop();
                    if (l <= r)
                        rightMinHeap.push(costs[r--]);
                }
            }
            else if (leftMinHeap.empty()) {
                total += rightMinHeap.top();
                rightMinHeap.pop();
            }
            else if (rightMinHeap.empty()) {
                total += leftMinHeap.top();
                leftMinHeap.pop();
            }
        }

        return total;
    }
};