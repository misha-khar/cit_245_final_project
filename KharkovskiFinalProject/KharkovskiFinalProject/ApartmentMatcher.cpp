/*
Misha Kharkovksi
Final project
Program matches apartment to user given certain preferences

resources:
sorting code from:
https://www.educative.io/edpresso/how-to-sort-a-map-by-value-in-cpp


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
const double SCORE_MULTIPLIER = 1.05;

// function to create sample apartments
// maybe add option of chooseing b/w pre-selected and user defined options?
//void createSampleApartments(vector<Apartment> a) {
//
//    // figure out how to retrurn pointer here
//
//    Apartment* apartment1 = new Apartment("alpha", 900, 1500, 15, 90);
//    apartments.push_back(*apartment1);
//    Apartment* apartment2 = new Apartment("bravo", 600, 800, 10, 85);
//    apartments.push_back(*apartment2);
//    Apartment* apartment3 = new Apartment("chalie", 500, 1300, 1, 70);
//    apartments.push_back(*apartment3);
//
//}

vector<Apartment*> createSampleApartments() {

    vector<Apartment*> a;

    a.push_back(new Apartment("alpha", 900, 1500, 15, 90));
    a.push_back(new Apartment("bravo", 900, 1500, 15, 90));
    a.push_back(new Apartment("chalie", 900, 1500, 15, 90));
    a.push_back(new Apartment("delta", 900, 1000, 15, 90));
    a.push_back(new Apartment("echo", 900, 1500, 15, 90));
    a.push_back(new Apartment("foxtrot", 900, 1500, 15, 90));

    return a;
}

//void doesItMeetCriteria3_0(vector<Apartment> options) {
//
//    for (int i = 0; i < apartments.size(); i++) {
//        if (apartments[i].criteriaTester('f', newSpecs.getFootageSpec(), newSpecs.getOverUnderMap("footage")) &&
//            apartments[i].criteriaTester('c', newSpecs.getCostSpec(), newSpecs.getOverUnderMap("cost")) &&
//            apartments[i].criteriaTester('d', newSpecs.getDistanceSpec(), newSpecs.getOverUnderMap("distance")) &&
//            apartments[i].criteriaTester(newSpecs.getGradeSpec(), newSpecs.getOverUnderMap("grade"))) {
//            cout << '\n' << "Apartment " << apartments[i].getName() << " meets all criteria. " << '\n';
//        }
//    }
//
//}
//
//// function to tes user input and make sure it is valid
//bool menuOptionCheck(char input) {
//    // char array that stores valid menu options
//    char validMenuOptions[] = { 'I', 'P', 'D', 'S', 'U', 'M', 'E' };
//    // loops through array of validMenuOptions and compares user input against validMenuOptions
//    for (int i = 0; i < sizeof(validMenuOptions); i = i + 1) {
//        // if the user input matches one of the acceptable options, returns true
//        if (input == validMenuOptions[i]) {
//            return true;
//        }
//    }
//    return false;
//}
//
//void quickLoadData() {
////    map<string, bool> overUnderMap;
//    overUnderMap.insert(pair<string, bool>("f", 1));
//    overUnderMap.insert(pair<string, bool>("c", 1));
//    overUnderMap.insert(pair<string, bool>("d", 1));
//    overUnderMap.insert(pair<string, bool>("g", 1));
//    UserSpecs specs2(100, 100, 1, 50, overUnderMap);
//    createSampleApartments();
//}
//
//void menuNav() {
//    // variable to store user input
//    char input;
//    do {
//        do {
//            cout << "_____________________________________________" << '\n';
//            cout << "|                                           |" << '\n';
//            cout << "|----------------Dumb Zillow----------------|" << '\n';
//            cout << "|------------------ MENU -------------------|" << '\n';
//            cout << "| Type 'I' to quick load data       |" << '\n';
//            cout << "| Type 'P' to use pre-existing apartments   | " << '\n';
//            cout << "| Type 'D' to display all apartment options |" << '\n';
//            cout << "| Type 'U' to input search parameters       |" << '\n';
//            cout << "| Type 'S' to display search parameters     |" << '\n';
//            cout << "| Type 'M' to find potential matches        |" << '\n';
//            cout << "| Type 'E' to exit the program              |" << '\n';
//            cout << "|___________________________________________|" << '\n' << '\n';
//            cout << "PLease enter a menu option: ";
//            cin >> input;
//            // converts user input to uppercase for consistent testing
//            input = toupper(input);
//            // selects proper menu option based on user input
//            switch (input) {
//            case 'I':
//                cout << "You selected quick load data" << '\n';
//
//                quickLoadData();
//
//                
//
//
//
//                break;
//            case 'P':
//                cout << "You selected use pre-existing apartments" << '\n';
//                cout << "Loading pre-existing apartments...";
//                createSampleApartments();
//                cout << "Loaded" << '\n';
//                break;
//            case 'D':
//                cout << "You selected show all apartment options" << '\n';
//                displayAllApartments();
//                break;
//            case 'U':
//                cout << "You selected input new search parameters" << '\n';
//             
//                newSpecs.requestUserSpecs();
//                break;
//            case 'S':
//                cout << "You selected show search parameters" << '\n';
//                newSpecs.displayUserSpecs();
//                break;
//            case 'M':
//                cout << "You selected find potetial matches" << '\n';
//                cout << "Searching for potential matches..." << '\n';
//                doesItMeetCriteria3_0(apartments);
//                break;
//            case 'E':
//                cout << "You selected exit" << '\n';
//                break;
//            default:
//                cout << "Please enter a valid menu option " << '\n';
//            }
//            // tests input to make sure user inputs a valid menu option
//        } while (!menuOptionCheck(input));
//        // tests input and only exits the program if user selects exit
//    } while (input != 'E');
//    cout << '\n' << "Ending program..." << '\n';
//}
//

// function tha assists in sort algorithm
bool compareDifference(const pair<Apartment*, double>& a, const pair<Apartment*, double>& b){
    return (a.second < b.second);
}

// may not need all code below
//void checkFootage(vector<Apartment> a, Parameter p, int importanceCoefficient) {
//    cout << '\n' << "Checking footage..." << '\n';
//
//    // initializes map for holding differences
//    map<string, double> differenceMap;
//    // loops thru and adds apartment with its difference to the map
//    for (int i = 0; i < a.size(); i++) {
//        differenceMap.insert(pair<string, double>(a[i].getName(), abs(a[i].getFootage() - p.getParameter('f'))));
//    }
//
//    // needed to be a vector type for sorting algorithm
//    vector<pair<string, double>> vecDiffMap;
//    map<string, double> ::iterator it2;
//    // transfers each element of diffMap to a vector of the same contents
//    for (it2 = differenceMap.begin(); it2 != differenceMap.end(); it2++)
//    {
//        vecDiffMap.push_back(make_pair(it2->first, it2->second));
//    }
//    // sorts the vector of differences
//    sort(vecDiffMap.begin(), vecDiffMap.end(), sortByVal);
//
//    // simple display 
//    //for (int i = 0; i < vecDiffMap.size(); i++) {
//    //    cout << vecDiffMap[i].first << ": " << vecDiffMap[i].second << '\n';
//    //}
//
//    // loops thru vecDiffMap and adds points appropriately
//    // outer loops goes thru vecDiffMap values
//    for (int i = 0; i < vecDiffMap.size(); i++) {
//        // inner loops used to go thru apartment list to compare values
//        for (int j = 0; j < a.size(); j++) {
//            if (vecDiffMap[i].first == a[j].getName()) {
//                a[j].addToMatchScore((i * SCORE_MULTIPLIER)*(10*importanceCoefficient));
//                cout << "Apartment " << a[j].getName() << " match score: " << a[j].getMatchScore() << '\n';
//            }
//        }
//    }
//
//}
//
//void checkCost(vector<Apartment> a, Parameter p, int importanceCoefficient) {
//    cout << '\n' << "Checking cost..." << '\n';
//
//    // initializes map for holding differences
//    map<string, double> differenceMap;
//    // loops thru and adds apartment with its difference to the map
//    for (int i = 0; i < a.size(); i++) {
//        differenceMap.insert(pair<string, double>(a[i].getName(), abs(a[i].getCost() - p.getParameter('c'))));
//    }
//
//    // needed to be a vector type for sorting algorithm
//    vector<pair<string, double>> vecDiffMap;
//    map<string, double> ::iterator it2;
//    // transfers each element of diffMap to a vector of the same contents
//    for (it2 = differenceMap.begin(); it2 != differenceMap.end(); it2++)
//    {
//        vecDiffMap.push_back(make_pair(it2->first, it2->second));
//    }
//    // sorts the vector of differences
//    sort(vecDiffMap.begin(), vecDiffMap.end(), sortByVal);
//
//    // simple display 
//    //for (int i = 0; i < vecDiffMap.size(); i++) {
//    //    cout << vecDiffMap[i].first << ": " << vecDiffMap[i].second << '\n';
//    //}
//
//    // loops thru vecDiffMap and adds points appropriately
//    // outer loops goes thru vecDiffMap values
//    for (int i = 0; i < vecDiffMap.size(); i++) {
//        // inner loops used to go thru apartment list to compare values
//        for (int j = 0; j < a.size(); j++) {
//            if (vecDiffMap[i].first == a[j].getName()) {
//                a[j].addToMatchScore((i * SCORE_MULTIPLIER) * (10 * importanceCoefficient));
//                cout << "Apartment " << a[j].getName() << " match score: " << a[j].getMatchScore() << '\n';
//            }
//        }
//    }
//
//}
//
//void checkDistance(vector<Apartment> a, Parameter p, int importanceCoefficient) {
//    cout << '\n' << "Checking distance..." << '\n';
//
//    // initializes map for holding differences
//    map<string, double> differenceMap;
//    // loops thru and adds apartment with its difference to the map
//    for (int i = 0; i < a.size(); i++) {
//        differenceMap.insert(pair<string, double>(a[i].getName(), abs(a[i].getDistance() - p.getParameter('d'))));
//    }
//
//    // needed to be a vector type for sorting algorithm
//    vector<pair<string, double>> vecDiffMap;
//    map<string, double> ::iterator it2;
//    // transfers each element of diffMap to a vector of the same contents
//    for (it2 = differenceMap.begin(); it2 != differenceMap.end(); it2++)
//    {
//        vecDiffMap.push_back(make_pair(it2->first, it2->second));
//    }
//    // sorts the vector of differences
//    sort(vecDiffMap.begin(), vecDiffMap.end(), sortByVal);
//
//    // simple display 
//    //for (int i = 0; i < vecDiffMap.size(); i++) {
//    //    cout << vecDiffMap[i].first << ": " << vecDiffMap[i].second << '\n';
//    //}
//
//    // loops thru vecDiffMap and adds points appropriately
//    // outer loops goes thru vecDiffMap values
//    for (int i = 0; i < vecDiffMap.size(); i++) {
//        // inner loops used to go thru apartment list to compare values
//        for (int j = 0; j < a.size(); j++) {
//            if (vecDiffMap[i].first == a[j].getName()) {
//                a[j].addToMatchScore((i * SCORE_MULTIPLIER) * (10 * importanceCoefficient));
//                cout << "Apartment " << a[j].getName() << " match score: " << a[j].getMatchScore() << '\n';
//            }
//        }
//    }
//
//}
//
//void checkGrade(vector<Apartment> a, Parameter p, int importanceCoefficient) {
//    cout << '\n' << "Checking grade..." << '\n';
//
//    // initializes map for holding differences
//    map<string, double> differenceMap;
//    // loops thru and adds apartment with its difference to the map
//    for (int i = 0; i < a.size(); i++) {
//        differenceMap.insert(pair<string, double>(a[i].getName(), abs(a[i].getGrade() - p.getParameter('g'))));
//    }
//
//    // needed to be a vector type for sorting algorithm
//    vector<pair<string, double>> vecDiffMap;
//    map<string, double> ::iterator it2;
//    // transfers each element of diffMap to a vector of the same contents
//    for (it2 = differenceMap.begin(); it2 != differenceMap.end(); it2++)
//    {
//        vecDiffMap.push_back(make_pair(it2->first, it2->second));
//    }
//    // sorts the vector of differences
//    sort(vecDiffMap.begin(), vecDiffMap.end(), sortByVal);
//
//    // simple display 
//    //for (int i = 0; i < vecDiffMap.size(); i++) {
//    //    cout << vecDiffMap[i].first << ": " << vecDiffMap[i].second << '\n';
//    //}
//
//    // loops thru vecDiffMap and adds points appropriately
//    // outer loops goes thru vecDiffMap values
//    for (int i = 0; i < vecDiffMap.size(); i++) {
//        // inner loops used to go thru apartment list to compare values
//        for (int j = 0; j < a.size(); j++) {
//            if (vecDiffMap[i].first == a[j].getName()) {
//                a[j].addToMatchScore((i * SCORE_MULTIPLIER) * (10 * importanceCoefficient));
//                cout << "Apartment " << a[j].getName() << " match score: " << a[j].getMatchScore() << '\n';
//            }
//        }
//    }
//}

// 
void checkParams(vector<Apartment*> &a, Parameter &p, double importanceCoefficient, char paramMarker) {
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



// function to accept unsorted apartment list and sort that list by match score
void sortApartments(vector<Apartment*> &unsortedA) {
    // write code to BUBBLE sort vector by match score here


}

int main() {

//    menuNav();

    vector<Apartment*> apartments = createSampleApartments();
    Parameter newSpecs;
    newSpecs.loadDefaultParameters();
    newSpecs.loadDefaultImportanceLevel();

    displayApartments(apartments);
    
    newSpecs.displayParameters();
    cout << "_____________________________" << '\n' << '\n';

    criteriaChecker(apartments, newSpecs);

    sortApartments(apartments);

    displayApartments(apartments);
}
