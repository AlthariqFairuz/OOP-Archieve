#include <iostream>
using namespace std;


class amba {
    private:
        bool apa;
        int nomor;
        amba *next;
    public:
        amba(int number) {
            apa= false;
            nomor = number;
            next = NULL;           
        }
        void setApa(int number) {
            int i = 0;
            while (i != number){
                i++;
            }
            apa = !apa;
        }
        bool getApa(int i) {
            return;
        }
};

int main () {

    return 0;
}