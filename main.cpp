#include <iostream>

using namespace std;
#include "capteurTemperature.h"


int main() {
    try {
        capteurTemperature c1("es",2);
        cout << *(c1.nom) << endl;
    } catch( invalid_argument e) {
        cout << e.what() << endl;
    }
    catch( invalid_argument * pe) {
        cout << pe->what() << endl;
        delete pe;
    }
    catch (int i) {
        cout << i << endl;
    }
    return 0;
}
