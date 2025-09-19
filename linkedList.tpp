template <typename T>
linkedList<T>::linkedList() : head(nullptr), length(0) { }

template <typename T>
linkedList<T>::~linkedList() {
    clear();
}

template <typename T>
linkedList<T>::linkedList(const linkedList<T>& other)
: head(nullptr), length(0) {
    copy(other);
}

template <typename T>
linkedList<T>& linkedList<T>::operator=(const linkedList<T>& other) {
    if (this == &other) return *this;
    clear();
    copy(other);
    return *this;
}

template <typename T>
void linkedList<T>::copy(const linkedList<T>& other) {
    Node* cur = other.head;
    while (cur != nullptr) {
        append(cur->value);
        cur = cur->next;
    }
}

template <typename T>
void linkedList<T>::append(const T& elem) {
    Node* n = new Node(elem);
    if (!head) {
        head = n;
    } else {
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = n;
    }
    length++;
}

template <typename T>
void linkedList<T>::clear() {
    Node* curr = head;
    while (curr != nullptr) {
        Node* nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }
    head = nullptr;
    length = 0;
}

template <typename T>
T& linkedList<T>::getElement(int position) const {
    if (position < 0 || position >= length) {
        throw std::string("getElement: Position out of bounds.");
    }
    Node* curr = head;
    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }
    return curr->value;
}

template <typename T>
int linkedList<T>::getLength() const {
    return length;
}

template <typename T>
void linkedList<T>::insert(int position, const T& elem) {
    if (position < 0 || position > length) {
        throw std::string("insert: Position out of bounds.");
    }
    Node* n = new Node(elem);
    if (position == 0) {
        n->next = head;
        head = n;
    } else {
        Node* curr = head;
        for (int i = 0; i < position - 1; i++) {
            curr = curr->next;
        }
        n->next = curr->next;
        curr->next = n;
    }
    length++;
}

template <typename T>
bool linkedList<T>::isEmpty() const {
    return length == 0;
}

template <typename T>
void linkedList<T>::remove(int position) {
    if (position < 0 || position >= length) {
        throw std::string("remove: Position out of bounds");
    }
    Node* prev = nullptr;
    Node* curr = head;

    for (int i = 0; i < position; ++i) {
        prev = curr;
        curr = curr->next;
    }

    if (prev == nullptr) {
        head = curr->next;
    } else {
        prev->next = curr->next;
    }
    delete curr;
    length--;
}

template <typename T>
void linkedList<T>::replace(int position, const T& elem) {
    if (position < 0 || position >= length) {
        throw std::string("replace: Position out of bounds.");
    }
    Node* curr = head;
    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }
    curr->value = elem;
}

template <typename T>
ostream& operator<<(ostream& outStream, const linkedList<T>& myObj) {
    typename linkedList<T>::Node* curr = myObj.head;
    while (curr != nullptr) {
        outStream << curr->value;
        if (curr->next != nullptr) {
            outStream << " --> ";
        }
        curr = curr->next;
    }
    return outStream;
}
