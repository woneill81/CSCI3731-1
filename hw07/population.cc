#include "Population.h"
#include <iostream>

Population::Population(){
	this->manyItems = 0;
	this->maxFishes = 30;
	fishes = new Fish*[maxFishes + 1];
}

Population::Population(int max){
	this->manyItems = 0;
	this->maxFishes = max;
	fishes = new Fish*[max + 1];
}

Population::~Population(){
}

void Population::add(Fish* aFish){
	fishes[manyItems] = aFish;
	this->manyItems++;
	
}

void Population::remove(Fish* aFish){
	for(int i = 0; i < manyItems; i++){
		if(fishes[i] == aFish){
			this->manyItems--;
			fishes[i] = fishes[this->manyItems];
			fishes[this->manyItems] = NULL;
			std::cout << "Fish " << i << " died" << std::endl;
		}
	}
	
}

const int Population::size() const{
	return this->manyItems;
}

Fish* Population::get(const int index) const{
	return fishes[index];
}