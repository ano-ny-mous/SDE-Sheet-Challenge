//Approach - 1
//TLE
//Time Complexity: O(n^2)
//Space Complexity: O(n)
class LRUCache {
public:
    int cap;    
    vector<pair<int,int>> LRU;
    LRUCache(int capacity) 
    {
        cap=capacity;
    }
        
    int get(int key) 
    {
        for(int i=0;i<LRU.size();i++)
        {
            if(LRU[i].first==key)
            {
                int val=LRU[i].second;
                LRU.erase(LRU.begin()+i);
                pair<int,int> temp={key,val};
                LRU.push_back(temp);
                return val;
            }
        }
        return -1;
    }
    
    void put(int key, int value) 
    {
        for(int i=0;i<LRU.size();i++)
        {
            if(LRU[i].first==key)
            {
                LRU.erase(LRU.begin()+i);
                pair<int,int> temp={key,value};
                LRU.push_back(temp);
                return;
            }
        }
        if(LRU.size()<cap)
        {
            LRU.push_back({key,value});
        }
        else
        {
            LRU.erase(LRU.begin());
            LRU.push_back({key,value});
        }
    }
};

//Approach - 2
//Time Complexity: O(n)
//Space Complexity: O(n)
class LRUCache {
public:
    int cap;
    unordered_map<int,pair<list<int>::iterator,int>> mp;
    list<int> dll;

    LRUCache(int capacity) 
    {
        cap=capacity;
    }
    
    int get(int key) 
    {
        if(mp.find(key)!=mp.end())
        {
            dll.push_front(key);
            dll.erase(mp[key].first);
            mp[key].first=dll.begin();
            return mp[key].second;
        }
        return -1;
    }
    
    void put(int key, int value) 
    {
        if(mp.find(key)!=mp.end())
        {
            dll.push_front(key);
            dll.erase(mp[key].first);
            mp[key].first=dll.begin();
            mp[key].second=value;
        }
        else if(mp.size()<cap)
        {
            dll.push_front(key);
            mp[key].first=dll.begin();
            mp[key].second=value;
        }
        else
        {
            int key_del=dll.back();
            dll.pop_back();
            mp.erase(key_del);
            dll.push_front(key);
            mp[key].first=dll.begin();
            mp[key].second=value;
        }
    }
};
