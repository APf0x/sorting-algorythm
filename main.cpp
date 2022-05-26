#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "main_bubble.h"
#include "recompile.h"
using namespace std;
#define NUMBER 50


int main(){
    int i,j, alt[NUMBER];
    float pos = 23, ACpos = 16, ypos = 400, rand1 = 0;
    srand(time(NULL));
    bubble_main bubble;


    sf::RenderWindow window(sf::VideoMode(1500, 580), "graph");
    
    std::array<sf::RectangleShape, NUMBER> tower;
    sf::Vector2f TowerSize(10.0f, 100.0f);

    for(i=0;i<NUMBER;i++){
        rand1 = (rand()%100)+10;
        TowerSize = sf::Vector2f(20.0f, -rand1);
        tower[i].setFillColor(sf::Color::Blue);
		tower[i].setSize(TowerSize);
        tower[i].setPosition(ACpos, ypos);
        ACpos = ACpos + pos + 1;
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyPressed){
                if(event.key.code == sf::Keyboard::S){
                    window.close();
                    return 0;
                }
                if (event.key.code == sf::Keyboard::C){
                    window.close();
                    recompile();
                    return 0;
                }
            }
        }
        window.clear();
        for(int x = 0;x<NUMBER; x++){
            window.draw(tower[x]);
        }
        sf::sleep (sf::seconds (1.0f) );
        
        bubble.bubble_sort(tower, TowerSize, window); 
        //nice nice nice fuck you and this stupid fucking code its 00;04 am and im done whit this shit go fuck yourself for not studying this shit earlyer do it tommorow with phisics so you have time afterwards + fuck you again why not p===D

        for(int x = 0;x<NUMBER; x++){
            window.draw(tower[x]);
        }
        window.display();
    }
    return 0;
}