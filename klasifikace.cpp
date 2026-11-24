#include <iostream> 

#include <iomanip>     // std::setw, std::setprecision 

#include <array> 

#include <string> 

#include <algorithm>   // std::sort 

  

const int STUDENTI = 6; 

const int PREDMETY = 4; 

  

std::array<std::string, STUDENTI> jmena = {"Adam", "Eva", "Jan", "Lucie", "Marek", "Petra"}; 

std::array<std::string, PREDMETY> predmety = {"PRG", "MAT", "CJL", "ANJ"}; 

  

int znamky[STUDENTI][PREDMETY] = { 

    {1, 2, 3, 1}, 

    {2, 2, 1, 1}, 

    {3, 4, 2, 3}, 

    {1, 1, 1, 2}, 

    {5, 3, 4, 4}, 

    {2, 3, 2, 2} 

}; 

  

// ===== Funkce – student A ===== 
void vypisTabulku(const int (&z)[STUDENTI][PREDMETY]) {
    // Prázdné místo v levém horním rohu
    std::cout.width(8);
    std::cout << "";

    // Výpis záhlaví
    for (size_t j = 0; j < predmety.size(); ++j) {
        std::cout.width(6);
        std::cout << predmety[j];
    }
    std::cout << "\n";

    // Výpis řádků se studenty
    for (size_t i = 0; i < jmena.size(); ++i) {
        std::cout.width(8);
        std::cout << jmena[i];

        for (size_t j = 0; j < predmety.size(); ++j) {
            std::cout.width(6);
            std::cout << z[i][j];
        }
        std::cout << "\n";
    }
}

  

// ===== Funkce – student B ===== 
double prumerStudenta(const int (&z)[STUDENTI][PREDMETY], int student) {
    int soucet = 0;
    for (int j = 0; j < PREDMETY; ++j) {
        soucet += z[student][j];
    }
    return static_cast<double>(soucet) / PREDMETY;
}

double prumerPredmetu(const int (&z)[STUDENTI][PREDMETY], int predmet) {
    int soucet = 0;
    for (int i = 0; i < STUDENTI; ++i) {
        soucet += z[i][predmet];
    }
    return static_cast<double>(soucet) / STUDENTI;
}
  

int main() { 

    // --- student A --- 
    vypisTabulku(znamky);
  
    // --- student B --- 
const char* nazvyPredmetu[PREDMETY] = {"PRG", "MAT", "CJL", "ANJ"};

    // 3. Kontrolní výpis (před další částí úkolu smaž)
    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Prumery studentu:\n";
    for (int i = 0; i < STUDENTI; ++i) {
        std::cout << "Student " << (i + 1) << ": " << prumerStudenta(z, i) << '\n';
    }

    std::cout << "\nPrumery predmetu:\n";
    for (int j = 0; j < PREDMETY; ++j) {
        std::cout << nazvyPredmetu[j] << ": " << prumerPredmetu(z, j) << '\n';
    }

    return 0;
} 
