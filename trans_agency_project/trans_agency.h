#pragma once

#include <iostream>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif


#include "order.h"
using namespace std;

class TrancAgency
{

private:
	int money = 10000;
public:
	void AcceptOrder(Order some_order){
    	cout << "The Order from " << some_order.GetNameOfCustomer()
    	<<" was accepted!" << endl;

    	cout << "Delivery is underway..." << endl;

    	/* Sleep for 5 seconds */
		sleep(5);
    	cout << "Delivered!" << endl;
	}
};
