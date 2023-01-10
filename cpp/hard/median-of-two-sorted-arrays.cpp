using MinHeap_t = priority_queue <int, vector<int>, greater<int> >;
using MaxHeap_t = priority_queue <int>;


class Solution {

private:
    MaxHeap_t h1;
    MinHeap_t h2;

public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        vector<int> arr;
        
        for (auto a: arr1) arr.push_back(a);
        for (auto a: arr2) arr.push_back(a);
        
        for(auto a: arr)
        {
            if(h1.empty())
            {
                h1.push(a);
                continue;
            }

            if(h1.size() == h2.size()) {
                auto min_from_h2 = h2.top();
                if(a >= min_from_h2)
                    h2.push(a);
                else
                    h1.push(a);
            } else {
                if( h1.size() > h2.size())
                {
                    auto max_from_h1 = h1.top();
                    if ( a < max_from_h1)
                    {
                        h1.pop();
                        h2.push(max_from_h1);
                        h1.push(a);
                    } else {
                        h2.push(a);
                    }
                }
                else
                {
                    auto min_from_h2 = h2.top();
                    if(a > min_from_h2)
                    {
                        h2.pop();
                        h1.push(min_from_h2);
                        h2.push(a);
                    } else {
                        h1.push(a);
                    }
                }
            }
        }
        
        if(h2.empty())
            return h1.top();
        if(h1.empty())
            return h2.top();
        

        double min_from_h2 = h2.top();
        double max_from_h1 = h1.top();
        if(h1.size() == h2.size())
        {
            return (min_from_h2+max_from_h1)/2.;
        }
        else {
            if (h1.size() > h2.size())
                return max_from_h1;
            else
                return min_from_h2;
        }
    }
};