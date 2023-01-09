#include <iostream>

using namespace std;

pair<int*, int>input() {
    int* array = new int[100000];
    int i = 0;
    int x;
    while (i < 100000) {
        cin >> x;
        if (x == 0) 
            break;
        array[i] = x;
        i++;
    }
    return { array, i };
}

pair<int*, int> min_five(int* array, int N) {
    int k = 0;
    for (int i = 0; i < N; i++) {
        if (array[i] < 5) k++;
    }
    int* array2 = new int[k];
    int j = 0;
    for (int i = 0; i < N; i++) {
        if (array[i] < 5) {
            array2[j] = array[i];
            j++;
        }
    }
    return { array2, k };
}

void main() {
    auto T = input();
    for (int i = 0; i < T.second; i++) 
        cout << T.first[i] << " ";
    auto arr2 = min_five(T.first, T.second);
    cout << endl;
    for (int i = 0; i < arr2.second; i++) 
        cout << arr2.first[i] << " ";

}