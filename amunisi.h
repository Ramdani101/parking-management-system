#ifndef AMUNISI_H
#define AMUNISI_H

#include <iostream>
using namespace std;

template <typename T>
class StackWannabe {
private:
    struct listNode {
        T val;
        listNode* next;
        listNode() : val(T()), next(nullptr) {}
        listNode(T x) : val(x), next(nullptr) {}
        listNode(T x, listNode* next) : val(x), next(next) {}
    };

    listNode* head;  
    listNode* back;  
    listNode* bantu; 

public:
    StackWannabe() {
        head = nullptr;
        back = nullptr;
    }

    bool isEmpty(){
        if(head == nullptr){
            return true;
        }else{
            return false;
        }
    }

    void pushIn(T newVal) {
        listNode* newNode = new listNode(newVal); 
        newNode->next = head; 
        head = newNode;       
        if(head->next == nullptr){
            back = head;
        }else{}
    }

    void popOut() {
        if (head == nullptr) {
            cout << "Stack masih kosong" << endl;
            return;
        }
        listNode* hapus = head; 
        head = head->next;      
        delete hapus;           
    }

    T getFront() {
        if (head == nullptr) {
            cout << "Stack Masih Kosong" << endl;
            return T(); // Nilai default untuk tipe T
        }
        return head->val; // Kembalikan nilai front
    }

    T getBack() {
        if (back == nullptr) {
            cout << "Stack Masih kosong" << endl;
            return T(); // Nilai default untuk tipe T
        }
        return back->val; // Kembalikan nilai back
    }
    
    void printStack() {
        bantu = head;
        while (bantu != nullptr) { 
            cout << bantu->val << " " << endl;
            bantu = bantu->next;
        }
    }
};


template <typename T>
class QueueWannabe{
private :
    struct listNode {
        T val;
        listNode* next;
        listNode() : val(T()), next(nullptr) {}
        listNode(T x) : val(x), next(nullptr) {}
        listNode(T x, listNode* next) : val(x), next(next) {}
    };

    listNode* head;  
    listNode* back;  
    listNode* bantu; 

public :
    QueueWannabe() {
        head = nullptr;
        back = nullptr;
    }

    bool isEmpty(){
        if(head == nullptr){
            return true;
        }else{
            return false;
        }
    }

    void pushIn(T newVal) {
        listNode* newNode = new listNode(newVal); 
        if(head==nullptr){
            head = newNode;
            newNode->next = nullptr;
            back = head;
        }
        back->next = newNode;
        back = newNode;
        back->next = nullptr;
        
    }

    void popOut() {
        if (head == nullptr) {
            cout << "Stack masih kosong" << endl;
            return;
        }
        listNode* hapus = head;
        head = head->next;      
        delete hapus;           
    }

    T getFront() {
        if (head == nullptr) {
            cout << "Stack Masih Kosong" << endl;
            return T();
        }
        return head->val; 
    }

    T getBack() {
        if (back == nullptr) {
            cout << "Stack Masih kosong" << endl;
            return T(); // Nilai default untuk tipe T
        }
        return back->val;
    }

    void printQueue() {
        bantu = head;
        while (bantu != nullptr) { 
            cout << bantu->val << " " << endl;
            bantu = bantu->next;
        }
    }
    
};


#endif