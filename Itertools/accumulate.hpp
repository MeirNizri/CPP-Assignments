/**
 * This class receives as any Container or Container-like input. 
 * it returns container-like that include partial sums. 
 * Another version can get another parameter which is a binary functure (with two arguments), 
 * and use it instead of a sum. 
 * 
 * Author: Meir Nizri
 * Fifth assignment in cpp course
 * Date: 2020-06
 */

#pragma once
#include <iostream>
using namespace std;
namespace itertools {
    
    class add{
    public:
        template <typename T> T operator()(T a, T b) const {
            return a + b;
        }
    };


    template <typename C, typename F=add> class accumulate {
        C cont;
        F func;

    public:
        accumulate(C c, F f = add()) : cont(c), func(f) {}
      
        // Iterator of class accumulate
        class iterator {
            typename C::iterator itr;
            typename C::iterator itr_end;
            typename C::value_type sum;
            F func;

        public:
            iterator(typename C::iterator beg, typename C::iterator end, F f)
                : itr(beg), itr_end(end), func(f), sum(*beg) {}
                
            iterator(typename C::iterator beg, typename C::iterator end)
                : itr(beg), itr_end(end) {}
 
            auto operator*() const {
                return sum;
            }
            
            iterator& operator++() {
                itr++;
                if(itr != itr_end) 
                    sum = func(sum, *itr);
			    return *this;
    		}
    		
    		const iterator operator++(int) {
    			iterator tmp = *this;
                itr++;
                if(itr != itr_end) 
                    sum = func(sum, *itr);
			    return tmp;
    		}

            bool operator==(const iterator& it) const {
			    return itr == it.itr;
		    }

    		bool operator!=(const iterator& it) const {
			    return itr != it.itr;
    		}
    	};  // END OF CLASS ITERATOR


    	iterator begin() {
    		return iterator{cont.begin(), cont.end(), func};
    	}

    	iterator end() {
    		return iterator{cont.end(), cont.end()};
    	}
    }; 
}