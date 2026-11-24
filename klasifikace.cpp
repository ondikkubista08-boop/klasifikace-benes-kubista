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
// 2. Dopředné deklarace funkcí studenta B
double prumerStudenta(const int (&z)[STUDENTI][PREDMETY], int student);
double prumerPredmetu(const int (&z)[STUDENTI][PREDMETY], int predmet);

// 1. Rozšířený výpis tabulky o průměry
void vypisTabulku(const int (&z)[STUDENTI][PREDMETY]) {
    // Nastavení formátování desetinných čísel na 2 místa (náhrada za std::fixed a std::setprecision)
    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);

    // Záhlaví
    std::cout.width(8);
    std::cout << "";
    for (size_t j = 0; j < predmety.size(); ++j) {
        std::cout.width(6);
        std::cout << predmety[j];
    }
    std::cout.width(7); // Šířka 7, aby "prumer" mělo před sebou 1 mezeru
    std::cout << "prumer" << "\n";

    // Řádky se studenty a jejich průměry
    for (size_t i = 0; i < jmena.size(); ++i) {
        std::cout.width(8);
        std::cout << jmena[i];

        for (size_t j = 0; j < predmety.size(); ++j) {
            std::cout.width(6);
            std::cout << z[i][j];
        }

        std::cout.width(7);
        std::cout << prumerStudenta(z, static_cast<int>(i)) << "\n";
    }

    // Poslední řádek s průměry předmětů
    std::cout.width(8);
    std::cout << "prumer";
    for (size_t j = 0; j < predmety.size(); ++j) {
        std::cout.width(6);
        std::cout << prumerPredmetu(z, static_cast<int>(j));
    }
    std::cout << "\n";
}

// 3. Lineární vyhledávání prvního studenta s danou známkou
int prvniStudentSeZnamkou(const int (&z)[STUDENTI][PREDMETY], int znamka) {
    for (size_t i = 0; i < jmena.size(); ++i) {
        for (size_t j = 0; j < predmety.size(); ++j) {
            if (z[i][j] == znamka) {
                return static_cast<int>(i); // Okamžitě vracíme index prvního nalezeného
            }
        }
    }
    return -1; // Nikdo danou známku nemá
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

  int indexPetka = prvniStudentSeZnamkou(znamky, 5);
    if (indexPetka != -1) {
        std::cout << "Prvni s petkou: " << jmena[indexPetka] << "\n";
    } else {
        std::cout << "Nikdo nema petku.\n";
    }

    int indexSestka = prvniStudentSeZnamkou(znamky, 6);
    if (indexSestka != -1) {
        std::cout << "Prvni se sestkou: " << jmena[indexSestka] << "\n";
    } else {
        std::cout << "Znamku 6 nema zadny student.\n";
    }
  
    // --- student B --- 
const char* nazvyPredmetu[PREDMETY] = {"PRG", "MAT", "CJL", "ANJ"};

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
