#include <iostream>
using namespace std;

class DoublyLinkedList {
private:
    // Wezel listy przechowywany na stercie
    struct Node {
        int data;
        Node* prev;
        Node* next;

        Node(int value)
            : data(value), prev(nullptr), next(nullptr) {
        }
    };

    // Wzorzec Factory - tworzenie wezlow
    class NodeFactory {
    public:
        static Node* createNode(int value) {
            return new Node(value);
        }
    };

    Node* head;
    Node* tail;
    int count;

public:
    // Iterator do przechodzenia po liscie
    class Iterator {
    private:
        Node* current;
        Node* tailNode;

        friend class DoublyLinkedList;

        Iterator(Node* node, Node* tail)
            : current(node), tailNode(tail) {
        }

    public:
        int& operator*() const {
            return current->data;
        }

        Iterator& operator++() {
            if (current != nullptr) {
                current = current->next;
            }
            return *this;
        }

        Iterator& operator--() {
            if (current != nullptr) {
                current = current->prev;
            }
            else {
                current = tailNode;
            }
            return *this;
        }

        bool operator==(const Iterator& other) const {
            return current == other.current;
        }

        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }
    };

    DoublyLinkedList()
        : head(nullptr), tail(nullptr), count(0) {
    }

    // Kopiowanie wylaczone - unikamy plytkiej kopii wskaznikow
    DoublyLinkedList(const DoublyLinkedList&) = delete;
    DoublyLinkedList& operator=(const DoublyLinkedList&) = delete;

    // Destruktor zwalnia wszystkie wezly
    ~DoublyLinkedList() {
        clear();
    }

    // Dodawanie na koncu
    void pushBack(int value) {
        Node* node = NodeFactory::createNode(value);

        node->prev = tail;

        if (tail != nullptr) {
            tail->next = node;
        }
        else {
            head = node;
        }

        tail = node;
        ++count;
    }

    // Dodawanie na poczatku
    void pushFront(int value) {
        Node* node = NodeFactory::createNode(value);

        node->next = head;

        if (head != nullptr) {
            head->prev = node;
        }
        else {
            tail = node;
        }

        head = node;
        ++count;
    }

    // Usuwanie pierwszego wystapienia wartosci
    bool remove(int value) {
        Node* current = head;

        while (current != nullptr &&
            current->data != value) {
            current = current->next;
        }

        if (current == nullptr) {
            return false;
        }

        if (current->prev != nullptr) {
            current->prev->next = current->next;
        }
        else {
            head = current->next;
        }

        if (current->next != nullptr) {
            current->next->prev = current->prev;
        }
        else {
            tail = current->prev;
        }

        delete current;
        --count;
        return true;
    }

    // Usuwanie wszystkich elementow
    void clear() {
        Node* current = head;

        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }

        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    int size() const {
        return count;
    }

    bool empty() const {
        return head == nullptr;
    }

    // Poczatkowy i koncowy iterator
    Iterator begin() {
        return Iterator(head, tail);
    }

    Iterator end() {
        return Iterator(nullptr, tail);
    }

    // Wyswietlanie od poczatku do konca
    void printForward() {
        for (Iterator it = begin(); it != end(); ++it) {
            cout << *it << " ";
        }
        cout << '\n';
    }

    // Wyswietlanie od konca do poczatku
    void printBackward() {
        Iterator it = end();

        while (it != begin()) {
            --it;
            cout << *it << " ";
        }

        cout << '\n';
    }
};

int main() {
    DoublyLinkedList list;

    list.pushBack(10);
    list.pushBack(20);
    list.pushBack(30);
    list.pushFront(5);

    cout << "Lista od poczatku: ";
    list.printForward();

    cout << "Lista od konca: ";
    list.printBackward();

    cout << "Liczba elementow: "
        << list.size() << '\n';

    cout << "Usuwanie elementu 20...\n";
    list.remove(20);

    cout << "Po usunieciu: ";
    list.printForward();

    cout << "Dodawanie elementu 15...\n";
    list.pushBack(15);

    cout << "Aktualna lista: ";
    list.printForward();

    cout << "Czyszczenie listy...\n";
    list.clear();

    cout << "Czy lista jest pusta? "
        << (list.empty() ? "Tak" : "Nie") << '\n';

    return 0;
}
