#include <iostream>
#include <string>
#include <time.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "trans_agency.h"
#include "order.h"

using namespace std;

/* Code driver */
int main()
{
	srand ( time(NULL) ); //initialize the random seed

	TrancAgency new_trans_agency;

	bool main_loop = true;
	while (main_loop) {
		Order first_customer;
		new_trans_agency.AcceptOrder(first_customer);
	}

	return 0;
		
}
