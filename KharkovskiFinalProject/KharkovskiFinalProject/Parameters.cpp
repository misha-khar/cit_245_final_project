#include <iostream>
#include <string>
#include <map>

using namespace std;

class Parameter {
private:

	char paramTypes[4] = { 'f', 'c', 'd', 'g' };	

	double footageParam = 0, costParam = 0, distanceParam = 0, gradeParam = 0;

	map<char, double> paramMap;
	map<string, double> marginMap;
	map<int, char> importanceLevelMap;




public:

	int getImportanceMapSize() {
		return importanceLevelMap.size();
	}

	char getImportanceParam(int i) {
		return importanceLevelMap.at(i);
	};

	double getParameter(char type) {
		return paramMap.at(type);
	};

	void loadDefaultParameters() {
		paramMap.insert(pair<char, double>('f', 900));
		paramMap.insert(pair<char, double>('c', 1500));
		paramMap.insert(pair<char, double>('d', 15));
		paramMap.insert(pair<char, double>('g', 90));
	};

	void loadDefaultMargins() {
		marginMap.insert(pair<string, double>("f", 200));
		marginMap.insert(pair<string, double>("c", 200));
		marginMap.insert(pair<string, double>("d", 3));
		marginMap.insert(pair<string, double>("g", 10));
	};

	void displayParameters() {
		cout << '\n' << "***   Parameters ***" << '\n';
		cout << "Footage: " << paramMap.at('f') << " sq ft" << '\n';
		cout << "Cost: $" << paramMap.at('c') << '\n';
		cout << "Distance: " << paramMap.at('d') << " miles" << '\n';
		cout << "Grade: " << paramMap.at('g') << "/100" << '\n';
	};

	void loadDefaultImportanceLevel() {
		importanceLevelMap.insert(pair<int, char>(1, 'f'));
		importanceLevelMap.insert(pair<int, char>(2, 'c'));
		importanceLevelMap.insert(pair<int, char>(3, 'd'));
		importanceLevelMap.insert(pair<int, char>(4, 'g'));
	};

};