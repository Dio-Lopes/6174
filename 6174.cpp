#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <limits>
#include <set>
#include <string>

constexpr bool debug = false;
constexpr int kaprekarconstant = 6174;

/*
    Select any four-digit number that has at least two different digits (leading zeros are allowed),
    Create two new four-digit numbers by arranging the original digits in a.) ascending and b.) descending order (adding leading zeros if necessary).
    Subtract the smaller number from the bigger number.
    If the result is not 6174, return to step 2 and repeat.
    https://en.wikipedia.org/wiki/6174
*/

int kaprekarsroutine(int chosenNumDecrescente, int chosenNumCrescente)
{
    return chosenNumDecrescente - chosenNumCrescente;
}

bool temDoisDigitosDiferentes(int n) {
    std::string s = std::to_string(n);
    std::set<char> digitos(s.begin(), s.end());
    return digitos.size() > 1;
}

int main()
{
    std::string chosenNum{};
    while(1)
    {
        // Inserção inicial do número
        std::cout << "Escolhe um número com 4 algarismos, com, pelo menos, dois digitos diferentes!\n";
        std::cin >> chosenNum;

        // Se o número que inseriste conter mais ou menos do que 4 algarismos, ou se o número não conter dois digitos diferentes, reiniciar.
        if (chosenNum.size() != 4 || temDoisDigitosDiferentes(std::stoi(chosenNum)) == false)
        {
            std::cout << "Número inválido!\n\n";
            std::cin.ignore();
        } else 
            break;
    }

    // Algoritmo principal
    int result = std::stoi(chosenNum);
    int iterations{};
    while (result != kaprekarconstant)
    {
        // Separar os digitos do número em strings
        std::string foo = std::to_string(result);
        std::sort(foo.begin(), foo.end());
        int chosenNumCrescente = std::stoi(foo);

        std::sort(foo.begin(), foo.end(), std::greater<int>());
        int chosenNumDecrescente = std::stoi(foo);
        
        result = kaprekarsroutine(chosenNumDecrescente, chosenNumCrescente);
        ++iterations;

    if constexpr (debug) // Verificação de erros
        {
            std::cout << "Número que resultou da operação:              " << result << '\n';
            std::cout << "Número que resultou da operação (Crescente):  " << chosenNumCrescente << '\n';
            std::cout << "Número que resultou da operação (Decrescente):" << chosenNumDecrescente << '\n';
        }
    }

    // Final, com o número total de vezes que fez a operação
    std::cout << "Acabou! O resultado deu: " << result << '\n';
    if (iterations == 1)
        std::cout << "Efetuamos a operação de Kaprekar " << iterations << " vez.\n";
    else 
        std::cout << "Efetuamos a operação de Kaprekar " << iterations << " vezes.\n";

    // Pausa no final do programa
    std::cout << "\nPress any key to exit..";

    std::cin.clear(); // reset any error flags
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any characters in the input buffer until we find a newline
    std::cin.get(); // get one more char from the user (waits for user to press enter)
}