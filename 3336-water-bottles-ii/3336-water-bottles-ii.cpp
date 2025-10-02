class Solution {
public:
    int maxBottlesDrunk(int& numBottles, int& numExchange) {
        int res = numBottles;
        while(numBottles >= numExchange){
            res++;
            numBottles -= (numExchange - 1);
            numExchange++;
        }
        return res;
    }
};