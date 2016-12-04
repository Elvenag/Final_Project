/*
CARD GAME PROJECT
Mathis Marcotte, 7677347
Mathieu Perron, 7698299
DiscardPile CLASS CPP FILE
*/

#include "DiscardPile.h"

DiscardPile & DiscardPile::operator+=(Card * c)
{
	dp.push_back(c);
	return *this;
}

DiscardPile::~DiscardPile()
{
	for (auto c : dp) {
		delete c;
	}
}

Card * DiscardPile::pickUp()
{
	auto drawn = dp.back();
	dp.pop_back();
	return drawn;
}

Card * DiscardPile::top() const
{
	auto top = dp.back();
	return top;
}

void DiscardPile::print(std::ostream & os)
{
	for (auto c : dp)
		os << c;
}

ostream& operator<<(ostream& os,const DiscardPile& Grave){
	os << Grave.top();
	return os;
}
