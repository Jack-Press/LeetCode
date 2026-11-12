class Solution {
public:
    string getSmallestString(string s, int k) {
        for(char& c : s){
            int placement = c - 'a';
            if(placement > 25 - placement){
                placement = 26 - placement;
            }
            if(placement <= k){
                c = 'a';
                k -= placement;
            }
            else{
                c -= k;
                break;
            }
        }

        return s;
    }
};