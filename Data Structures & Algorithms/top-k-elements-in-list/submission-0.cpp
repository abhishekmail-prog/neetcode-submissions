class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // key = number, value = freqency
        unordered_map<int, int> freqMap;

        for(int num : nums) {
            freqMap[num]++; // count the occurence
        }

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>> // makes it MIN heap
        > minHeap;

        for(auto& entry : freqMap) {
            int number = entry.first;
            int frequency = entry.second;

            minHeap.push({frequency, number});

            if(minHeap.size() > k) {
                minHeap.pop(); // removes small freq
            }
        }

        vector<int> result;

        while(!minHeap.empty()) {
            int number = minHeap.top().second;
            result.push_back(number);
            minHeap.pop();
        }

        return result;
    }
};
