#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
#define NUMBER 50

int recompile(){
    system("g++ -c main_buble.cpp");
    system("g++ main_buble.o -o graph -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio");
    system("./graph");
    return 0;
}


int main(){
    int i,j, alt[NUMBER];
    float pos = 23, ACpos = 16, ypos = 400, rand1 = 0;
    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode(1500, 580), "graph");
    sf::RectangleShape tower[NUMBER];
    sf::Vector2f temp;
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
        window.display();
        sf::sleep (sf::seconds (1.0f) );
        for(j=0;j<NUMBER-1;j++){
		    for(i=0;i<NUMBER-1;i++){
		    	if(sf::Vector2f(tower[i].getSize()).y > sf::Vector2f(tower[i+1].getSize()).y){
		    		temp = sf::Vector2f(tower[i].getSize());
		    		tower[i].setSize(sf::Vector2f(tower[i+1].getSize()));
		    		tower[i+1].setSize(temp);
                    for(int x = 0;x<NUMBER; x++){
                        window.draw(tower[x]);
                    }
                    window.display();
		    	}
            }
        }
        for(int x = 0;x<NUMBER; x++){
            window.draw(tower[x]);
        }
        window.display();
    }
    return 0;
}
