#include <iostream>
#include <fstream>


void packagelist() {
    //only get first page, need to go through every page.
    const char * curl = "curl https://aur.archlinux.org/packages -s -o data.txt > /dev/null";
    std::system(curl);
    std::ifstream getpackages("data.txt");
    std::string line, packages;
    while (getline (getpackages, line)) {
        if (line.find("<a href=\"/packages/") != std::string::npos) {
            line.erase(0,39);
            for (int i=0; i<2; i++) {
                line.erase(line.size()-1);
            }
            packages += line + "\n";
        }
    }
    std::ofstream write(".packagelist");
    write << packages;
    write.close();
    getpackages.close();
    line.clear();
    packages.clear();
    line.clear();
}

void update() {
    ;
}

void upgrade() {
    ;
}

void sync() {
    ;
}

void install () {
    ;
}

int main() {
    packagelist();
}