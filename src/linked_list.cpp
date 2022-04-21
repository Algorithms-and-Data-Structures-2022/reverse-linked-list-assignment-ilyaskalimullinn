#include "assignment/linked_list.hpp"

#include <utility> // swap

namespace assignment {

  /**
   * Переворачивает связный список, используя три указателя.
   *
   * Сложность
   *    по памяти ~ O(1)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseIterative() {
    if (front_ == nullptr) return;
    Node* prev = nullptr;
    Node* curr = front_;
    front_ = back_;
    back_ = curr;

    while (curr != nullptr) {
      Node* next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
  }

  /**
   * Переворачивает связный список, используя рекурсию.
   *
   * Сложность
   *    по памяти ~ O(N)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseRecursive() {
    reverse_recursive_helper(front_, nullptr);
    Node* node = front_;
    front_ = back_;
    back_ = node;
  }

  // вспомогательный метод для реализации рекурсии
  void LinkedList::reverse_recursive_helper(Node*& curr, Node* prev) {
    if (curr == nullptr) return;
    Node* next = curr->next;
    curr->next = prev;

    reverse_recursive_helper(next, curr);
  }

}  // namespace assignment
