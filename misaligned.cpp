#include <iostream>
#include <cstring>
#include <assert.h>
#include <vector>
#include <algorithm>

using namespace std;

int printColorMap() {
    const char* majorColors[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColors[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int majorColorLen = (sizeof(majorColors) / sizeof(majorColors[0]));
    int minorColorLen = (sizeof(minorColors) / sizeof(minorColors[0]));
    vector<pair<string, string>> colorPair;
    int i = 0, j = 0;
    for(i = 0; i < majorColorLen; i++) {
        for(j = 0; j < minorColorLen; j++) {
            string majorColor = majorColors[i];
            string minorColor = minorColors[i];
            std::cout <<  i * 5 + j << " | " <<  majorColor << " | " <<  minorColor << "\n";
            pair<string, string> toFind(majorColor, minorColor);
            auto itr = std::find_if(colorPair.begin(), colorPair.end(), [&toFind](pair<string, string> p){
               return p.first == toFind.first && p.second == toFind.second;
            });
            assert (itr != colorPair.end());
            colorPair.emplace_back(make_pair(majorColor, minorColor));
        }
    }
    
    return i * j;
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    std::cout << "All is well (maybe!)\n";
    return 0;
}