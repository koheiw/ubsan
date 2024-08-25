
#include <Rcpp.h>
#include <iostream>
using namespace Rcpp;


// source
// https://stackoverflow.com/questions/46836809/clang-and-clang-with-asan-generate-different-output

// [[Rcpp::export]]
void memory_leak() {

    std::cout << "Started Program\n";
    int* i = new int(); 
    *i = 42;
    std::cout << "Expected i: " << *i << std::endl;
}

// [[Rcpp::export]]
void has_asan() {
#if defined(__clang__)
#if __has_feature(address_sanitizer) //clang
    std::cout << "Has address_sanitiezer (clang)\n";
#endif
#else
#if defined(__SANITIZE_ADDRESS__) // gcc
    std::cout << "Has address_sanitiezer (gcc)\n";
#endif
#endif
}
