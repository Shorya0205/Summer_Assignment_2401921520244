class SummaryRanges {
public:

    unordered_set<int>st;
    SummaryRanges() {
        st.clear();
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
    vector<int> nums(st.begin(), st.end());
    sort(nums.begin(), nums.end());

    vector<vector<int>> result;
    int n = nums.size();

    if(n == 0) return result;

    int l = nums[0];

    for(int i = 0; i < n; i++) {

        if(i < n-1 && nums[i+1] == nums[i] + 1) {
            continue;
        }

        result.push_back({l, nums[i]});

        if(i < n-1) {
            l = nums[i+1];
        }
    }

    return result;
}
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */