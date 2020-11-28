#pragma once

#include <iostream>

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