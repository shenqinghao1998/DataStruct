#include <iostream>

using namespace std;
#define MaxSize 100

bool insertElem(int *SqList, int &length, int position, int elem);//����
bool deleteElem(int *SqList, int &length, int position, int &elem);//ɾ��
bool createList(int *SqList, int &length);//����
bool merge(const int *SqListA, int lengthA, const int *SqListB, int lengthB, int *SqListC);//�ϲ�
bool reverseSimple(int *SqListA, int length);//�����ã����ø����ĳ��ȣ�
bool reverseComplex(int *SqList, int left, int right, int lengthToReverse);//��ָ�����ȣ�ָ��λ�õ�Ԫ�ؽ�������
bool locateByElem(const int *SqList, int number, int &location);//��Ԫ�ز�������λ�ã������±꣩
bool locateByPosition(const int *SqList, int length, int location, int &number);//��λ�ò��Ҷ�Ӧλ�õ�Ԫ��
bool moveByNumberP(int *SqList, int p, int listLength); //��˳���ѭ������pλ

void partitionA(int *SqList, int length);//�Ե�һ��Ԫ��Ϊ����ͱȽ�Ԫ��
void partitionB(int *SqList, int length, int compare);//�Ե�һ��Ԫ��Ϊ���ᣬͬʱ��compareΪ�Ƚ�Ԫ�أ��������һ�����ֺ�����ֻ��Ҫ�ѵ�һԪ����Ϊcompare��
void partitionC(int *SqList, int length, int randomNumber);//������Ԫ��Ϊ����ͱȽ�Ԫ��
void showElem(int *SqList, int length); //��ʾ


int main() {
    int SqListA[MaxSize];//�����������£�ֻ�����鼴�ɽ������˳�������⣬����ṹ��
    int length;

    createList(SqListA, length);

    return 0;
}

bool createList(int *SqList, int &length) {
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

bool insertElem(int *SqList, int &length, int position, int elem) {
    if (position < 0 || position > length || length == MaxSize)
        return false;

    for (int i = length - 1; i >= position; i--) {
        SqList[i + 1] = SqList[i];
    }

    SqList[position] = elem;
    length++;

    return true;
}

bool deleteElem(int *SqList, int &length, int position, int &elem) {
    if (position < 0 || position > length - 1)
        return false;

    elem = SqList[position];

    for (int i = position - 1; i < length - 1; ++i) {
        SqList[i] = SqList[i + 1];
    }

    length--;
    return true;
}

void showElem(int *SqList, int length) {
    for (int j = 0; j < length; ++j) {
        cout << SqList[j] << "\t";
    }
    cout << endl << "Length:" << length;
}


bool merge(const int *SqListA, int lengthA, const int *SqListB, int lengthB, int *SqListC) {
    if (lengthB + lengthA > 2 * MaxSize)
        return false;

    int pointerA = 0;
    int pointerB = 0;
    int pointerC = 0;

    while (pointerA < lengthA && pointerB < lengthB) {
        if (SqListA[pointerA] < SqListB[pointerB]) {
            SqListC[pointerC++] = SqListA[pointerA++];
        } else {
            SqListC[pointerC++] = SqListB[pointerB++];
        }
    }

    while (pointerA < lengthA) {
        SqListC[pointerC++] = SqListA[pointerA++];
    }
    while (pointerB < lengthB) {
        SqListC[pointerC++] = SqListB[pointerB++];
    }

    return true;
}

bool reverseSimple(int *SqListA, int length) {
    if (length < 0)
        return false;

    int temp;

    for (int head = 0, back = length - 1; head < back; ++head, --back) {
        temp = SqListA[head];
        SqListA[head] = SqListA[back];
        SqListA[back] = temp;
    }

    return true;
}

bool reverseComplex(int *SqList, int left, int right, int lengthToReverse) {
    if (left < 0 || right < 0 || lengthToReverse < 0 ||
        lengthToReverse > MaxSize || right > MaxSize || left > MaxSize)
        return false;

    int temp;
    for (int head = left, back = right;
         head < left + lengthToReverse && left < right; ++head, --back) {
        temp = SqList[head];
        SqList[head] = SqList[back];
        SqList[back] = temp;
    }

    return true;
}

bool moveByNumberP(int *SqList, int p, int listLength) {
    if (SqList == nullptr || p < 0 || listLength < 0)
        return false;
    reverseComplex(SqList, 0, p - 1, p);
    reverseComplex(SqList, p, listLength - 1, listLength - p);
    reverseComplex(SqList, 0, listLength - 1, listLength);

    return true;
}

bool locateByElem(const int *SqList, int number, int &location) {
    if (number < 0 || SqList == nullptr)
        return false;

    for (int i = 0; i < number; ++i) {
        if (SqList[i] == number) {
            location = i;
            return true;
        }
    }

    return false;
}

bool locateByPosition(const int *SqList, int length, int location, int &number) {
    if (location < 0 || location > length - 1 || SqList == nullptr)
        return false;

    for (int i = 0; i < location; ++i) {
        if (i == location) {
            number = SqList[i];
        }
    }

    return true;
}

void partitionA(int *SqList, int length) {
    int head = 0;
    int back = length - 1;
    int temp = SqList[0];

    while (head < back) {
        while (head < back && SqList[back] >= temp)//�ҵ���tempС��Ԫ������λ��
            --back;
        if (head < back) {
            SqList[head] = SqList[back];
            head++;
        }
        while (head < back && SqList[head] < temp)
            ++head;
        if (head < back) {
            SqList[back] = SqList[head];
            --back;
        }
    }

    SqList[head] = temp;
}

void partitionB(int *SqList, int length, int compare) {
    int head = 0;
    int back = length - 1;
    int temp = SqList[0];

    while (head < back) {
        while (head < back && SqList[back] >= compare)//�ҵ���tempС��Ԫ������λ��
            --back;
        if (head < back) {
            SqList[head] = SqList[back];
            head++;
        }
        while (head < back && SqList[head] < compare)
            ++head;
        if (head < back) {
            SqList[back] = SqList[head];
            --back;
        }
    }

    SqList[head] = temp;
}

void partitionC(int *SqList, int length, int randomNumber) {
    int head = 0;
    int back = length - 1;
    int temp = SqList[0];
    SqList[0] = SqList[randomNumber];//��
    SqList[randomNumber] = temp;
    temp = SqList[head];

    while (head < back) {
        while (head < back && SqList[back] >= temp)//�ҵ���tempС��Ԫ������λ��
            --back;
        if (head < back) {
            SqList[head] = SqList[back];
            head++;
        }
        while (head < back && SqList[head] < temp)
            ++head;
        if (head < back) {
            SqList[back] = SqList[head];
            --back;
        }
    }

    SqList[head] = temp;
}