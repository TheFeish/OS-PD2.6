#include "pch.h"
#include "Dll.h"

void F1(std::chrono::steady_clock::time_point start) {
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Vykdymo laikas: " << duration.count() << "s" << std::endl;
}

void F2() {
    std::string user, time;
    std::cout << "Iveskite vartotojo varda:" << std::endl;
    std::cin >> user;
    std::cout << "Iveskite laiko apribojima:" << std::endl;
    std::cin >> time;
    std::string s = "net user " + user + " /time:" + time;
    system(s.c_str());
}

void F3() {
    std::string l1 = "mkdir Malinauskas";
    system(l1.c_str());
    for (int x = 1; x <= 3; x++) {
        std::string l2 = "mkdir Malinauskas\\Adomas" + std::to_string(x);
        system(l2.c_str());
        for (int y = 1; y <= 3; y++) {
            std::string l3 = "mkdir Malinauskas\\Adomas" + std::to_string(x) + "\\Adomo" + std::to_string(x) + "Adomas" + std::to_string(y);
            system(l3.c_str());
        }
    }
    std::cout << "Sukurti aplankai" << std::endl;
}

void F4(float F, float x0, float x1, float deltax) {
    std::cout << "Pradedamas funkcijos skaiciavimas su F = " << F << std::endl;
    int l2 = 1, l3 = 1;
    std::ofstream file;
    for (float x = x0; x <= x1; x += deltax) {
        float temp = -F + pow(x, 3) + 3 * pow(x, 2);
        if (temp >= 0) {
            std::string ans;
            if (temp != 0) {
                ans = "X: " + std::to_string(x) + " Y: +/-" + std::to_string(sqrt(temp)) + "\n";
            }
            else {
                ans = "X: " + std::to_string(x) + " Y: " + std::to_string(temp) + "\n";
            }
            std::string filePath = "Malinauskas\\Adomas" + std::to_string(l2) + "\\Adomo" + std::to_string(l2) + "Adomas" + std::to_string(l3) + "\\F" + std::to_string(F) + ".txt";
            file.open(filePath, std::ios_base::app);
            file << ans;
            file.close();
            l3++;
            if (l3 > 3) {
                l3 = 1;
                l2++;
                if (l2 > 3) {
                    l2 = 1;
                }
            }
        }
    }
    std::cout << "Baigtas funkcijos skaiciavimas su F = " << F << std::endl;
}

bool F5Sort(std::string i, std::string j) {
    float fi, fj;
    if (i[3] == '-') {
        fi = std::stof(i.substr(3, 9));
    }
    else {
        fi = std::stof(i.substr(3, 8));
    }

    if (j[3] == '-') {
        fj = std::stof(j.substr(3, 9));
    }
    else {
        fj = std::stof(j.substr(3, 8));
    }
    return fi < fj;
}

void F5(float F) {
    std::ifstream input;
    std::vector<std::string> results;
    for (int x = 1; x <= 3; x++) {
        for (int y = 1; y <= 3; y++) {
            std::string filePath = "Malinauskas\\Adomas" + std::to_string(x) + "\\Adomo" + std::to_string(x) + "Adomas" + std::to_string(y) + "\\F" + std::to_string(F) + ".txt";
            input.open(filePath, std::ios_base::app);
            std::string line;
            while (std::getline(input, line))
            {
                results.push_back(line);
            }
            input.close();
        }
    }
    std::sort(results.begin(), results.end(), F5Sort);
    std::ofstream output("F" + std::to_string(F) + ".txt");
    for (auto line : results) {
        output << line << std::endl;
    }
    output.close();
    std::cout << "Baigtas failu rusiavimas su F = " << F << std::endl;
}

void F6() {
    std::string s = "rmdir Malinauskas /s /q";
    system(s.c_str());
    std::cout << "Laikini failai istrinti" << std::endl;
}