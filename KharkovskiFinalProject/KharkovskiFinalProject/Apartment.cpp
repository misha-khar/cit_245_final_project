#include <iostream>
#include <string>

using namespace std;

class Apartment {
private:
	string nickname;
	double squareFootage;
	double cost;
	double distanceFromCity;
	double neighborhoodGrade;
	double matchScore = 0.0;
public:

	Apartment(string name, double footage, double price, double distance, double grade)
		:nickname{ name }, squareFootage{ footage }, cost{ price }, 
		distanceFromCity{ distance }, neighborhoodGrade{ grade }{
	}

	void setMatchScore(int m) {
		matchScore = m;
	};
	
	void addToMatchScore(int a) {
		matchScore = matchScore + a;
	};

	string getName() {
		return nickname;
	};

	double getFootage() {
		return squareFootage;
	};

	double getCost() {
		return cost;
	};

	double getDistance() {
		return distanceFromCity;
	};

	double getGrade() {
		return neighborhoodGrade;
	};

	double getMatchScore() {
		return matchScore;
	};

	void printDetails() {
		cout << '\n' << "***      " << nickname << "      ***" << '\n';
		cout << "Square Footage: " << squareFootage << " sq. feet" << '\n';
		cout << "Cost: $" << cost << "/month" << '\n';
		cout << "Distance from city: " << distanceFromCity << " miles" << '\n';
		cout << "Neighborhood Grade: " << neighborhoodGrade << '\n';
	};
};