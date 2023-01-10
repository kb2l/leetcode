/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    vector<pair<int, int>> IntegerAndWeight;
    int FindDepth(NestedInteger& input, int &currDepth){
        int depth = 1;
        if(input.isInteger()) 
            IntegerAndWeight.push_back(make_pair(input.getInteger(), currDepth));
        else 
        {
            auto newDepth = 1 + currDepth;
            for(auto & nestedInt : input.getList())
                depth = max(depth, 1 + FindDepth(nestedInt, newDepth));
        }
        return depth;
    }
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int maxDepth = 0, depthSumInverse = 0, initialDepth = 1;
        
        for(auto& nestedInt : nestedList)
            maxDepth = max(maxDepth, FindDepth(nestedInt, initialDepth));
        
        for(auto &p : IntegerAndWeight)
            depthSumInverse += p.first * (maxDepth - p.second + 1);
        
        return depthSumInverse;
    }
};