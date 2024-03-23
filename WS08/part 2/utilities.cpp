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

#include <memory>
#include "list.h"
#include "element.h"
#include "utilities.h"

using namespace std;

namespace seneca
{
	List<Product> mergeRaw(const List<Description> &desc, const List<Price> &price)
	{
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers

		for (auto i = 0u; i < desc.size(); i++)
		{
			for (auto j = 0u; j < price.size(); j++)
			{
				if (desc[i].code == price[j].code)
				{
					Product *temp = nullptr;
					temp = new Product(desc[i].desc, price[j].price);

					try
					{
						temp->validate();
					}
					catch (...)
					{
						delete temp;
						throw;
					}
					priceList += temp;
					delete temp;
				}
			}
		}

		return priceList;
	}
	List<Product> mergeSmart(const List<Description> &desc, const List<Price> &price)
	{
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
		for (auto i = 0u; i < desc.size(); i++)
		{
			for (auto j = 0u; j < price.size(); j++)
			{
				if (desc[i].code == price[j].code)
				{
					std::unique_ptr<Product> temp(new Product(desc[i].desc, price[j].price));

					try
					{
						temp->validate();
					}
					catch (...)
					{
						throw;
					}
					priceList += std::move(temp);
				}
			}
		}

		return priceList;
	}
}