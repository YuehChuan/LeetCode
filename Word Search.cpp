class Solution {
//https://leetcode.com/problems/word-search/
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty())   return false;
        if(word.empty())    return false;
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(existHelper(board,word,i,j,0))   return true;
            }
        }
        return false;
    }
    
    bool existHelper(vector<vector<char> >&board,string word,int i,int j,int k){
        if(k==word.size())  return true;//k代表的是第几位
        
        if(i<0||i>=board.size()||j<0||j>=board[0].size())   return false;
        if(board[i][j]!=word[k])    return false;
        
        board[i][j]='#';//防止以后再次返回到当前节点。直接设置一个非字符
        
        bool result=(existHelper(board,word,i-1,j,k+1) || existHelper(board,word,i+1,j,k+1)
                    ||existHelper(board,word,i,j-1,k+1) || existHelper(board,word,i,j+1,k+1));
        board[i][j]=word[k];
        
        return result;
    }
};
//有很多细节性的地方，需要琢磨，还是不会，稍微会了点，不会啊，通过啦，不会，还是不会
//基本一次通过哦，似乎文思如泉，做了好几遍啦，一次AC 啊
