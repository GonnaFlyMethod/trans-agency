/* Core headers*/
#include <iostream>
#include <string>
#include <time.h>
#include <map>
#include <vector>
#include <cmath>


/*Getting sleep func for different OS */
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

/* Namespace declaration */
using namespace std;


class Order
{
private:
	int id;
	/*Arrays for random picking*/

	/* Name of the customer */
	string names[6] = {"John", "Oliver", "Mike", "Alex",
							    "Elizabeth", "Nikole"
			                    };

    string types_of_transport[3] = {"Car", "Train", "Plane"};

    /*Key is gonna be string and value is gonna be integer*/
    map <string, int> citites = {
    	{"Minsk", 2000000},
    	{"Moscow", 10000000},
    	{"Vitebsk", 900000},
    	{"Polock", 70000},
    	{"Berlin", 3000000}

    };

    string citites_list[5] = {"Minsk", "Moscow", "Vitebsk", "Polock", "Berlin"};
	string name_of_customer;
	string type_of_transport;
	int age_of_customer;
	float weight;

	string PointA;
	string PointB;

	int award;

protected:
	float RandomFloat(float a, float b) {
	    float random = ((float) rand()) / (float) RAND_MAX;
	    float diff = b - a;
	    float r = random * diff;
	    return a + r;
	}

public:
	Order(int id){
		this ->id = id;

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

		/*Setting random Point A */
		/*generate random num from 0 to 4*/
		int RandIndexPointA = rand() % 5;
		string randomPointA = citites_list[RandIndexPointA];
		this -> SetPointA(randomPointA);

		/*Setting random Point A */
		/*generate random num from 0 to 4*/
		int RandIndexPointB;
		while (RandIndexPointB == RandIndexPointA){
			RandIndexPointB = rand() % 5; 
		}

		string randomPointB = citites_list[RandIndexPointB];
		this -> SetPointB(randomPointB);

		/* Generating random award for delevering */
		/* from 10000$ to 109999$ */
		int random_award = (rand() % 100000) + 10000;
		this -> SetRandomAward(random_award);

	}
	~Order(){};
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

	string GetPointA(){
		return this ->PointA;
	}
	void SetPointA(string value){
		PointA = value;
	}

	string GetPointB(){
		return this -> PointB;
	}
	void SetPointB(string value){
		PointB = value;
	}

	int GetRandomAward(){
		return this -> award;
	}
	void SetRandomAward(int value){
		award = value;
	}

	void GetInfoAboutOrder(){
		string indention(10, '~');
		cout << indention << " New Order " << indention << endl <<
		"Customer's name: " <<  this ->GetNameOfCustomer() << endl <<
		"Customer's age: "  << this -> GetAgeOfCustomer() << endl <<
		"Point A: " << this -> GetPointA() << endl <<
		"Point B: " << this -> GetPointB() << endl <<
		"Preffered transport: " << this -> GetNameOfTransport() << endl <<
		"Award for delevering: " << this -> GetRandomAward() << "$" << endl;
		sleep(10);
	}
	string* GetPointerToCities(){
		return this -> citites_list;
	}

	int GetPopulationOfCity(string city){
		return citites[city];
	}

};


class TrancAgency
{

private:
	int money = 10000;

	map<string, int> map_cities = {
		{"Car", 0},
		{"Train", 1},
		{"Plane", 2},
	};

	string InitWeatherConditions(){
		string possible_weather[4] = {"Good", "OK", "Bad", "Awful"};

		/*generate random num from 0 to 4*/
		int rand_weather_index = rand() % 5;
		string weather = possible_weather[rand_weather_index];
		return weather;
	}

	bool ProcessAccident(int coefficient_of_accident_included){
		int random_value = rand() % 100;

		if (random_value > coefficient_of_accident_included){
			return true;
		} else{
			return false;
		}

	}

