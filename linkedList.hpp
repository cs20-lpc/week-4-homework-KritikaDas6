template <typename T>
linkedList<T>::linkedList()
: head(nullptr), length(0){ }

template <typename T>
linkedList<T>::~linkedList() {
    clear();
}

template <typename T>
linkedList<T>::linkedList(const linkedList<T>& other)
: head(nullptr), length(0) {

    Node* cur = other.head;
    while (cur != nullptr) {
        append(cur->value);
        cur = cur->next;
    }
}

template <typename T>
linkedList<T>& linkedList<T>::operator=(const linkedList<T>& other) {
    if (this == &other) return *this;  
    clear();
    Node* cur = other.head;
    while (cur != nullptr) {
        append(cur->value);
        cur = cur->next;
    }
    return *this;
}

template <typename T>
void linkedList<T>::append(const T& elem) {
    Node* n = new Node(elem);
    if (!head){
        head = n;
        this->length++;
        return;
    } 
    Node *curr = head;
    while (curr->next != nullptr){
        curr = curr->next;
    }
    curr->next = n;
    this->length++;
}



template <typename T>
void linkedList<T>::clear() {
    Node *curr = head;
    while(curr != nullptr){
        Node *nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }
    head = nullptr;
    this->length = 0;
}

template <typename T>
T linkedList<T>::getElement(int position) const {
    if (position < 0 || head == nullptr) {
        throw std::string("getElement: Position is out of bounds or list is empty.");
    }
    Node *curr = head;
    for (int i = 0; i < position; i++){
        curr = curr->next;
    }
    return curr-> value;
    
}

template <typename T>
int linkedList<T>::getLength() const {
    return this->length;
}

template <typename T>
bool linkedList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
void linkedList<T>::remove(int position) {
    if (position < 0 || position >= length) {
        throw std::string("remove: position out of bounds");
    }

    Node* prev = nullptr;
    Node* curr = head;


    for (int i = 0; i < position; ++i) {
        prev = curr;
        curr = curr->next;
    }


    if (prev == nullptr){ 
        head = curr->next;
    } else {
        prev->next = curr->next;
    }
    length--;
    delete curr;

}

template <typename T>
void linkedList<T>::replace(int position, const T& elem) {
    if(position < 0){
        throw std::string("Replace: Position cannot be negative");
    }
    Node *curr = head;
    for (int i = 0; i < position; i++){
        curr = curr-> next;
    }
    curr->value = elem;
}

template <typename T>
ostream& operator<<(ostream& outStream, const linkedList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        typename linkedList<T>::Node* curr = myObj.head;
        while (curr != nullptr) {
            outStream << curr->value;
            if (curr->next != nullptr) {
                outStream << " --> ";
            }
            curr = curr->next;
        }
        outStream << endl;
    }

    return outStream;
}