#include<iostream>
#include<string>

int main(){
    std::string something; // Declaration of string type variable.

    std::cout << "Write something!" << std::endl;
    std::cin >> something;
    std::cout << "You have written that " << something << std::endl;
}