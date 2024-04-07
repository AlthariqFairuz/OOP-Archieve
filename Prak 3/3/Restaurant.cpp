#include "Restaurant.hpp"

Restaurant::Restaurant(){
 
}

Restaurant :: ~Restaurant(){
 
}

void Restaurant::Push(int val){
    stack<int> temp;
    while (!order.empty()) {
        temp.push(order.top());
        order.pop();
    }
    order.push(val);
    while (!temp.empty()) {
        order.push(temp.top());
        temp.pop();
    }
}

void Restaurant::Pop(int val){
    stack<int> temp;
    if (val > order.size()){
        cout << "Proses tidak valid" << endl;
    }
    else {
        while (!order.empty()) {
            temp.push(order.top());
            order.pop();
        }
        while (val > 0 && !temp.empty()) {
            temp.pop();
            val--;
        }
        while (!temp.empty()) {
            order.push(temp.top());
            temp.pop();
        }
    }
}

void Restaurant::AddMenu(int k, int val){
    stack<int> temp;
    int i = 0;
    while (!order.empty()) {
        temp.push(order.top());
        order.pop();
        i++;
    }
    while (i > k) {
        order.push(temp.top());
        temp.pop();
        i--;
    }

    while (!temp.empty()) {
        order.push(temp.top() + val);
        temp.pop();
    }
}

void Restaurant::Reorder(int k) {
    stack<int> t;
    while (!order.empty()) {
        t.push(order.top());
        order.pop();
    }

    int i = t.size() - k;
    while (i > 0 && !t.empty()) {
        order.push(t.top());
        t.pop();
        i--;
    }

    stack<int> t2;
    while (!t.empty()) {
        t2.push(t.top());
        t.pop();
    }

    while (!t2.empty()) {
        order.push(t2.top());
        t2.pop();
    }
}

ostream& operator<<(ostream& os, Restaurant other) {
    stack<int> temp;
    while (!other.order.empty()) {
        temp.push(other.order.top());
        other.order.pop();
    }
    os << "(";
    while (!temp.empty()) {
        os << temp.top();
        temp.pop();
        if (!temp.empty()) {
            os << ", ";
        }
    }
    os << ")" << endl;
    return os;
}



