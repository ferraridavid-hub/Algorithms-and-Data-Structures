#ifndef SINGLY_LINKED_LIST_HPP
#define SINGLY_LINKED_LIST_HPP

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>

template <typename T> class Singly_Linked_List {
  struct Node {
    T val;
    Node *next;
    Node(T d) : val{d}, next{nullptr} {}
  };

  Node *head;
  size_t sz;

public:
  // default constructor: initilize empty list
  Singly_Linked_List() : head(nullptr), sz{0} {}

  // constructor: initilize list with given node
  Singly_Linked_List(T d) : head{new Node(d)}, sz(1) {}

  // destructor: delete all nodes
  ~Singly_Linked_List() {
    Node *t{head};
    while (head != nullptr) {
      head = head->next;
      delete t;
      t = head;
    }
  }

  // size: return length of the list
  size_t size() { return sz; }

  // empty: return true if list is empty
  bool empty() { return sz == 0; }

  // push_back: append d to the tail of the list
  void push_back(T d) {
    if (sz == 0) {
      head = new Node{d};
      sz++;
      return;
    }

    auto end = new Node{d};
    auto t = head;
    while (t->next != nullptr)
      t = t->next;
    sz++;
    t->next = end;
  }

  // pop_back: remove last element of the list
  // return: value stored in removed node
  T pop_back() {

  }

  // push_front: prepend d to the head of the list
  void push_front(T d) {
    if (sz == 0) {
      head = new Node{d};
      sz++;
      return;
    }

    auto new_node = new Node{d};
    new_node->next = head;
    head = new_node;
    sz++;
  }

  // print: print the list on standard output
  void print() {
    auto n = head;
    std ::cout << "[";
    while (n != nullptr) {
      std ::cout << n->val;
      if (n->next != nullptr)
        std ::cout << ", ";
      n = n->next;
    }
    std ::cout << "]\n";
  }
};

#endif