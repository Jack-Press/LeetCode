class ProductOfNumbers {
        vector<int> nums;
public:
    void add(int num) {
        nums.push_back(num);
    }
    
    int getProduct(int k) {
        int n = nums.size() - 1;
        int product = 1;
        for(int i=0;i<k;i++){
            product *= nums[n-i];
        }

        return product;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */