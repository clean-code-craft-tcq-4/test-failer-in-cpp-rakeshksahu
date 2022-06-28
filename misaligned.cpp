#include <iostream>
#include <assert.h>
#include <iomanip>
#include <cstring>
#include "misaligned.hpp"

int getMaxWidth(const char* color[], int size) {
    int maxLength = 0;
    for (int i = 0; i < size; ++i)
    {
        int length = strlen(color[i]); 
        if (maxLength < length)
        {
            maxLength = length;
        }
    }
    return maxLength;
}

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

    int numberOfMinorColors = sizeof(minorColor) / sizeof(minorColor[0]);
    int numberOfMajorColors = sizeof(majorColor) / sizeof(majorColor[0]);

    int maxMajorColorWidth = getMaxWidth(majorColor, numberOfMajorColors);
    int maxMinorColorWidth = getMaxWidth(minorColor, numberOfMinorColors);

    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::cout << std::left << std::setw(5) <<i * 5 + j + 1 << " | " << std::setw(maxMajorColorWidth) << majorColor[i]
             << " | " << std::setw(maxMinorColorWidth)<< minorColor[j] << std::endl;

            int PairNum = PairNumFromColorNum(i, j, numberOfMinorColors);

            assert(PairNum == i * 5 + j + 1 ); 
            assert(MajorColorFromPairNum(PairNum, numberOfMinorColors) == i);
            assert(MinorColorFromPairNum(PairNum, numberOfMinorColors) == j);
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