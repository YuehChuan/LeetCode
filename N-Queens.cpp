class Solution {
private:
//https://leetcode.com/problems/n-queens/
    int colFlag;//代表列
    int diagFlag1;//index=i+j
    int diagFlag2;//index=n-1+i-j
    
    bool isValid(int rowIndex,int colIndex,int n){
        //行不需要判断，因为我是按照行走的
        //为0说明有效
        if( (1<<colIndex)&colFlag ){
            //为1 无效
            return false;
        }
        if( (1<<(rowIndex+colIndex))&diagFlag1  ){
            return false;
        }
        if( (1<<(n-1+rowIndex-colIndex) ) & diagFlag2 ){
            return false;
        }
        return true;
    }
    
    void setFlag(int rowIndex,int colIndex,int n){
        colFlag   |=(1<<colIndex);
        diagFlag1 |=(1<<(rowIndex+colIndex));
        diagFlag2 |=(1<<(n-1+rowIndex-colIndex));
    }
    
    
    void unsetFlag(int rowIndex, int colIndex, int n) {
        colFlag &= ~(1 << colIndex);
        diagFlag1 &= ~(1 << (rowIndex + colIndex));
        diagFlag2 &= ~(1 << (n + rowIndex - colIndex - 1));
    }
    
    void queenHelper(int n, vector<string> &answer, vector<vector<string> > &result) {
        int rowIndex = answer.size();

        if (rowIndex == n) {
            result.push_back(answer);
            return;
        }
        
        answer.push_back(string(n, '.'));
        for (int i = 0; i < n; i++) {
            if (isValid(rowIndex, i, n)) {
                setFlag(rowIndex, i, n);
                answer.back()[i] = 'Q';
                queenHelper(n, answer, result);
                answer.back()[i] = '.';
                unsetFlag(rowIndex, i, n);
            }
        }
        answer.pop_back();
    }

public:
    vector<vector<string> > solveNQueens(int n) {
        // https://oj.leetcode.com/problems/n-queens/

        colFlag = diagFlag1 = diagFlag2 = 0;
        vector<vector<string> > result;
        vector<string> answer;

        queenHelper(n, answer, result);
        return result;
    }
};
