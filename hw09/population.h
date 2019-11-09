#ifndef POPULATION_H
#define POPULATION_H

class Fish;

class Population {

private:
	int maxFishes;
	Fish** fishes;
	int manyItems;
	
public:
	//no-arg constructor, manyItems = 0, maxFishes = 30
	Population();
	
	//maxFishes = max
	Population(int max);
	virtual ~Population();
	
	//add a fish at the end of the list
	void add(Fish* aFish);
	
	//remove a particular Fish
	void remove(Fish* aFish);
	
	//return size of the list
	const int size() const;
	
	//return pointer to a particular fish index
	Fish* get(const int index) const;

}; //end of Population class

#endif