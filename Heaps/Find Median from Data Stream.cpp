// Approach - 1
// TLE
// Time Complexity: O(n*log(n))
// Space Complexity: O(n)
class MedianFinder
{
public:
    vector<int> arr;

    MedianFinder()
    {
    }

    void addNum(int num)
    {
        arr.push_back(num);
        sort(arr.begin(), arr.end());
    }

    double findMedian()
    {
        if (arr.size() % 2 == 0)
        {
            int rightmid = arr.size() / 2;
            int leftmid = (arr.size() / 2) - 1;
            return (double)(arr[leftmid] + arr[rightmid]) / 2;
        }
        else
        {
            int mid = arr.size() / 2;
            return arr[mid];
        }
    }
};

// Approach - 2
// Time Complexity: O(log(n))
// Space Complexity: O(n)
class MedianFinder
{
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (maxHeap.size() == 0 || maxHeap.top() > num)
        {
            maxHeap.push(num);
        }
        else
        {
            minHeap.push(num);
        }

        if (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian()
    {
        if ((minHeap.size() + maxHeap.size()) % 2 == 0)
        {
            return ((double)minHeap.top() + maxHeap.top()) / 2;
        }
        else
        {
            return maxHeap.top();
        }
    }
};