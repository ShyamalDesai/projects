
template <typename T>
struct Adder
{
	Adder() : _sum(0) {}
	void operator () (const T value)
	{
		_sum += value;
	}
	T getSum() const { return _sum; }
private:
	T _sum;
};
