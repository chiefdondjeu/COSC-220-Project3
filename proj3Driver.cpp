/*
 *proj3Driver.cpp
 *main function
 *Author: Florent Dondjeu Tschoufack
 *Created: November 29, 2019
 *Current: November 29, 2019
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "d_dnode.h"
#include "d_dnodeBase.h"
#include "studentClass.h"

int main()
{
	dNode<Student> *list = new dNode<Student>;
	read_file(list);

	char choice;
	std :: string space = "\n";

	bool END = true;
	do
	{	
		for(int i = 0; i < 75; i++ )
			std :: cout << space;

		std :: cout << "=======================================================" << std :: endl;
		std :: cout << std :: right << std :: setw(38) << "Flo&Ryan's Database" << std :: endl;
		std :: cout << "=======================================================" << std :: endl;

		std :: cout << "V - View Database information" << std :: endl;
		std :: cout << "F - Find student" << std :: endl;
		std :: cout << "S - Sort students" << std :: endl;
		std :: cout << "A - Add a student" << std :: endl;
		std :: cout << "D - Delete a student" << std :: endl;
		std :: cout << "Q - Quit the program" << std :: endl;

		std :: cout << "=======================================================" << std :: endl;

		std :: cout << "\nChoice selected -- ";
		std :: cin >> choice;

		for(int i = 0; i < 75; i++ )
					std :: cout << space; 

		switch(choice)
		{
			case 'V':
				display(list);
				break;
			case 'F':
				findStudent(list);
				break;
			case 'S':
				break;
			case 'A':
				addStudent(list);
				break;
			case 'D':
				deleteStudent(list);
				break;
			case 'Q': 
				END = false;
				std :: cout << "You have successfully exited the program. Good day!\n\n" << std :: endl;
				break;
		}

	}while(END == true);


	return 0;
}