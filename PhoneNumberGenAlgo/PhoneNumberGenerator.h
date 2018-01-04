#pragma once
template <class IMPL>
class PhoneNumberGenerator : public IMPL
{
public:
	PhoneNumberGenerator() {}
	~PhoneNumberGenerator() {}

	const std::vector <int>& getMovesFromPosition(const int val) const
	{
		return IMPL::getMovesFromPosition(val);
	}
};

