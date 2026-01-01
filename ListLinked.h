#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {
private:
	Node<T>* first;
	int n;

public:

	ListLinked() : first(nullptr), n(0) {}
   
	~ListLinked() {
        	Node<T>* aux;
        	while (first != nullptr) {
            		aux = first->next;
            		delete first;
            		first = aux;
        	}
    	}
   
	T operator[](int pos){
        	if (pos < 0 || pos >= n) {
            		throw std::out_of_range("Posición inválida");
        	}
       
        	Node<T>* current = first;
        	for (int i = 0; i < pos; i++) {
            		current = current->next;
        	}
        	return current->data;
    	}
   
	friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list) {
        	out << "[";
        	Node<T>* current = list.first;
        	while (current != nullptr) {
            		out << current->data;
            		if (current->next != nullptr) {
                		out << ", ";
            		}
            		current = current->next;
        	}
        	out << "]";
        	return out;
    	}
   
   
	void insert(int pos, T e) override {
        	if (pos < 0 || pos > n) {
            		throw std::out_of_range("Posición inválida");
        	}
       
        	if (pos == 0) {

            		// Insertar al principio
            		first = new Node<T>(e, first);
        	} else {

            		// Insertar en otra posición
            		Node<T>* prev = first;
            		for (int i = 0; i < pos - 1; i++) {
                		prev = prev->next;
            		}
            		prev->next = new Node<T>(e, prev->next);
        	}
        	n++;
    	}
   
    	void append(T e) const override {
        	insert(n, e);
    	}
   
    	void prepend(T e) const override {
        	insert(0, e);
    	}
   
    	T remove(int pos) override {
        	if (pos < 0 || pos >= n) {
            		throw std::out_of_range("Posición inválida");
        	}
       
        	T data;
        	if (pos == 0) {

            		Node<T>* aux = first;
            		data = aux->data;
            		first = first->next;
            		delete aux;
        	} else {

            		Node<T>* prev = first;
            		for (int i = 0; i < pos - 1; i++) {
                		prev = prev->next;
            		}
            		Node<T>* aux = prev->next;
            		data = aux->data;
            		prev->next = aux->next;
            		delete aux;
        	}
        	n--;
        	return data;
    	}
   
    	T get(int pos) const override {
        	if (pos < 0 || pos >= n) {
            		throw std::out_of_range("Posición inválida");
        	}
       
        	Node<T>* current = first;
        	for (int i = 0; i < pos; i++) {
            		current = current->next;
        	}
        	return current->data;
    	}
   
    	int search(T e) const override {
        	Node<T>* current = first;
        	int pos = 0;
        	while (current != nullptr) {
            		if (current->data == e) {
                		return pos;
            		}
            		current = current->next;
            		pos++;
        	}
        	return -1;
    	}
   
    	bool empty() const override {
        	return n == 0;
    	}
   
    	int size() const override {
        	return n;
    	}
};

#endif
