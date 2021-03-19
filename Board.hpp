#include <string>
#include "Direction.hpp"

namespace ariel{
		class Board{
	
		private:
			int rows;
			int columns;


		public:
			void post(int row_loc,int column_loc, Direction direction, std::string ad_data);
        	std::string read( int row_loc, int column_loc, Direction direction, int ad_len);
        	void show();
			Board();

	};
}