#include <iostream>
#include <string>
#include <time.h>

using namespace std;


class City
{
private:
	string city_name;
	int city_population;

public:
	City(string city_name, int city_population){
		this -> SetCityName(city_name);
		this -> SetCityPopulation(city_population);
	}

	string GetCityName(bool print=false){
		if (print){
			cout << this -> city_name;
		}
		return this -> city_name;
	}
	void SetCityName(string name_of_city){
		if (name_of_city.length()){
			city_name = name_of_city;
		} else {
			throw invalid_argument("Value city_name setted as ''");
		}
	}

	int GetCityPopulation(bool print=false){

		if (print){
			cout << city_population<< endl;
		}
		return this -> city_population;
	}

	void SetCityPopulation(int value){
		if (value < 0){
			throw invalid_argument("Value of city_population can't be \
				                   negative");
		}
		city_population = value;
	}

};

class Customer
{
private:
	/*Arrays for random picking*/
	string names[6] = {"John", "Oliver", "Mike", "Alex",
							    "Elizabeth", "Nikole"
			                    };

    string types_of_transport[3] = {"Car", "Train", "Plane"};

	string name_of_customer;
	string type_of_transport;
	int age_of_customer;
	float weight;

protected:
	float RandomFloat(float a, float b) {
	    float random = ((float) rand()) / (float) RAND_MAX;
	    float diff = b - a;
	    float r = random * diff;
	    return a + r;
	}
public:
	Customer(){

		/*Setting random customer's name */

		/*generate random num from 0 to 5*/
		int RandIndexForName = rand() % 6;
		string rand_name = names[RandIndexForName];
		this -> SetNameOfCustomer(rand_name);

		/*Setting random type_of_transport  that the custoemer if*/
		/* preffered */

		/*generate random num from 0 to 2*/
		int RandIndexTypeOfTransport = rand() % 3;
		string rand_trans_name = types_of_transport[RandIndexTypeOfTransport];
		this -> SetNameOfTransport(rand_trans_name);

		/*Setting random age of the customer*/

		/* adds 50 to the random num from 0 to 25 */
		int RandomAge = (rand() % 26) + 30;
		this -> SetAgeOfCustomer(RandomAge);

		/*Setting random weight of the product */
		float RandomWeight = RandomFloat(500, 20000);
		this -> SetWeight(RandomWeight);

	}
	string GetNameOfCustomer(){
		return this -> name_of_customer;
	}
	void SetNameOfCustomer(string nameValue){
		name_of_customer = nameValue;
	}

	string GetNameOfTransport(){
		return this -> type_of_transport;
	}
	void SetNameOfTransport(string nameValue){
		type_of_transport = nameValue;
	} 

	int GetAgeOfCustomer(){
		return this -> age_of_customer;
	}
	void SetAgeOfCustomer(int value){
		age_of_customer = value;
	}

	float GetWeight(){
		return this -> weight;
	};
	void SetWeight(float value){
		weight = value;
	}

};

int main()
{
	srand ( time(NULL) ); //initialize the random seed

	Customer first_customer;
	cout << first_customer.GetNameOfCustomer() << endl;
	cout << first_customer.GetNameOfTransport() << endl;
	cout << first_customer.GetAgeOfCustomer() << endl;
	cout << first_customer.GetWeight();
}
