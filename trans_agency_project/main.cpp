/* Core headers*/
#include <iostream>
#include <string>
#include <time.h>
#include <map>
#include <vector>
#include <array>


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
	Order(){

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
public:
	TrancAgency(){
		cout << "New Tranc Agency was created!" << endl;
		sleep(2);
	};
	void AcceptOrder(Order some_order){
    	cout << "The Order from " << some_order.GetNameOfCustomer()
    	<<" was accepted!" << endl;

    	cout << "Delivery is underway..." << endl;

    	/* Sleep for 5 seconds */
		sleep(5);
    	cout << "Delivered!" << endl;
	}
};


/* Code driver */
int main()
{
	srand (time(NULL)); //initialize the random seed

	TrancAgency new_trans_agency;

	bool main_loop = true;

	/*for (int i;i<5;i++){
		string get = *(first_customer.GetPointerToCities() + i);
		cout << get;
	}*/
	

	while (main_loop) {
		Order first_customer;
		first_customer.GetInfoAboutOrder();
	}

	return 0;
		
}