	bool InitAccident(string type_of_transport, string weather){
		int middle_chance = 50;
		int coefficient_of_accident_included;

		if (type_of_transport == "Car"){
			if (weather == "Good"){
				/*chance of accident is 19 %*/
				/* 50 * 1.6 = 80*/
				/* 99 - 80 = 19 */
				coefficient_of_accident_included = (middle_chance * 1.6);
			} else if (weather == "OK") {
				/*chance of accident is 29 %*/
				coefficient_of_accident_included = (middle_chance * 1.4);
			} else if (weather == "Bad"){
				/*chance of accident is 54 %*/
				coefficient_of_accident_included = (middle_chance * 0.9);
			} else{
				/*chance of accident is 69 %*/
				coefficient_of_accident_included = (middle_chance * 0.6);
			}

			bool accident = ProcessAccident(coefficient_of_accident_included);

			if (accident){
				return true;
			} else{
				return false;
			}

		} else if (type_of_transport == "Train"){
			if (weather == "Good"){
				/*chance of accident is 14 %*/
				coefficient_of_accident_included = (middle_chance * 1.7);
			} else if (weather == "OK") {
				/*chance of accident is 19 %*/
				coefficient_of_accident_included = (middle_chance * 1.6);
			} else if (weather == "Bad"){
				/*chance of accident is 34 %*/
				coefficient_of_accident_included = (middle_chance * 1.3);
			} else{
				/*chance of accident is 69 %*/
				coefficient_of_accident_included = (middle_chance * 0.6);
			}

			bool accident = ProcessAccident(coefficient_of_accident_included);

			if (accident){
				return true;
			} else{
				return false;
			}

		} else{
			if (weather == "Good"){
				/*chance of accident is 4 %*/
				coefficient_of_accident_included = (middle_chance * 1.9);
			} else if (weather == "OK") {
				/*chance of accident is 14 %*/
				coefficient_of_accident_included = (middle_chance * 1.7);
			} else if (weather == "Bad"){
				/*chance of accident is 34 %*/
				coefficient_of_accident_included = (middle_chance * 1.3);
			} else{
				/*chance of accident is 79 %*/
				coefficient_of_accident_included = (middle_chance * 0.4);
			}

			bool accident = ProcessAccident(coefficient_of_accident_included);

			if (accident){
				return true;
			} else{
				return false;
			}

		}

	}

	void SumUp(int compensation, Order order_obj){
		int award = order_obj.GetRandomAward();

		if (compensation){
			award = 0;
			this -> money = this ->money - compensation;
			cout << "Income: " << "-" << compensation;
		}
		cout << "Total money of the agency: " << this -> money << endl;

	}
public:
	TrancAgency(){
		cout << "New Tranc Agency was created!" << endl;
		sleep(2);
	};
	~TrancAgency(){};

	void AcceptOrder(Order some_order){
    	cout << "The Order from " << some_order.GetNameOfCustomer()
    	<<" was accepted!" << endl;

    	this -> Delevering(some_order);
	}
	int Delevering(Order some_order){
		string transport_for_order = some_order.GetNameOfTransport();
		string point_a = some_order.GetPointA();
		int point_a_int = map_cities[transport_for_order];

		/* {"Car", 0},
		   {"Train", 1},
		   {"Plane", 2} */
		switch(point_a_int){
			case 0:
				cout << "Car is moving from " << point_a <<
				"..." << endl;
				break;
			case 1:
				cout << "Train is moving from " << point_a << endl;
				break;
			case 2:
				cout << "Plane" << endl;
				break;
		}

		string weather = InitWeatherConditions();

		cout << "Weather is " << weather << endl;

		bool is_accident = InitAccident(transport_for_order, weather);
		int compensation = 0;

		if (is_accident == 1){
			cout << "There's an accident on the way of delevering!" << endl;
			sleep(3);
			if (transport_for_order == "Car"){
				compensation = 10000;
			} else if (transport_for_order == "Train"){
				compensation = 50000;
			} else{
				compensation = 80000;
			}
		}
		cout << "Continue delevering..." << endl;
		sleep(2);
    	cout << "Delivered!" << endl;

    	/* Sleep for 5 seconds 
		sleep(5);*/
		this -> SumUp(compensation, some_order);
		return 0;
	}
};


/* Code driver */
int main()
{
	srand(time(NULL)); //initialize the random seed

	TrancAgency new_trans_agency;

	bool main_loop = true;

	/*for (int i;i<5;i++){
		string get = *(first_customer.GetPointerToCities() + i);
		cout << get;
	}*/
	int id = 0;
	while (1) {
		/*Getting memory adress of the obj*/
		Order *first_customer = new Order(id);
		(*first_customer).GetInfoAboutOrder();
		new_trans_agency.AcceptOrder(*first_customer);
		delete first_customer;
		id++;
	}
		
}
