#include <iostream>

using namespace std;

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode;

void createListH(LNode *&head);

void createListR(LNode *&head);

bool LocateElemLinkList(LNode *head, int num, int &location);

bool insertElemR(LNode *&head, int num);

bool deleteElem(LNode *&head, int num);

bool reverseByNum(LNode *&head, int num);

bool reverse(LNode * &head);

bool findMin(LNode *head, int &min);

bool merge(LNode *ListA, LNode *ListB, LNode *ListC);

void show(LNode *head);

int main() {
    LNode *head = nullptr;
    createListR(head);
    int min;
    findMin(head, min);
    cout << "min:" << min << endl;

    cout << endl;
    show(head);

    cout << endl;
    int location = 0;
    if (LocateElemLinkList(head, 4, location)) {
        cout << "yes, its location:" << location << endl;
    } else {
        cout << "no" << endl;
    }

    cout << endl;
    reverseByNum(head, 3);
    show(head);

    cout << endl;
    findMin(head, min);
    cout << "min:" << min << endl;

    deleteElem(head, 2);
    show(head);
}

void createListH(LNode *&head) {
    head = (LNode *) malloc(sizeof(LNode));
    head->next = nullptr;
    LNode *p = nullptr;

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        p = (LNode *) malloc(sizeof(LNode));
        p->next = nullptr;
        cin >> p->data;
        p->next = head->next;
        head->next = p;
    }
}

void createListR(LNode *&head) {
    head = (LNode *) malloc(sizeof(LNode));
    head->next = nullptr;
    LNode *p = nullptr;
    LNode *r = head;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        p = (LNode *) malloc(sizeof(LNode));
        p->next = nullptr;
        cin >> p->data;
        p->next = r->next;
        r->next = p;
        r = p;
    }
}

bool LocateElemLinkList(LNode *head, int num, int &location) {
    if (head->next == nullptr)
        return false;
    LNode *p = head;

    while (p->next != nullptr) {
        if (p->data == num)
            return true;
        else{
            location++;
        }
        p = p->next;
    }
    return p->data == num;
}

bool insertElemR(LNode *&head, int num) {
    if (head->next == nullptr)
        return false;

    LNode *p = (LNode *) malloc(sizeof(LNode));
    p->data = num;
    p->next = nullptr;

    while (head->next != nullptr)
        head = p->next;

    head->next = p;
    return true;
}

bool deleteElem(LNode *&head, int num) {
    if (head->next == nullptr)
        return false;

    LNode *p = head;
    LNode *m;

    while (p->next != nullptr) {
        if (p->next->data != num)
            p = p->next;
        else
            break;
    }
    if (p->next == nullptr)
        return false;

    m = p->next;
    p->next = p->next->next;
    free(m);

    return true;
}

bool reverseByNum(LNode *&head, int num)
{
    if(head->next == nullptr)
        return false;

    LNode* t;
    LNode*p = head;
    LNode*r = head;
    while (r->next!= nullptr){
        r = r->next;
    }
    for (int i = 0; i < num; ++i) {
        t=p->next;
        p->next=p->next->next;
        t->next=r->next;
        r->next=t;
    }

    return true;
}

void show(LNode *head)
{
    while (head->next != nullptr){
        cout << head->next->data << "\t";
        head=head->next;
    }
}

bool findMin(LNode *head, int &min)
{
    if(head->next == nullptr)
        return false;
    LNode* p =head;
    min = p->next->data;
    while (p->next != nullptr){
        if(p->next->data<min)
            min = p->next->data;
        p=p->next;
    }

    return true;
}

bool reverse(LNode *&head) {
    if (head->next == nullptr)
        return false;

    LNode *p= head->next;
    LNode *q = nullptr;

    head->next= nullptr;
    while (p!= nullptr) {
        q=p->next;
        p->next = head->next;
        head->next = p;
        p=q;
    }
}