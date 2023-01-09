#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void write_vector(const vector<vector<T>> &V)
{
    cout << "The numbers in the vector are: " << endl;
    for (int i = 0; i < V.size(); i++)
    {
        for (int j = 0; j < V[i].size(); j++)
            cout << V[i][j] << " ";
        cout << endl;
    }
}

void main()
{
    int input;
    vector<int> V; //ââîäèì äàííûå â âåêòîð
    vector<int>::iterator vec1;
    vector<int> vec2;
    vector<vector<int>> vec;

    cout << "Enter your numbers: " << endl;
    while (cin >> input)
        V.push_back(input);

    sort(V.begin(), V.end());  //ñîðòèðîâêà äàííûõ

    vec.push_back(V);  // çàïîëíèëè 0 èíäåêñ âåêòîðà

    vec1 = unique(vec[0].begin(), vec[0].end()); 
    vec[0].erase(vec1, vec[0].end()); //âåêòîð óíèêàëüíûõ ÷èñåë

    for (vector<int>::iterator vec_it = V.begin(), next; vec_it != V.end(); vec_it = next)
    {
        next = upper_bound(vec_it, V.end(), *vec_it);
        vec2.push_back(distance(vec_it, next));  // âåêòîð êîëè÷åñòâà 
    }

    vec.push_back(vec2);

    write_vector(vec);
}
