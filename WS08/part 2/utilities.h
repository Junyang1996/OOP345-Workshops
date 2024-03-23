/*************************************************************************************
 *
 * Student Name : Lawrence Wan
 * Student ID  :105442230
 * Course/Section: OOP244/NBB 2237
 * * Seneca Email: jwan27@myseneca.ca
 * Completion date: Mar 23, 2024
 *
 *
 * I have done all the coding by myself and only copied the code that my professor
 * provided to complete my workshops and assignments.
 *
 **************************************************************************************/

#ifndef SENECA_UTILITIES_H
#define SENECA_UTILITIES_H

#include "list.h"
#include "element.h"

namespace seneca
{
	List<Product> mergeRaw(const List<Description> &desc, const List<Price> &price);
	List<Product> mergeSmart(const List<Description> &desc, const List<Price> &price);
}

#endif