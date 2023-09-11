#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep) {
    while (node) {
        cout << node->data;

        node = node->next;

        if (node) {
            cout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* node1 = head1;
    SinglyLinkedListNode* node2 = head2;
    SinglyLinkedListNode* zeroNode = new SinglyLinkedListNode(0);
    SinglyLinkedListNode* firstNode = new SinglyLinkedListNode(0);
    SinglyLinkedListNode* currentNode = firstNode;
    while(node1 != zeroNode && node2 != zeroNode) {
        SinglyLinkedListNode* nextNode = new SinglyLinkedListNode(0);
        currentNode->next = nextNode;
        if(node1->next == nullptr && node1->data != 0 && node1->data <= node2->data) {
            currentNode->next = node2;
            currentNode->data = node1->data;
            node1 = zeroNode;
            node2 = zeroNode;
        } else if(node2->next == nullptr && node2->data != 0 && node1->data > node2->data){
            currentNode->next = node1;
            currentNode->data = node2->data;
            node1 = zeroNode;
            node2 = zeroNode;
        } else {
            if(node1->data <= node2->data) {
                currentNode->data = node1->data;
                node1 = node1->next;
            } else if(node1->data > node2->data) {
                currentNode->data = node2->data;
                node2 = node2->next;
            }
        }
        currentNode = nextNode;
    }
    return firstNode;
}

int main()
{
    string t_tests;
    getline(cin, t_tests);
    int tests = stoi(ltrim(rtrim(t_tests)));

    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
        SinglyLinkedList* llist1 = new SinglyLinkedList();

        string t_llist1_count;
        getline(cin, t_llist1_count);
        int llist1_count = stoi(ltrim(rtrim(t_llist1_count)));

        for (int i = 0; i < llist1_count; i++) {
            string t_llist1_item;
            getline(cin, t_llist1_item);
            int llist1_item = stoi(ltrim(rtrim(t_llist1_item)));

            llist1->insert_node(llist1_item);
        }
      
        SinglyLinkedList* llist2 = new SinglyLinkedList();

        string t_llist2_count;
        getline(cin, t_llist2_count);
        int llist2_count = stoi(ltrim(rtrim(t_llist2_count)));

        for (int i = 0; i < llist2_count; i++) {
            string t_llist2_item;
            getline(cin, t_llist2_item);
            int llist2_item = stoi(ltrim(rtrim(t_llist2_item)));

            llist2->insert_node(llist2_item);
        }

        SinglyLinkedListNode* llist3 = mergeLists(llist1->head, llist2->head);

        print_singly_linked_list(llist3, " ");
        cout << "\n";

        free_singly_linked_list(llist3);
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), [](unsigned char c) { return !ispunct(c); })
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), [](unsigned char c) { return !ispunct(c); }).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}