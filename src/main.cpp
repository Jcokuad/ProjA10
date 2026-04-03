// src/main.cpp
#include <iostream>
#include <string>
#include "stackqueue/stack_queue_utils.hpp"

int main() {
    // test your code 
    //Problem 1:
    std::string str1 = "abbaca";
    std::cout << "Input: " << str1 << '\n';
    std::cout << "Output: " << remove_duplicates(str1) << "\n\n";

    //Problem 2:
    std::string str2 = "a<bc<d";
    std::cout << "Input: " << str2 << '\n';
    std::cout << "Output: " << clean_backspace_string(str2) << "\n\n";

    //Problem 3:
    dsac::stackqueue::stack<int> st;
    dsac::stackqueue::queue<int> qu;
    
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    int x = 3;

    std::cout << "Input: " << "st = {1, 2, 3, 4, 5}; q={}; x=3" << '\n';
    std::cout << "Output: " << (stack_contains(st, qu, x) ? "true" : "false") << "\n\n";
}

