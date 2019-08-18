// -------------------------------------------
//					Word
// -------------------------------------------
#include <string>
#include <algorithm>
#include "Word.h"
#include <cstring>
#include <cctype>


Word::Word(const string& word): word_{word}
{
	// throws an exception (in the form of WordContainsNoLetters object)
	// indicating that the word being constructed contains no letters
	if (word_.empty()) throw WordContainsNoLetters{};
    
    //transform function to convert string to upper case
    transform(word_.begin(), word_.end(), word_.begin(), ::toupper );
    //more STL functions: erase(), remove_if() and ispunct() to check if character in string is punctuation mark
    //and then removing it from the string if it is
    word_.erase (remove_if( word_.begin(), word_.end(), ::ispunct ) , word_.end() ) ;
   
    //Piece of code to check if the entire string contatins characters and throw an exception
    auto cntr = 0u;
    for(auto i = 0u; i != word_.size(); i++)
    {
       if (ispunct(word_[i]) !=0 ){cntr++;}
    }
    if(cntr == word_.size())
    {
        throw WordContainsNoLetters{};
    }
    
   //Piece of code to check for a space in word string and throw an exception
   for(auto p : word_)
   {
     if(p == ' '){ throw WordContainsSpace{}; } 
   }
	// Note, we will cover exceptions in more detail later on in the course.
}

// overloads the equivalence operator which allows two Words to be compared using ==
bool Word::operator==(const Word& rhs) const
{
    //std::transform(word_.begin(), word_.end(), word_.begin(), [](unsigned char c){ return std::tolower(c); });
    //std::transform(rhs.word_.begin(), rhs.word_.end(), rhs.word_.begin(), [](unsigned char c){ return std::tolower(c); });
    
	if (word_ == rhs.word_)
		return true;
	else
		return false;
}

bool Word::isQueryable() const
{
    if(word_.size() >= 3){return true;}
      else if(word_.size() < 3){return false;}
	//return false;
}


