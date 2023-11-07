#include <iostream>
#include <string>
using namespace std;


string path;
int n;

int jumps(int pos, int coins) {
    int testCoins = 0, testCoinsCompare = 0;
    for (int i = 1; i<=5; i+=2) {
        if (pos+i >= n) {
            return coins + testCoins;
        }

        cout << pos+i << path[pos + i] << endl;
        
        switch(path[pos + i]) {
            case 'w': continue;
            case '.': testCoinsCompare = jumps(pos+i, coins); break;
            case '"': testCoinsCompare = jumps(pos+i, coins+1); break;
        }
        
        if (testCoinsCompare > testCoins) 
            testCoins = testCoinsCompare;
    }
    return testCoins;
}

int main() {
    cin >> n;
    cin >> path;
    cout << "-" << jumps(0, 0);
    return 1;
}

