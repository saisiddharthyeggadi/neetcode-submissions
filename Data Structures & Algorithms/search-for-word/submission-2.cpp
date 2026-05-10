class Solution {
public:
    bool word_search(int row, int col, int idx,
                     vector<vector<char>> &board, string &word){

        if(board[row][col] != word[idx])
            return false;

        if(idx == word.size()-1)
            return true;

        int n = board.size();
        int m = board[0].size();

        char temp = board[row][col];
        board[row][col] = '#';

        if(row+1 < n && board[row+1][col] != '#')
            if(word_search(row+1, col, idx+1, board, word))
                return true;

        if(row-1 >= 0 && board[row-1][col] != '#')
            if(word_search(row-1, col, idx+1, board, word))
                return true;

        if(col+1 < m && board[row][col+1] != '#')
            if(word_search(row, col+1, idx+1, board, word))
                return true;

        if(col-1 >= 0 && board[row][col-1] != '#')
            if(word_search(row, col-1, idx+1, board, word))
                return true;

        board[row][col] = temp;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(word_search(i, j, 0, board, word))
                    return true;
            }
        }

        return false;
    }
};