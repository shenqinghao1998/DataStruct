#include <iostream>
#include <cmath>
using namespace std;

#define MaxSize 100
#define Min 0.0001
int compare(const float *A, int lengthA, const float *B, int lengthB);
bool createList(float *SqList, int &length);

int main()
{
    float A[MaxSize];
    int lengthA = 0;
    createList(A, lengthA);
    float B[MaxSize];
    int lengthB = 0;
    createList(B, lengthB);

}

bool createList(float *SqList, int &length) {
    cout << "please input the DataStruct length: ";
    cin >> length;

    if (length > MaxSize)
        return false;

    cout << "please input the elem in line: " << endl;
    for (int i = 0; i < length; ++i) {
        cin >> SqList[i];
    }

    return true;
}

int compare(const float *A, int lengthA, const float *B, int lengthB){
    int i = 0;
    for (;i < lengthA && i < lengthB;) {
        if (fabs(A[i]-B[i]) < Min)
            i++;
        else
            break;;
    }

    if (i >= lengthA && i >=lengthB)
        return 0;
    else if((i >=lengthA) || A[i] < B[i])
        return -1;
    else
        return 1;
}