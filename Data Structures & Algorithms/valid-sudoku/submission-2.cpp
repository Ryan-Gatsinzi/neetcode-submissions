#include <unordered_map>

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int board_size = 9;

        std::unordered_map<char, int> group_col_1;
        std::unordered_map<char, int> group_col_2;
        std::unordered_map<char, int> group_col_3;

        for(int row = 0; row < board_size; row++){
            std::unordered_map<char, int> row_appearances;
            std::unordered_map<char, int> col_appearances;

            for(int col = 0; col < board_size; col++){
                char row_elem = board[row][col];
                //check row
                //  if find(board element) returns an iterator i.e any iterator other than row_appearances.end() that means the elem has already been seen and added to the map hence a repetion in the row
                if((row_appearances.find(row_elem) != row_appearances.end()) && row_elem != '.') 
                    return false;
                row_appearances.emplace(row_elem, 1);


                char col_elem = board[col][row];
                //check column
                //  if find(board element) returns an iterator i.e any iterator other than col_appearances.end() that means the elem has already been seen and added to the map hence a repetion in the col
                if((col_appearances.find(col_elem) != col_appearances.end() && col_elem != '.')) 
                    return false;
                col_appearances.emplace(col_elem, 1);

            }

            // check 3x3 box
            for(int col = 0; col < board_size; col++){               
                char group_elem = board[row][col];

                if(col < 3){
                    if((group_col_1.find(group_elem) != group_col_1.end()) && group_elem != '.')
                        return false;
                    
                    group_col_1.emplace(group_elem, 1);
                }
                
                if(col >= 3 && col < 6){
                    if((group_col_2.find(group_elem) != group_col_2.end()) && group_elem != '.')
                        return false;
                    
                    group_col_2.emplace(group_elem, 1);
                }

                if(col >= 6){
                    if((group_col_3.find(group_elem) != group_col_3.end()) && group_elem != '.')
                        return false;
                    
                    group_col_3.emplace(group_elem, 1);
                }
               
            }
            if((row+1) % 3 == 0){
                group_col_1.clear();
                group_col_2.clear();
                group_col_3.clear();
            }
        }

        return true;
    }
};
