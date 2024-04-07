#ifndef PRIO_QUEUE_HPP
#define PRIO_QUEUE_HPP

#include <iostream>
#include <vector>
using namespace std;

template<class T>
class PriorityQueue {
    private:
        int size;
        std::vector<T> content;
    public:
    /*
        Default constructor, size = 0
    */
    PriorityQueue(): size(0) {}
    ~PriorityQueue() {}

    /*
        Menambahkan nilai T ke dalam content
    */   
    void Enqueue(T value){
       T t;
       for (int i=0; i < this->content.size(); i++){
           if (this->content[i] <= value){
               t = this->content[i];
               this->content[i] = value;
               value = t;
           }
       }
       this->content.push_back(value);
         this->size++;
    }

    /*
        Mengembalikan nilai pada posisi paling depan dari queue dan menghapus nilai tersebut
        Dijamin PrioriryQueue tidak kosong
    */
    T Dequeue(){
        T temp;
        for (int i = 0; i < this->content.size(); i++){
            if (i == 0){
                temp = this->content[i];
            } else {
                this->content[i-1] = this->content[i];
            }
        }

        this->content.pop_back();
        this->size--;
        return temp;
    }

    /*
        Mengembalikan nilai pada posisi paling depan dari queue
        Dijamin PriorityQueue tidak kosong
    */
    T Front(){
        return content[0];
    }

    /*
        Menambahkan elemen pada priority queue pq ke dalam content
    */
    void MergeQueue(PriorityQueue<T> pq){
        for (int i = 0; i < pq.GetSize(); i++){
            this->Enqueue(pq.content[i]);
        }
    }

    /*
        Mengembalikan banyak data dari priority queue ini
    */
    int GetSize(){
        return this->size;
    }

    /*
        Operator overloading untuk mencetak isi priority queue
        Contoh: (3, 2, 1)
        Apabila kosong, tampilkan ()
    */
    friend ostream& operator<<(ostream& os, PriorityQueue<T> other){
        if (other.size == 0){
            os << "()\n";
        } else {
            os << "(";
            for (int i = 0; i < other.size; i++){
                os << other.content[i];
                if (i != other.size-1){
                    os << ", ";
                }
            }
            os << ")\n";
        }
        return os;
    }


};



#endif