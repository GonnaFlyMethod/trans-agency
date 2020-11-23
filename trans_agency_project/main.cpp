#include <iostream>
#include <string>

using namespace std;

class City
{
private:
	string city_name;
	int city_population;

public:
	City(string city_name, int city_population){
		this -> set_city_name(city_name);
		this -> set_city_population(city_population);
	}

	string get_city_name(bool print=false){
		if (print){
			cout << this -> city_name;
		}
		return this -> city_name;
	}
	void set_city_name(string name_of_city){
		if (name_of_city.length()){
			city_name = name_of_city;
		} else {
			throw invalid_argument("Value city_name setted as ''");
		}
	}

	int get_city_population(bool print=false){

		if (print){
			cout << city_population<< endl;
		}
		return this -> city_population;
	}

	void set_city_population(int value){
		if (value < 0){
			throw invalid_argument("Value of city_population can't be \
				                   negative");
		}
		city_population = value;
	}

};


int main()
{
	City new_city("Polock", 30000);
	new_city.set_city_population(30);
	new_city.get_city_population(true);
	new_city.get_city_name(true);
}
