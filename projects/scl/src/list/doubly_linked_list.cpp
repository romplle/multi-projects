#include <iostream>

#include "doubly_linked_list.hpp"


template<typename T>
KSerikov::DoublyLinkedList<T>::~DoublyLinkedList() noexcept {
    Node* current = begin;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}


template <typename T>
void KSerikov::DoublyLinkedList<T>::push_back(const T& value) noexcept {
    Node* new_end = new Node(value);
    if (begin == nullptr) {
        begin = new_end;
    }
    else {
        end->next = new_end;
        new_end->prev = end;
    }

    end = new_end;
}


template <typename T>
bool KSerikov::DoublyLinkedList<T>::has_item(const T& value) const noexcept {
    Node* current = begin;
    while (current != nullptr) {
        if (current->value == value) {
            return true;
        }

        current = current->next;
    }

    return false;
};


template <typename T>
void KSerikov::DoublyLinkedList<T>::print() const noexcept {
    Node* current = begin;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
};


template <typename T>
bool KSerikov::DoublyLinkedList<T>::remove_first(const T& value) noexcept { // почему bool?
    if (begin == nullptr) {
        return false;
    }

    if (begin->value == value) {
        Node* temp = begin;
        begin = begin->next;
        if (begin != nullptr) {
            begin->prev = nullptr;
        }
        else {
            end = nullptr;
        }

        delete temp;
        return true;
    }

    Node* current = begin->next;
    while (current != nullptr) {
        if (current->value == value) {
            Node* temp = current;
            if (current == end) {
                end = current->prev;
            }
            else {
                current->next->prev = current->prev;
            }

            current->prev->next = current->next;
            delete temp;
            return true;
        }

        current = current->next;
    }

    return false;
};


template <typename T>
std::size_t KSerikov::DoublyLinkedList<T>::size() const noexcept {
    std::size_t size = 0;
    Node* current = begin;
    while (current != nullptr) {
        size++;
        current = current->next;
    }

    return size;
};