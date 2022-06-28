#ifndef MISALIGNED_H_
#define MISALIGNED_H_

int PairNumFromColorNum(int majorColor,int minorColor,int maxMinorColor) 
{
    return (majorColor * maxMinorColor + minorColor + 1);
}

int MajorColorFromPairNum(int pairNum, int maxMinorColor)
{ 
    return ((pairNum - 1) / maxMinorColor);
}
int MinorColorFromPairNum(int pairNum, int maxMinorColor) 
{
    return ((pairNum - 1) % maxMinorColor);
}

#endif // MISALIGNED_H_