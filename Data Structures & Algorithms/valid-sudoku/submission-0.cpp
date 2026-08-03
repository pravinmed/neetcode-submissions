class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check for row
        for(int i = 0;i < board.size();i++){
            std::map<int,int> mp;
            for(int j = 0; j < board[0].size();j++){
                if(int(board[i][j]) == 46){
                    continue;
                }
               if(mp.find(int(board[i][j])) != mp.end()){
                  return false;
               }else {
                mp[int(board[i][j])] = 1;
               }
            }
        }
        std::cout << " done with row " << std::endl;
        // check for col
        for(int i = 0;i < board.size();i++){
            std::map<int,int> mp;
            for(int j = 0; j < board[0].size();j++){
                 if(int(board[j][i]) == 46){
                    continue;
                }
                if(mp.find(int(board[j][i])) != mp.end()){
                    return false;
                }else {
                   mp[int(board[j][i])] = 1;
                }
            }
        }
        std::cout << " done with col " << std::endl;
        // check for square 
        for(int i = 1;i < board.size()-1;i+=3){       
            for(int j = 1; j < board[0].size()-1;j+=3){
                std::map<int,int> mp;
                std::cout << "----new loop-----" << std::endl;
                for(int m = -1;m<=1;m++){
                    for(int n = -1;n <=1;n++){
                        if(int(board[i+m][j+n]) == 46){
                            continue;
                        }
                        if(mp.find(int(board[i+m][j+n])) != mp.end()){
                            std::cout<< "dup " << std::endl;
                            std::cout << i+m << " i " << j+n << " j " << std::endl;
                            return false;
                        } else {
                            std::cout<< "inserting " << std::endl;
                            std::cout << i+m << " i " << j+n << " j " << std::endl;
                            mp[int(board[i+m][j+n])] = 1;
                        }
                    }
                }
            }
        }
        return true;

    }
};
