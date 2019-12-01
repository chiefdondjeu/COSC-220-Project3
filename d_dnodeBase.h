
/*
 *d_dnodeBase.h
 *definition of dnode class
 *Author: Florent Dondjeu Tschoufack
 *Created: November 29, 2019
 *Current: November 29, 2019
 */

#ifndef DNODEBASE_H
#define DNODEBASE_H

#include<iostream>
#include<fstream>
#include<iomanip>

#include "d_dnode.h"
#include "studentClass.h"

 //display
 //displays the elements in the list
 //parameter: dnode pointer
 //returns: none
 //precondition: list is not empty
 //postcondition: every element in the list has been printed
template <typename T>
void display(dNode<T>* currNode)
{
	int count = 0;
	dNode<T>* p = currNode->next;

	std::cout << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << std::left << std::setw(15) << "Student ID" << std::setw(31) << "Name" << std::setw(10) << "Year" << std::setw(10) << "GPA" << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;

	while (p != currNode)
	{
		std::cout << p->value;
		p = p->next;
		count++;
	}
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "\nStudent count - " << count << std::endl;

	std::cout << "\n\nPress enter to continue...";
	std::cin.ignore();
	std::cin.get();
}

//add
//adds element into the list
//parameter: dnode pointer, and element to be added
//returns: list with new element
//precondition: none
//postcondition: the new element is in the list
template <typename T>
dNode<T>* add(dNode<T>* currNode, T val)
{
	dNode<T>* newNode, * prevNode;

	newNode = new dNode<T>(val);

	prevNode = currNode->prev;

	newNode->prev = prevNode;
	newNode->next = currNode;

	prevNode->next = newNode;
	currNode->prev = newNode;

	return newNode;
}

//read_file
//reads students information from a file and puts it in the list
//parameter: dnode pointer
//returns: none
//precondition: file is not empty
//postcondition: every students information from the file is in the list
template <typename T>
void read_file(dNode<T>* currNode)
{
	int id, year;
	double GPA;
	std::string firstname, lastname;

	std::ifstream infile;
	infile.open("student.txt");
	while (!infile.eof())
	{
		infile >> id;
		infile >> firstname;
		infile >> lastname;
		infile >> year;
		infile >> GPA;
		add(currNode, Student(id, firstname, lastname, year, GPA));
	}
}

//addStudent
//adds one student information
//parameter: dnode pointer
//returns: none
//precondition: none
//postcondition: the new student information is in the list
template <typename T>
void addStudent(dNode<T>* currNode)
{
	int id, year;
	double GPA;
	std::string firstname, lastname;

	std::cout << "\n=======================================================" << std::endl;
	std::cout << "New student's info...\n" << std::endl;
	std::cout << "ID\t-- ";
	std::cin >> id;

	std::cout << "Name\t-- ";
	std::cin >> firstname >> lastname;

	std::cout << "Year\t-- ";
	std::cin >> year;

	std::cout << "GPA\t-- ";
	std::cin >> GPA;

	add(currNode, Student(id, firstname, lastname, year, GPA));
	//std :: cout << "=====================================" << std :: endl;

	std::cout << "\n\nPress enter to continue...";
	std::cin.ignore();
	std::cin.get();

}

//search
//searchs students in datdabase based on user's description
//parameter: dnode pointer, char variable
//returns: true if search found else false
//precondition: none
//postcondition: either true or false is returned
template<typename T>
bool search(dNode<T>* currNode, char choice)
{
	int id;
	std::string firstname, lastname;

	dNode<T>* p = currNode->next;

	if (choice == 'I')
	{
		std::cout << "ID -- ";
		std::cin >> id;

		while (p != currNode)
		{
			if (p->value.getId() == id)
			{
				std::cout << p->value.getFname();
				return true;
			}
			else p = p->next;
		}
	}

	if (choice == 'F')
	{
		std::cout << "First name -- ";
		std::cin >> firstname;

		while (p != currNode)
		{
			if (p->value.getFname() == firstname)
			{
				std::cout << p->value.getFname();
				return true;
			}
			else p = p->next;
		}
	}

	if (choice == 'L')
	{
		std::cout << "Last name -- ";
		std::cin >> lastname;

		while (p != currNode)
		{
			if (p->value.getLname() == lastname)
			{
				std::cout << p->value.getFname();
				return true;
			}
			else p = p->next;
		}
	}

	return false;
}

//findStudent
//determines how the student should be searched
//parameter: dnode pointer
//returns: none
//precondition: none
//postcondition: notifies the user if the student is in or not in the list
template <typename T>
void findStudent(dNode<T>* currNode)
{
	char c, c1;
	bool tell;

	std::cout << "\n=======================================================" << std::endl;
	std::cout << "Find by...\n" << std::endl;
	std::cout << "I - ID" << std::endl;
	std::cout << "F - First name" << std::endl;
	std::cout << "L - Last name" << std::endl;
	//std :: cout << "=====================================" << std :: endl;

	std::cout << "\nChoice selected -- ";
	std::cin >> c;
	std::cout << std::endl;

	switch (c)
	{
	case 'I':
		tell = search(currNode, c);
		break;
	case 'F':
		tell = search(currNode, c);
		break;
	case 'L':
		tell = search(currNode, c);
		break;
	}

	if (tell == true)
	{
		std::cout << " is in the database." << std::endl;
	}
	else
	{
		std::cout << "This student is not in the database." << std::endl;

		std::cout << "\n\nPress enter to continue...";
		std::cin.ignore();
		std::cin.get();

		std::cout << "\nWould you like to add him... " << std::endl;
		std::cout << "Y - Add\nN - Leave" << std::endl;
		std::cout << "\nChoice selected -- ";
		std::cin >> c1;

		if (c1 == 'Y')
		{
			addStudent(currNode);
		}
	}

	std::cout << "\n\nPress enter to continue...";
	std::cin.ignore();
	std::cin.get();

}

