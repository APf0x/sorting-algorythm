#include <bits/stdc++.h>

int recompile(){
    system("g++ -c main.cpp");
    system("g++ main.o -o graph -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio");
    system("./graph");
    return 0;
}