/**
 * This class receives as input two parameters: the first is a boolean functore representing a condition, 
 * and the second is a container or container-like. 
 * Returns a new container-like, which includes only the elements in the given container-like, 
 * that fulfill the condition.
 * 
 * Author: Meir Nizri
 * Fifth assignment in cpp course
 * Date: 2020-06
 */

#pragma once

using namespace std;
namespace itertools {

    template <typename F, typename C> class filterfalse {
        C cont;
        F func;
        
    public:
        filterfalse(F f, C c) : func(f), cont(c) {}
    
        // Iterator of class current_falsefalse
        class iterator {
            typename C::iterator itr;
            typename C::iterator itr_end;
            typename C::value_type current_false;
            F func;

        public:
            iterator(typename C::iterator beg, typename C::iterator end, F f)
                : itr(beg), itr_end(end), func(f), current_false(*beg) {
                
                while(itr != itr_end) {
                    if(!func(*itr)) {
                        current_false = *itr;
                        break;
                    }
                    itr++;
                }
            }
 
            auto operator*() const {
                return current_false;
            }
            
            iterator& operator++() {
                itr++;
                while(itr != itr_end) {
                    if(!func(*itr)) {
                        current_false = *itr;
                        break;
                    }
                    itr++;
                }
			    return *this;
    		}
    		
    		const iterator operator++(int) {
    			iterator tmp = *this;
			    itr++;
                while(itr != itr_end) {
                    if(!func(*itr)) {
                        current_false = *itr;
                        break;
                    }
                    itr++;
                }
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
    		return iterator{cont.end(), cont.end(), func};
    	}
    }; 
}