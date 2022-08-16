#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>

namespace challenges { 
namespace mol {

constexpr int FIRST_CAPITAL_LETTER = 65;
constexpr int FIRST_SMALL_LETTER = 97;
constexpr int LAST_CAPITAL_LETTER = 90;
constexpr int LAST_SMALL_LETTER = 122;
constexpr int DELTA_TO_LOWER = 32;
constexpr int INIT_COUNTER = 1;

class MOccurredL 
{
public:
    MOccurredL();
    ~MOccurredL() = default;

    template<typename A, typename B>
    void extractLettersFromFile(const std::string &filename, std::map<A, B> &mapOfLetters)
    {
        std::ifstream file;

        file.open(filename);

        if (not file.is_open())
        {
            std::cerr << "Error: Could not open file " << filename << std::endl;
            return;
        }

        while(not file.eof())
        {
            char letter{' '};

            file >> letter;

            if (letter < FIRST_CAPITAL_LETTER or 
                (letter > LAST_CAPITAL_LETTER and 
                letter < FIRST_SMALL_LETTER) or
                letter > LAST_SMALL_LETTER)
            {
                continue;
            }

            if (letter >= FIRST_CAPITAL_LETTER and letter <= LAST_CAPITAL_LETTER)
            {
                letter += DELTA_TO_LOWER;
            }
            
            if(mapOfLetters.find(letter) == mapOfLetters.end())
            {
                mapOfLetters.insert(std::make_pair(letter, INIT_COUNTER));
            } else
            {
                mapOfLetters[letter]++;
            }
        }

        file.close();
    }

    template<typename A, typename B>
    void flipMap(std::map<A, B> &mapSrc, std::multimap<B, A> &mapDst)
    {
        for(typename std::map<A, B>::const_iterator it = mapSrc.begin(); it not_eq mapSrc.end(); ++it)
        {
            mapDst.insert(std::pair<B, A>(it->second, it->first));
        }
    }

    template<typename A, typename B>
    void showTopOccurrences(std::multimap<A, B> &map, int topOcc)
    {
        size_t index{0};

        for (typename std::multimap<A, B>::const_reverse_iterator it = map.rbegin(); it not_eq map.rend(); ++it)
        {
            topOcc--;
            std::cout << "Top(" << ++index << ") -> [" << it->second << "] : " << it->first << std::endl;
            
            if(topOcc == 0)
            {
                break;
            }
        }
    }
};

} // mol
} // challenges