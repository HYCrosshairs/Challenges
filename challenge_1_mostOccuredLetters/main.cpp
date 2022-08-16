#include "challenge_1_most_occurredLetters.hpp"

#include <map>

using namespace challenges::mol;

int main(int argc, char const *argv[])
{
    MOccurredL mOccurredL;
    std::map<char, int> mMap;

    mOccurredL.extractLettersFromFile("input.txt", mMap);

    std::multimap<int, char> ordMap;
    mOccurredL.flipMap(mMap, ordMap);

    mOccurredL.showTopOccurrences(ordMap, 10);
    return 0;
}
