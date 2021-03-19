#include "Board.hpp"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

namespace ariel
{
	Board::Board()
    {
        rows = 0;
        columns = 0;
		message_board[0][0]='_';
    }

	void Board::post(int row_loc,int column_loc, Direction direction, string ad_data)
    {
		int location=0;
		if(direction==Direction::Horizontal){
			for (int i=row_loc;i<row_loc+(ad_data.length());i++}){
				message_board[i][column_loc]=ad_data.at(location);
				location++;
			}
		}
		else
		{
			if(direction==Direction::Vertical){
				for (int j=column_loc;j<column_loc+(ad_data.length());j++}){
					message_board[row_loc][j]=ad_data.at(location);
					location++;
				}
			}
		}

	string Board::read(int row_loc, int column_loc, Direction direction, int ad_len)
    {
		string read_ad="";
		if(direction==Direction::Horizontal){
			for (int i=row_loc;i<row_loc+ad_len;i++}){
				read_ad=read_ad+message_board[i][column_loc];
			}
		}
		else
		{
			if(direction==Direction::Vertical){
				for (int j=column_loc;j<column_loc+ad_len;j++}){
					read_ad=read_ad+message_board[row_loc][j];
				}
			}
		}
		return read_ad;
	}

	void Board::show(){
		for (int i = 0; i < message_board.size(); i++)
        {
            cout << i << ":  ";
            for (int j = 0; j < message_board[i].size(); j++)
            {
                cout << message_board[i][j];
            }
            cout << endl;
        }
	}
	
}

