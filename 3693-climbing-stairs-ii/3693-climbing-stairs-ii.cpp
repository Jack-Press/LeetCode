class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        costs[0]++;
        if(n == 1){
            return costs[0];
        }

        int temp = costs[1] + costs[0] + 1;
        costs[1] += 4;
        if(temp < costs[1]){
            costs[1] = temp;
        }
        if(n == 2){
            return costs[1];
        }

        costs[2] += min(costs[1] + 1, costs[0] + 4, 9);

        for(int i=3;i<n;i++){
            costs[i] += min(costs[i-1] + 1, costs[i-2] + 4, costs[i-3] + 9);
        }

        return costs[n-1];
    }


private:
    int min(int op1, int op2, int op3){
        if(op1 < op2 && op1 < op3){
            return op1;
        }
        if(op2<op3){
            return op2;
        }
        return op3;
    }
};