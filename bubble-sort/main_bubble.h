#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#define NUMBER 50

class bubble_main{
private:
    sf::Vector2f temp;
public:
    int bubble_sort(std::array<sf::RectangleShape, NUMBER> tower, sf::Vector2f TowerSize, sf::RenderWindow& window){
        // .getGlobalBounds().height
        for(int j=0;j<NUMBER-1;j++){
		    for(int i=0;i<NUMBER-1;i++){
		    	if(tower[i].getGlobalBounds().height > tower[i+1].getGlobalBounds().height){
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
        return 0;
    }
};

