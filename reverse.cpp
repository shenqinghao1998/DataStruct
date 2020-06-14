#include <iostream>

using namespace std;

void create(int a[], int m);

void reverseS(int *a, int left, int right, int number);

void reverseH(int *a, int left, int right, int number);

void moveToEnd(int *a, int n, int k);

void show(int a[], int m);

int main() {
    int m = 10;
    int a[m];

    create(a, m);
    cout << "a before:" << endl;
    show(a, m);

    reverseS(a, 0, m, 4);
    cout << "a after:" << endl;
    show(a, m);

    int b[m];
    cout << "b before:" << endl;
    create(b, m);
    show(b, m);

    reverseH(b, 0, m, 4);
    cout << "b after:" << endl;
    show(b, m);

    int c[m];
    create(c, m);
    cout << "c before:" << endl;
    show(c, m);
    moveToEnd(c, m, 4);
    cout << "c after：" << endl;
    show(c, m);
}

void create(int a[], int m) {
    for (int i = 0; i < m; ++i) {
        a[i] = i;
    }
}

void reverseS(int *a, int left, int right, int number) {
    int t = 0;
    for (int i = left, j = right - 1; i < j; ++i, --j) {
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
}

void reverseH(int *a, int left, int right, int number) {
    int t = 0;
    for (int i = 0, j = right - 1; i < left + number && i < j; ++i, --j) {
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
}

void moveToEnd(int *a, int n, int k) {
    reverseH(a, 0, k , k);
    cout << "c mid" << endl;
    show(a, n);
    reverseH(a, 0, n, k);
}

void show(int a[], int m) {
    for (int i = 0; i < m; ++i) {
        cout << a[i] << "\t";
    }

    cout << endl;
}