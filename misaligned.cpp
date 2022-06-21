#include <iostream>
#include <iomanip>
#include <cstring>
#include <assert.h>
using namespace std;
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
    int maxMajorColorLen = getMaxWidth(majorColor, 5);
    int maxMinorColorLen = getMaxWidth(minorColor, 5);
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 1; j <= 5; j++) {
            std::cout << std::setw(4) << left << i * 5 + j << " | " << std::setw(maxMajorColorLen) << left <<  majorColor[i] << " | " << std::setw(maxMinorColorLen) << minorColor[i] << "\n";
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