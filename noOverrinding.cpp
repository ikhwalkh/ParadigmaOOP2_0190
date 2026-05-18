#include <iostream>
using namespace std;

class baseClass {
    public:
        virtual void perkenalan() final{
            cout << "Halo saya Fuction dari base Class";
        }
};
class derivedClass : public baseClass {
    public:
       void perkenalan1() {
        cout << "Halo saya fuction dari devired Class";
       }
};
int main() {
    derivedClass a;
    a.perkenalan1();

    return 0;
}