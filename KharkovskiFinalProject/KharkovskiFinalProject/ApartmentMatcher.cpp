/*
Misha Kharkovksi
Final project
Program matches apartment to user given certain preferences

resources:
sorting code from:
https://www.educative.io/edpresso/how-to-sort-a-map-by-value-in-cpp

bubble sort help:
https://stackoverflow.com/questions/18838742/bubblesort-vector

*/

#include <iostream>
#include <string>
#include <vector>
#include "Apartment.cpp"
// #include "UserSpecs.cpp"
#include "Parameters.cpp"
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

// defines a vector in which to store our apartments
// vector<Apartment> apartments;

char paramTypes[4] = { 'f', 'c', 'd', 'g' };
// const double SCORE_MULTIPLIER = 1.05;

vector<Apartment*> createSampleApartments() {

    vector<Apartment*> a;

    a.push_back(new Apartment("alpha", 850, 1500, 15, 90));
    a.push_back(new Apartment("bravo", 900, 1500, 5, 85));
    a.push_back(new Apartment("chalie", 700, 1000, 10, 60));
    a.push_back(new Apartment("delta", 900, 1000, 20, 80));
    a.push_back(new Apartment("echo", 600, 850, 12, 95));
    a.push_back(new Apartment("foxtrot", 900, 1500, 3, 98));

    return a;
}

Parameter createDefaultParams() {
    Parameter p = Parameter(900,1, 1500,2, 15,3, 90, 4);
    return p;
}

Parameter createCustomParams() {
    double f, c, d, g;
    int fi, ci, di, gi;
    cout << "Please enter a target square footage: ";
    cin >> f;
    cout << "Please enter an importance level for footage (1-4, 1 being most important): ";
    cin >> fi;

    cout << "Please enter a target cost: ";
    cin >> c;
    cout << "Please enter an importance level for cost (1-4, 1 being most important): ";
    cin >> ci;

    cout << "Please enter a target distance to city: ";
    cin >> d;
    cout << "Please enter an importance level for distance (1-4, 1 being most important): ";
    cin >> di;

    cout << "Please enter a target neighborhood grade: ";
    cin >> g;
    cout << "Please enter an importance level for neighborhood grade (1-4, 1 being most important): ";
    cin >> gi;
    
    
    Parameter p = Parameter(f, fi, c, ci, d, di, g, gi);
    return p;
}

// function to tes user input and make sure it is valid
bool menuOptionCheck(char input) {
    // char array that stores valid menu options
    char validMenuOptions[] = { 'Q', 'D', 'S', 'U', 'M', 'E' };
    // loops through array of validMenuOptions and compares user input against validMenuOptions
    for (int i = 0; i < sizeof(validMenuOptions); i = i + 1) {
        // if the user input matches one of the acceptable options, returns true
        if (input == validMenuOptions[i]) {
            return true;
        }
    }
    return false;
}

// function tha assists in sort algorithm
bool compareDifference(const pair<Apartment*, double>& a, const pair<Apartment*, double>& b){
    return (a.second < b.second);
}

void checkParams(vector<Apartment*> &a, Parameter &p, double importanceCoefficient, char paramMarker) {
    const double SCORE_MULTIPLIER = 1.05;
    
    cout << '\n' << "Checking parameters..." << '\n';

    // initializes map for holding differences
    map<Apartment*, double> differenceMap;
    // loops thru and adds apartment with its difference to the map
   
    switch (paramMarker) {
    case 'f':
        for (int i = 0; i < a.size(); i++) {
            differenceMap.insert(pair<Apartment*, double>(a.at(i), abs(a.at(i)->getFootage() - p.getParameter(paramMarker))));
        }
        break;
    case 'c':
        for (int i = 0; i < a.size(); i++) {
            differenceMap.insert(pair<Apartment*, double>(a.at(i), abs(a.at(i)->getCost() - p.getParameter(paramMarker))));
        }
        break;
    case 'd':
        for (int i = 0; i < a.size(); i++) {
            differenceMap.insert(pair<Apartment*, double>(a.at(i), abs(a.at(i)->getDistance() - p.getParameter(paramMarker))));
        }
        break;
    case 'g':
        for (int i = 0; i < a.size(); i++) {
            differenceMap.insert(pair<Apartment*, double>(a.at(i), abs(a.at(i)->getGrade() - p.getParameter(paramMarker))));
        }
        break;
    }

    // needed to be a vector type for sorting algorithm
    vector<pair<Apartment*, double>> vecDiffMap;
    map<Apartment*, double> ::iterator it2;
    // transfers each element of diffMap to a vector of the same contents
    for (it2 = differenceMap.begin(); it2 != differenceMap.end(); it2++)
    {
        vecDiffMap.push_back(make_pair(it2->first, it2->second));
    }
    // sorts the vector of differences
    sort(vecDiffMap.begin(), vecDiffMap.end(), compareDifference);

    // simple display 
    //for (int i = 0; i < vecDiffMap.size(); i++) {
    //    cout << vecDiffMap[i].first << ": " << vecDiffMap[i].second << '\n';
    //}

    // loops thru vecDiffMap and adds points appropriately
    // outer loops goes thru vecDiffMap values
    for (int i = 0; i < vecDiffMap.size(); i++) {
        // inner loops used to go thru apartment list to compare values
        for (int j = 0; j < a.size(); j++) {
            if (vecDiffMap[i].first == a.at(j)) {
                if (vecDiffMap[i].second == 0) {
                    a.at(j)->addToMatchScore(0);
                }
                else {
                    a.at(j)->addToMatchScore((i * SCORE_MULTIPLIER) * (10.0 * importanceCoefficient));
                }
 //               a.at(j)->addToMatchScore((i * SCORE_MULTIPLIER) * (10.0 * importanceCoefficient));
                cout << "Apartment " << a.at(j)->getName() << " match score: " << a.at(j)->getMatchScore() << '\n';
            }
        }
    }
}

