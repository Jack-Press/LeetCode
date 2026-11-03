class Solution {
public:
    int minMoves(vector<int>& nums) {
        int res= 0;
        int max = nums[0];

        for(int i=0;i<nums.size( );i++){
	        int num = nums[i];
	        if (num > max){
		        res += (num - max) * i;
		        max = num;
	        }
	        else{
		        res += max- num;
	        }
        }

        return res;
    }
};