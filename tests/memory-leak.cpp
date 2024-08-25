// g++ -o memory-leak memory-leak.cpp -fsanitize=address -fno-omit-frame-pointer -g
// clang++ -o memory-leak memory-leak.cpp -fsanitize=address -fno-omit-frame-pointer -g

#include <iostream>
int main() {
#if defined(__clang__)
#if __has_feature(address_sanitizer) //clang
    std::cout << "Has address_sanitiezer (clang)\n";
#endif
#else
#if defined(__SANITIZE_ADDRESS__) // gcc
    std::cout << "Has address_sanitiezer (gcc)\n";
#endif
#endif
    std::cout << "Started Program\n";
    int* i = new int(); 
    *i = 42;
    std::cout << "Expected i: " << *i << std::endl;
}
