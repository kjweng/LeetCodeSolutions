class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (exist(board, word.c_str(), i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    int m;
    int n;
    bool exist(vector<vector<char>>& board, const char* word, int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n || *word != board[x][y] || board[x][y] == '\0') {
            return false;
        }
        if (*(word+1) == '\0') {
            return true;
        }
        
        char t = board[x][y];
        board[x][y] = '\0';
        if (exist(board, (word + 1), x + 1, y) || exist(board, (word + 1), x, y + 1) 
            || exist(board, (word + 1), x, y - 1) || exist(board, (word + 1), x - 1, y)) {
            return true;
        }
        board[x][y] = t;
        return false;
    }
};