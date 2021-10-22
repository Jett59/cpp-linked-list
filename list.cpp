#include <iostream>
#include <memory>

using std::shared_ptr;
using std::cout;
using std::endl;
using std::make_shared;
using std::weak_ptr;

template<typename t>
class LinkedList;

template<typename t>
class LinkedListElement {
protected:
shared_ptr<t> element;
weak_ptr<LinkedListElement<t>> previous;
shared_ptr<LinkedListElement> next;
operator t () {
return *element;
}
LinkedListElement<t>& operator=(LinkedListElement<t>& other) {
element = other.element;
previous = other.previous;
next = other.next;
return *this;
}
LinkedListElement& operator=(t value) {
*element = value;
return *this;
}
public:
LinkedListElement(shared_ptr<t> element, weak_ptr<LinkedListElement<t>> previous, shared_ptr<LinkedListElement<t>> next) : element(element), previous(previous), next(next) {
cout << "Creating a linked list element" << endl;
}
~LinkedListElement () {
cout << "Destroying the linked list element" << endl;
}
friend class LinkedList<t>;
};

template<typename t>
class LinkedList {
private:
shared_ptr<LinkedListElement<t>> head, tail;
public:
LinkedList() : head(shared_ptr<LinkedListElement<t>>(new LinkedListElement<t>(make_shared<t>(), weak_ptr<LinkedListElement<t>>(), shared_ptr<LinkedListElement<t>>()))), tail(head) {
cout << "Creating the linked list" << endl;
}
~LinkedList () {
cout << "Destroying the linked list" << endl;
}
t get (int index) {
cout << "Getting" << endl;
shared_ptr<LinkedListElement<t>> element = head;
for (int i = 0; i < index; i ++) {
element = element->next;
}
return element;
}
void set (int index, t value) {
cout << "Setting" << endl;
shared_ptr<LinkedListElement<t>> element = head;
for (int i = 0; i < index; i ++) {
element = element->next;
}
*element = value;
}
void add (t value) {
cout << "Adding" << endl;
shared_ptr<LinkedListElement<t>> element = head;
while (element->next != nullptr) {
element = element->next;
}
element->next = shared_ptr<LinkedListElement<t>>(new LinkedListElement<t>(make_shared<t>(), element, shared_ptr<LinkedListElement<t>>()));
*element->next->element = value;
tail = element->next;
}
};

int main () {
LinkedList<int> theList;
theList.set(0, 10);
theList.add(20);
return 0;
}
