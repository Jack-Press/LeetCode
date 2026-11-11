class Solution {
public:
    long long minimumCost(long long cost1, long long cost2, long long costBoth, int need1, int need2) {
        long long res = 0;
        if(costBoth < cost1 + cost2){
            if(need1<need2){
                res = costBoth * need1;
                if(costBoth < cost2){
                    res += costBoth * (need2 - need1);
                }
                else{
                    res += cost2 * (need2-need1);
                }
            }
            else{
                res = costBoth * need2;
                if(costBoth < cost1){
                    res += costBoth * (need1 - need2);
                }
                else{
                    res += cost1 * (need1-need2);
                }
            }
        }
        else{
            res = need1 * cost1 + need2 * cost2;
        }

        return res;
    }
};