void criteriaChecker(vector<Apartment*> &a, Parameter &p) {
    
    for (double i = 1; i <= p.getImportanceMapSize(); i++) {
        switch (p.getImportanceParam(i)) {
        case 'f':
            checkParams(a, p, 1/i, 'f');
            //checkFootage(a, p, i);
            break;
        case 'c':
            checkParams(a, p, 1/i, 'c');
            //checkCost(a, p, i);
            break;
        case 'd':
            checkParams(a, p, 1/i, 'd');
            //checkDistance(a, p, i);
            break;
        case 'g':
            checkParams(a, p, 1/i, 'g');
            //checkGrade(a, p, i);
            break;
        }
    }

}

void displayApartments(vector<Apartment*> a) {
    for (int i = 0; i < a.size(); i++) {
        a[i]->printDetails();
    }
}

void displayBestOptions(vector<Apartment*> a) {
    cout << '\n' << "***   Best Option   ***" << '\n';
    
    for (int i = 0; i < a.size(); i++) {
        cout << i + 1 << ") " << a[i]->getName() << '\n';
    }
    cout << "***   Worst Option   ***" << '\n';
}

// function to accept unsorted apartment list and sort that list by match score
void sortApartments(vector<Apartment*> &unsortedA) {
    sort(unsortedA.begin(), unsortedA.end(), [](Apartment* a, Apartment* b){
        return b->getMatchScore() > a->getMatchScore(); }
    );
}

void menuNav(vector<Apartment*>& apartments, Parameter newSpecs) {
    // variable to store user input
    char input;
    do {
        do {
            cout << "_____________________________________________" << '\n';
            cout << "|                                           |" << '\n';
            cout << "|----------------Dumb Zillow----------------|" << '\n';
            cout << "|------------------ MENU -------------------|" << '\n';
            cout << "| Type 'Q' to quick load data               |" << '\n';
            cout << "| Type 'D' to display all apartment options |" << '\n';
            cout << "| Type 'U' to input search parameters       |" << '\n';
            cout << "| Type 'S' to display search parameters     |" << '\n';
            cout << "| Type 'M' to find potential matches        |" << '\n';
            cout << "| Type 'E' to exit the program              |" << '\n';
            cout << "|___________________________________________|" << '\n' << '\n';
            cout << "PLease enter a menu option: ";
            cin >> input;
            // converts user input to uppercase for consistent testing
            input = toupper(input);
            // selects proper menu option based on user input
            switch (input) {
            case 'Q':
                cout << "You selected quick load data" << '\n';
              
                apartments = createSampleApartments();
                newSpecs = createDefaultParams();

                break;
            case 'D':
                cout << "You selected show all apartment options" << '\n';

                displayApartments(apartments);

                break;
            case 'U':
                cout << "You selected input new search parameters" << '\n';

                newSpecs = createCustomParams();

                break;
            case 'S':
                cout << "You selected show search parameters" << '\n';

                newSpecs.displayParameters();

                break;
            case 'M':
                cout << "You selected find potetial matches" << '\n';
                cout << "Searching for potential matches..." << '\n';

                criteriaChecker(apartments, newSpecs);

                sortApartments(apartments);

                displayBestOptions(apartments);

                break;
            case 'E':
                cout << "You selected exit" << '\n';
                break;
            default:
                cout << "Please enter a valid menu option " << '\n';
            }
            // tests input to make sure user inputs a valid menu option
        } while (!menuOptionCheck(input));
        // tests input and only exits the program if user selects exit
    } while (input != 'E');
    cout << '\n' << "Ending program..." << '\n';
}


int main() {
    vector<Apartment*> a;
    Parameter s;

    menuNav(a, s);

  /*  vector<Apartment*> apartments = createSampleApartments();
    Parameter newSpecs = createDefaultParams();
    newSpecs.loadDefaultParameters();
    newSpecs.loadDefaultImportanceLevel();

    displayApartments(apartments);
    
    newSpecs.displayParameters();

    cout << "_____________________________" << '\n' << '\n';

    criteriaChecker(apartments, newSpecs);

    sortApartments(apartments);

    displayBestOptions(apartments);*/
}
