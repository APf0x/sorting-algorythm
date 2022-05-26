#include <bits/stdc++.h>

int recompile(){
    system("g++ -c main_buble.cpp");
    system("g++ main_buble.o -o graph -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio");
    system("./graph");
    return 0;
}