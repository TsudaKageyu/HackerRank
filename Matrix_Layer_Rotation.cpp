// https://www.hackerrank.com/challenges/matrix-rotation-algo

#include <vector>
#include <iostream>

using namespace std;

int main() {
    int m, n, r;
    cin >> m >> n >> r;
    
    // Read the matrix from STDIN.
    
    vector<int> matrix(m * n);
    for (int y = 0; y < m; ++y) {
        for (int x = 0; x < n; ++x) {
            cin >> matrix[y * n + x];
        }
    }
    
    // Split the matrix into layers.
    
    vector<vector<int>> layers(min(m, n) / 2);
    for (int l = 0; l < min(m, n) / 2; ++l) {
        for (int x = l; x < n - l; ++x)
            layers[l].push_back(matrix[l * n + x]);
        
        for (int y = l + 1; y < m - l - 1; ++y) 
            layers[l].push_back(matrix[y * n + n - 1 - l]);
        
        for (int x = n - l - 1; x >= l; --x)
            layers[l].push_back(matrix[(m - l - 1) * n + x]);
        
        for (int y = m - l - 2; y >= l + 1; --y)
            layers[l].push_back(matrix[y * n + l]);
    }
    
    // Rotate all the layers.
    
    for (auto &layer : layers) {
        const auto it = layer.cbegin() + (r % layer.size());
        vector<int> temp;
        temp.reserve(layer.size());
        temp.insert(temp.end(), it, layer.cend());
        temp.insert(temp.end(), layer.cbegin(), it);
        temp.swap(layer);
    }
    
    // Write back the rotated layers to the matrix.
    
    for (int l = 0; l < min(m, n) / 2; ++l) {
        auto it = layers[l].cbegin();
        for (int x = l; x < n - l; ++x)
            matrix[l * n + x] = *it++;
        
        for (int y = l + 1; y < m - l - 1; ++y) 
            matrix[y * n + n - 1 - l] = *it++;
        
        for (int x = n - l - 1; x >= l; --x)
            matrix[(m - l - 1) * n + x] = *it++;
        
        for (int y = m - l - 2; y >= l + 1; --y)
            matrix[y * n + l] = *it++;
    }
    
    // Print the matrix.
    
    for (int y = 0; y < m; ++y) {
        for (int x = 0; x < n; ++x) {
            cout << matrix[y * n + x] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
