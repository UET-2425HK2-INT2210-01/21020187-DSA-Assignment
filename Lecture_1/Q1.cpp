#include <iostream>

int main() {
    std::string sentence;
    
    // Read a full line from the keyboard
    std::getline(std::cin, sentence);
    
    // Reverse and print the sentence
    for (int i = sentence.length() - 1; i >= 0; i--) {
        std::cout << sentence[i];
    }
    
    std::cout << std::endl;
    return 0;
}
