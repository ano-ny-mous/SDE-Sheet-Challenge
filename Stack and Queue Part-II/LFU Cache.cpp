class LFUCache
{
public:
    int n, sz;
    unordered_map<int, list<vector<int>>::iterator> mp;
    map<int, list<vector<int>>> freq;

    LFUCache(int capacity)
    {
        n = capacity;
        sz = 0;
    }

    void mostRecentlyUsed(int key)
    {
        auto &node = *(mp[key]);
        int v = node[1];
        int c = node[2];
        freq[c].erase(mp[key]);
        if (freq[c].empty())
        {
            freq.erase(c);
        }
        freq[c + 1].push_front({key, v, c + 1});
        mp[key] = freq[c + 1].begin();
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end())
            return -1;

        auto &node = (*(mp[key]));
        int value = node[1];
        mostRecentlyUsed(key);
        return value;
    }

    void put(int key, int value)
    {
        if (n == 0)
        {
            return;
        }
        if (mp.find(key) != mp.end())
        {
            auto &node = (*(mp[key]));
            node[1] = value;
            mostRecentlyUsed(key);
        }
        else if (sz < n)
        {
            sz++;
            freq[1].push_front(vector<int>({key, value, 1}));
            mp[key] = freq[1].begin();
        }
        else
        {
            auto &del = freq.begin()->second;
            int keydel = (del.back())[0];
            del.pop_back();
            if (del.empty())
            {
                freq.erase(freq.begin()->first);
            }
            freq[1].push_front(vector<int>({key, value, 1}));

            mp.erase(keydel);
            mp[key] = freq[1].begin();
        }
    }
};
