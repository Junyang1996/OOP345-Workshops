#include <memory>
#include <algorithm>
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
}
