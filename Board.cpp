#include "Board.hpp"
#include "Direction.hpp"
#include <string>
#include <iostream>
#include <vector>

using namespace std;
using namespace ariel;

	Board::Board()
    {
        rows = 0;
        columns = 0;
		message_board.push_back(vector<char>{'_'});
    }

	void Board::post(unsigned int row_loc,unsigned int column_loc, Direction direction, string ad_data)
    {
		if(ad_data.length()==0){
			return;
		}
		int index_in_string=0;
		//if the rows location for post is bigger then numbers of rows
		if(rows<row_loc){
			for(int i=rows-1;i<=row_loc;i++){
				message_board.push_back(vector<char>(columns,'_'));
			}
			rows=row_loc;
			}
		//if the column location for post bigger then the numbers of columns
		if(columns<column_loc){
			for(int i=0;i<rows;i++){
				for(int j=columns-1; j<=column_loc;j++){
					message_board.at(i).push_back('_');
					}
				}
			columns=column_loc;
		}
		
		if(direction==Direction::Horizontal){
			//if the message length bigger then the numbers of columns
			if(columns<column_loc+ad_data.length()){
				for(int i=0;i<rows;i++){
					for(int j=columns-1; j<(column_loc+ad_data.length())-1;j++){
						message_board.at(i).push_back('_');
					}
				}
				columns=columns+(column_loc+ad_data.length()-columns);
			}
			//post the message
			for (int j=column_loc;j<column_loc+(ad_data.length())-1;j++){
				message_board.at(row_loc).at(j)=ad_data.at(index_in_string);
				index_in_string++;
			}
		}
		else{
			//if the message length bigger then the numbers of columns
			if(rows<row_loc+ad_data.length()){
				for(int i=rows-1;i<(row_loc+ad_data.length()-1);i++){
					message_board.push_back(vector<char>(columns, '_'));
				}
				rows= rows+(row_loc+ad_data.length()-rows);
			}
			//post the message	
			for (int i=row_loc;i<row_loc+(ad_data.length())-1;i++){
				message_board.at(i).at(column_loc)=ad_data.at(index_in_string);
				index_in_string++;
			}
		}
	}

	string Board::read(unsigned int row_loc,unsigned int column_loc, Direction direction,unsigned int ad_len)
    {
		string read_ad="";
		// if(direction==Direction::Horizontal){
		// 	for (int i=row_loc;i<row_loc+ad_len;i++){
		// 		read_ad=read_ad+message_board[i][column_loc];
		// 	}
		// }
		// else
		// {
		// 	if(direction==Direction::Vertical){
		// 		for (int j=column_loc;j<column_loc+ad_len;j++){
		// 			read_ad=read_ad+message_board[row_loc][j];
		// 		}
		// 	}
		// }
		return read_ad;
	}

	void Board::show()
	{
		// for (int i = 0; i < message_board.size(); i++)
        // {
        //     cout << i << ":  ";
        //     for (int j = 0; j < message_board.at(i).size(); j++)
        //     {
        //         cout << message_board.at(i).at(j);
        //     }
        //     cout << endl;
        // }
	}
	


