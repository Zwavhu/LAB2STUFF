// -------------------------------------------
//					Line
// -------------------------------------------

#include "Line.h"
#include <algorithm>
#include <sstream>
#include <cctype>
#include <string>

Line::Line(const string& line) : line_(line)
{
	// Hint: some of string's member functions might come in handy here
	// for extracting words.
}

bool Line::contains(const Word& search_word) const
{
    if(line_.empty()) {return false;}
    
		if(search_word.isQueryable() == 1)
		{
			//for extracting words initialise two iterator type markers 
			auto atStart = line_.begin();
			auto atEnd = line_.begin();
			string tempString;
            auto endOfLine = false;

			while(!endOfLine)
			{
				// atEnd shifts and now 'points' to next space from atStart. characters within [atStart, atEnd) (exception: end of line -> [start, last])range are
				// assumed to form a word, so they are exctracted into tempString 
				atEnd = find(atStart, line_.end(), ' '); 
				if(atEnd == atStart)
                  {  atStart++;
                  }//Special case where start is a space (e.g two consecutive spaces within line); advance start by 1
                   //if we find tha the first word in a line is a space then we move to next word
				else
				{
					tempString.assign(atStart, atEnd); //assaigning all words/characters between start and end to temp string 
					
					auto compare_word = Word{tempString};
					if(compare_word == search_word)
					{
						return true;
						break; //break because you've found the word
					}
					//check if at the end of line and set loop break conditions true
					if(atEnd == line_.end())
					  { 
                          endOfLine = true;
                      }
					//the start position is now an element after the current pos/last poistion
					atStart = ++atEnd;
				}
			}
			
		}
    return false;
}
