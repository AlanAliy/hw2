#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"


std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
//TODO this currently parses ewach word greater than size two and seperates punctuations IDK if that is what we want
//ISBN AND MOVIE GENRE WORK DIFERENTLY
std::set<std::string> parseStringToWords(std::string rawWords)
{
    std::stringstream toParse(rawWords);
    std::set<std::string> keywords;
    std::string word;

    while( toParse >> word) {
        //word = trim(word);
        if (word.size() <= 1) {
            continue;
        }
        else {
            word = convToLower(word);
            size_t last_pos = 0;
            std::string keyword;
            for(size_t i=0; i < word.size(); i++) { 
                if ((i - last_pos >= 2) && ispunct(word[i])){                                                                                                           //2) The length of the word between i and the index we left off at myst be 2
                    keyword = word.substr(last_pos, i-last_pos);
                    keywords.insert(keyword);
                    last_pos = i+1;
                }
                else if ((i - last_pos >= 2) && (i == word.size()-1)) {
                    keyword = word.substr(last_pos, (i-last_pos) + 1);
                    keywords.insert(keyword);
                    last_pos = i+1;
                }

            }
        }
    }
    return keywords;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
