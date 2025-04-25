## C++ Merge Intervals Function

Here's how to merge overlapping intervals:

```cpp
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> result;
    for (auto& intv : intervals) {
        if (intv[1] < newInterval[0])
            result.push_back(intv);
        else if (intv[0] > newInterval[1]) {
            result.push_back(newInterval);
            newInterval = intv;
        } else {
            newInterval[0] = min(newInterval[0], intv[0]);
            newInterval[1] = max(newInterval[1], intv[1]);
        }
    }
    result.push_back(newInterval);
    return result;
}
