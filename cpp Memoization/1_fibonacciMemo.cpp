#include <iostream>
#include <unordered_map>

// Time = O(n)
// Space = O(n)

long long int helper(int n, std::unordered_map<int, long long int>& umap){
    if(umap.find(n) != umap.end()) return umap[n];
    if(n <= 2) return 1;

    umap[n] = helper(n-1, umap) + helper(n-2, umap);
    return umap[n];
}

long long int fibonacci(int n){
    std::unordered_map<int, long long int> umap;
    return helper(n, umap);
}

int main(int argc, const char** argv) {
    std::cout <<  fibonacci(6) << std::endl;       
    std::cout <<  fibonacci(7) << std::endl;       
    std::cout <<  fibonacci(8) << std::endl;    
    std::cout <<  fibonacci(50) << std::endl;    
    return 0;
}