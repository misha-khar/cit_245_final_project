//#include <iostream>
//#include <string>
//#include <map>
//
//using namespace std;
//
//class UserSpecs {
//
//private:
//	string specTypes[4] = { "footage", "cost", "distance", "grade" };
//
//	double footageSpec;
//	double costSpec;
//	double distanceSpec;
//	double gradeSpec;
//
//	map<string, double> parameterMap;
//
//	map<string, bool> overUnderMap;
//
//	//	bool overUnderMap[4];
//
//	bool footageOverUnder;
//	bool costOverUnder;
//	bool distanceOverUnder;
//	bool gradeOverUnder;
//
//	void insertOverUnderMap(string type, bool b) {
//		overUnderMap.insert(pair<string, bool>(type, b));
//	}
//
//	string convertOverUnder(bool b) {
//		if (b) {
//			return "More";
//		}
//		else {
//			return "Less";
//		}
//	}
//
//public:
//
//	UserSpecs() {
//	}
//
//	UserSpecs(double f, double c, double d, double g, map<string, bool> oum)
//		:footageSpec{ f }, costSpec{ c }, distanceSpec{ d }, gradeSpec{ g }, overUnderMap{ oum }{
//	}
//
//	double getFootageSpec() {
//		return footageSpec;
//	};
//
//	double getCostSpec() {
//		return costSpec;
//	};
//
//	double getDistanceSpec() {
//		return distanceSpec;
//	};
//
//	double getGradeSpec() {
//		return gradeSpec;
//	};
//
//	bool getOverUnderMap(string key) {
//		return overUnderMap.at(key);
//	}
//
//	void setFootageSpec(double f) {
//		footageSpec = f;
//	}
//
//	void setCostSpec(double c) {
//		costSpec = c;
//	}
//
//	void setDistanceSpec(double d) {
//		distanceSpec = d;
//	}
//
//	void setGradeSpec(char g) {
//		gradeSpec = g;
//	}
//
//	void requestUserSpecs() {
//		bool b;
//		double input;
//		
//		for (int i = 0; i <= 3; i++) {
//			cout << '\n' << "Please enter your target " << specTypes[i] << " : ";
//			cin >> input;
//			parameterMap.insert(pair<string, double>(specTypes[i], input));
//			cout << "Would you like to show results higher or lower than " << footageSpec << "? :  ";
//			cout << "(Enter 1 for higher and 0 for lower): ";
//			cin >> b;
//			overUnderMap.insert(pair<string, bool>(specTypes[i], b));
//		}
//
//
//
//		/*cout << "Please enter your target square footage: ";
//		cin >> footageSpec;
//		cout << "Would you like to show results higher or lower than " << footageSpec << " sq ft? ";
//		cout << "(Enter 1 for higher and 0 for lower): ";
//		cin >> b;
//		insertOverUnderMap("footage", b);
//
//		cout << '\n' << "Please enter your target cost: ";
//		cin >> costSpec;
//		cout << "Would you like to show results higher or lower than $" << costSpec << "? ";
//		cout << "(Enter 1 for higher and 0 for lower): ";
//		cin >> b;
//		insertOverUnderMap("cost", b);
//
//		cout << '\n' << "Please enter your target distance from the city: ";
//		cin >> distanceSpec;
//		cout << "Would you like to show results higher or lower than " << distanceSpec << " miles? ";
//		cout << "(Enter 1 for higher and 0 for lower): ";
//		cin >> b;
//		insertOverUnderMap("distance", b);
//
//		cout << '\n' << "Please enter your target neighborhood grade (1-100): ";
//		cin >> gradeSpec;
//		cout << "Would you like to show results higher or lower than " << gradeSpec << "? ";
//		cout << "(Enter 1 for higher and 0 for lower): ";
//		cin >> b;
//		insertOverUnderMap("grade", b);*/
//
//		// displayUserSpecs();
//	}
//
//	void displayUserSpecs() {
//		
//		cout << "*** Criteria To Meet ***" << '\n';
//
//		for (int i = 0; i <= 3; i++) {
//			cout << convertOverUnder(overUnderMap.at(specTypes[i])) << " than or equal to "
//				<< overUnderMap.at(specTypes[i]) << '\n';
//		}
//		
//		
//		
//		/*cout << '\n' << "***   Criteria to meet:   ***" << '\n';
//		cout << convertOverUnder(overUnderMap.at("footage")) << " than or equal to "
//			<< footageSpec << " sq ft" << '\n';
//		cout << convertOverUnder(overUnderMap.at("cost")) << " than or equal to $"
//			<< costSpec << "/month" << '\n';
//		cout << convertOverUnder(overUnderMap.at("distance")) << " than or equal to "
//			<< distanceSpec << " miles from the city" << '\n';
//		cout << convertOverUnder(overUnderMap.at("grade")) << " than or equal to '"
//			<< gradeSpec << "' grade" << '\n';*/
//	}
//};