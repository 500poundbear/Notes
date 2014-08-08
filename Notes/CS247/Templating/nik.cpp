#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>


int plusOne ( int i ) {
  return i + 1;
}

struct Multiplier : public std::binary_function <int , int , int > {
  int operator()( int a, int b ) const {
  return a * b;
  }
};

struct Integer {
  explicit Integer ( int i ) : m_i ( i ) {}
  void increment(){ m_i ++; }
  friend std::ostream & operator <<(std::ostream &, const Integer & ) ;
private:
  int m_i;
};

std::ostream& operator <<( std::ostream & os , const Integer & i ) {
  os << i. m_i;
  return os;
}

int main(){
  std::vector <int > nums ;
  std::vector < Integer > ints ;

  for ( int i = 0; i < 10; i++ ) {
    nums.push_back ( i );
    ints.push_back ( Integer ( i ) );
  }

  std::vector <int > nums2 ( nums );
  std::ostream_iterator<int> o( std::cout , ", " );

  // ptr_fun
  std::transform ( nums.begin(), nums.end(), o, std::ptr_fun ( plusOne ) ) ;
  std::cout << std::endl ;
  // bind
  Multiplier theMult ;
  std::transform ( nums.begin(), nums.end(), o, std::bind2nd ( theMult , 10 ) );
  std::cout << std::endl ;
  // mem_fun
  std::ostream_iterator < Integer > os( std::cout , ", " );
  std::for_each ( ints.begin(), ints.end(), std::mem_fun_ref ( & Integer::increment ) );
  std::copy ( ints.begin(), ints.end(), os );
  std::cout << std::endl ;
return 0;
}