//deleteStudent
//searches and delete student in the list
//parameter: dnode pointer
//returnd: none
//precondtion: none
//postcondition: one student as been removed  from the list if found
template <typename T>
void deleteStudent(dNode<T>* currNode)
{
	int id;
	std::string firstname, lastname;

	char del;
	bool check = false;

	std::cout << "\n=======================================================" << std::endl;
	std::cout << "Delete by...\n" << std::endl;
	std::cout << "I - ID" << std::endl;
	std::cout << "F - First name" << std::endl;
	//std :: cout << "L - Last name" << std :: endl;
	//std :: cout << "=====================================" << std :: endl;

	std::cout << "\nChoice selected -- ";
	std::cin >> del;
	std::cout << std::endl;

	dNode<T>* delt;	//node that will be deleted
	dNode<T>* s = currNode;
	dNode<T>* prevNode = currNode->prev;
	dNode<T>* succNode = currNode->next;

	switch (del)
	{
	case 'I':
		std::cout << "ID -- ";
		std::cin >> id;

		while (currNode->next != s)
		{
			if (currNode->value.getId() == id)
			{
				delt = currNode;
				prevNode->next = succNode;
				succNode->prev = prevNode;

				check = true;
				std::cout << currNode->value.getFname() << " has been removed from the database." << std::endl;
				delete delt;
			}

			prevNode = currNode;
			currNode = currNode->next;
			succNode = currNode->next;
		}
		break;
	case 'F':
		std::cout << "First name -- ";
		std::cin >> firstname;

		while (currNode->next != s)
		{
			if (currNode->value.getFname() == firstname)
			{
				delt = currNode;
				prevNode->next = succNode;
				succNode->prev = prevNode;

				check = true;
				std::cout << currNode->value.getFname() << " has been removed from the database." << std::endl;
				delete delt;
			}

			prevNode = currNode;
			currNode = currNode->next;
			succNode = currNode->next;
		}
		break;
	}

	if (check == false)
		std::cout << "The student you are trying to delete does not exist." << std::endl;

	std::cout << "\n\nPress enter to continue...";
	std::cin.ignore();
	std::cin.get();
}


template <typename T>
int size(dNode<T>* currNode) {
	int count = 0;
	dNode<T>* p = currNode->next;
	while (p != currNode)
	{
		p = p->next;
		count++;
	}
	return count;
}
template <typename T>
void sortStudent(dNode<T>* currNode)
{
	dNode<T>* Sorter;
	dNode<T>* Sorter2;
	char choice;

	std :: cout << "\n=======================================================" << std::endl;
	std :: cout << "Sort by..." << std::endl;
	std :: cout << "\nI - ID\nF - First name\nL - Last name\nY - Year\nG - GPA" << std :: endl;
	std ::cout << "\nChoice selected -- ";
	std :: cin >> choice;
	Sorter = currNode;

	if (choice == 'I') {
		Student x;
		for (int i = 0; i < size(currNode); i++) {
			Sorter2 = Sorter->next;
			while (Sorter2 != currNode) {
				if (Sorter->value.getId() > Sorter2->value.getId()) {
					x = Sorter->value;
					Sorter->value = Sorter2->value;
					Sorter2->value = x;

				}
				Sorter2 = Sorter2->next;
			}
			Sorter = Sorter->next;
		}
	}
	if (choice == 'F') {
		Student x;
		for (int i = 0; i < size(currNode); i++) {
			Sorter2 = Sorter->next;
			while (Sorter2 != currNode) {
				if (Sorter->value.getFname() > Sorter2->value.getFname()) {
					x = Sorter->value;
					Sorter->value = Sorter2->value;
					Sorter2->value = x;

				}
				Sorter2 = Sorter2->next;
			}
			Sorter = Sorter->next;
		}
	}
	if (choice == 'L') {
		Student x;
		for (int i = 0; i < size(currNode); i++) {
			Sorter2 = Sorter->next;
			while (Sorter2 != currNode) {
				if (Sorter->value.getLname() > Sorter2->value.getLname()) {
					x = Sorter->value;
					Sorter->value = Sorter2->value;
					Sorter2->value = x;

				}
				Sorter2 = Sorter2->next;
			}
			Sorter = Sorter->next;
		}
	}
	if (choice == 'Y') {
		Student x;
		for (int i = 0; i < size(currNode); i++) {
			Sorter2 = Sorter->next;
			while (Sorter2 != currNode) {
				if (Sorter->value.getYear() > Sorter2->value.getYear()) {
					x = Sorter->value;
					Sorter->value = Sorter2->value;
					Sorter2->value = x;

				}
				Sorter2 = Sorter2->next;
			}
			Sorter = Sorter->next;
		}
	}
	if (choice == 'G') {
		Student x;
		for (int i = 0; i < size(currNode); i++) {
			Sorter2 = Sorter->next;
			while (Sorter2 != currNode) {
				if (Sorter->value.getGPA() > Sorter2->value.getGPA()) {
					x = Sorter->value;
					Sorter->value = Sorter2->value;
					Sorter2->value = x;

				}
				Sorter2 = Sorter2->next;
			}
			Sorter = Sorter->next;
		}
	}

	std::cout << "\n\nPress enter to continue...";
	std::cin.ignore();
	std::cin.get();

}
#endif/*
 *d_dnodeBase.h
 *definition of dnode class
 *Author: Florent Dondjeu Tschoufack
 *Created: November 29, 2019
 *Current: November 29, 2019
 */




