class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        if (beginWord == endWord) return 1;
        queue<pair<string, int> > q;
        q.push(make_pair(beginWord, 1));
        string chars = "abcdefghijklmnopqrstuvwxyz";

        while (!q.empty()) {
            // Optimize with reference?
            pair<string, int> cur = q.front();
            q.pop();
            string curStr = cur.first;
            
            // Check all possible intermediate
            for (int i = 0; i < beginWord.size(); ++i) {
                for (char c : chars) {
                    string temp(curStr);
                    temp[i] = c;
                    auto it = wordList.find(temp);
                    if (it != wordList.end()) {
                        if (temp == endWord) {
                            return cur.second + 1;
                        }
                        wordList.erase(it);
                        q.push(make_pair(temp, cur.second + 1));
                    }
                }
            }
            
        }
        return 0;
    }
};