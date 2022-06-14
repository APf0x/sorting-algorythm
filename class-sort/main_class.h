#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <iostream>
#define NUMBER 50

class main_class{
private:
    sf::Vector2f temp;
    void swap(std::array<sf::RectangleShape, NUMBER>& tower, int a, int b){
        temp = sf::Vector2f(tower[a].getSize());
	    tower[a].setSize(sf::Vector2f(tower[b].getSize()));
	    tower[b].setSize(temp);
    }
    int partition(std::array<sf::RectangleShape, NUMBER>& tower, int low, int high){
        float pivot = tower[high].getGlobalBounds().height;
        int i = (low - 1);
        for(int j=low; j<high; j++){
            if(tower[j].getGlobalBounds().height <= pivot){
                i++;
                swap(tower, i, j);
            }
        }
        swap(tower, i+1, high);
        return (i + 1);
    }

public:
    void buble_sort(std::array<sf::RectangleShape, NUMBER>& tower, sf::RenderWindow& window);
    void quicksort(std::array<sf::RectangleShape, NUMBER>& tower, sf::RenderWindow& window, int low, int high);
};


void main_class::buble_sort(std::array<sf::RectangleShape, NUMBER>& tower, sf::RenderWindow& window){
    // .getGlobalBounds().height
    for(int j=0;j<NUMBER-1;j++){
	    for(int i=0;i<NUMBER-1;i++){
	    	if(tower[i].getGlobalBounds().height > tower[i+1].getGlobalBounds().height){
	    		temp = sf::Vector2f(tower[i].getSize());
	    		tower[i].setSize(sf::Vector2f(tower[i+1].getSize()));
	    		tower[i+1].setSize(temp);
                window.clear();
                for(int x = 0;x<NUMBER; x++){
                    window.draw(tower[x]);
                }
                window.display();
	    	}
        }
    }
}

void main_class::quicksort(std::array<sf::RectangleShape, NUMBER>& tower, sf::RenderWindow& window, int low, int high){
    int pi = partition(tower, 0, high);
    main_class::quicksort(tower, window, low, pi-1);
    main_class::quicksort(tower, window, pi+1, high);
}