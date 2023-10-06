//Nick Widmer
// 1-26-2023
// header file





#ifndef CS2_BIGINT_HPP_
#define CS2_BIGINT_HPP_

const int capacity = 400;

class bigint{
public:

bigint();
bigint(int);
bigint(const char[]);
void debugPrint(std::ostream&) const;
bool operator==(const bigint);
bigint operator+(const bigint&) const;
int operator[](int) const;
bigint times_digit(int) const;
bigint times10(int) const;
bigint operator*(bigint);

friend std::ostream& operator<<(std::ostream&, bigint);
friend std::istream& operator>> (std::istream&, bigint&);


private:
int bi[capacity];


};
#endif

