#include <iostream>

using namespace std;

typedef struct LNode {
    char data;
    struct LNode *next;
} LNode;

void createList(LNode *head);

int main() {
    LNode *p;
    createList(p);

}

void createList(LNode *head) {
    head = (LNode *) malloc(sizeof(LNode));
    head->next = nullptr;
    LNode *p = nullptr;
    int n = 0;
    char ch;
    cout << "ÊäÈëÊý×Ö" << endl;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "ÊäÈë×ÖÄ¸" << endl;
        cin >> ch;
        while (p != nullptr) {
            if (p->data == ch)
                break;
            p = p->next;
        }
        if (p == nullptr) {
            p = (LNode *) malloc(sizeof(LNode));
            p->data = ch;
            p->next = head->next;
            head->next = p;
        }
    }
}



