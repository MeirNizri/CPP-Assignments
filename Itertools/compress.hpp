/**
 * This class receives as input two containers or container-like, which must be the same length. 
 * The first includes objects of some kind, and the second must include Boolean objects. 
 * Returns a new container-like container that contains elements from the first container, 
 * which corresponds to them in the second container is true.
 * 
 * Author: Meir Nizri
 * Fifth assignment in cpp course
 * Date: 2020-06
 */

#pragma once

using namespace std;
namespace itertools {

    template <typename C, typename C_bool> class compress {
        C cont;
        C_bool cont_bool;
        
    public:
        compress(C c, C_bool c_bool) : cont(c), cont_bool(c_bool) {}
    
        // Iterator of class compress
        class iterator{
            typename C::iterator itr_cont;  
            typename C::iterator itr_cont_end;
            typename C_bool::iterator itr_bool; 
            decltype(*(cont.begin())) current_true;

        public:
            iterator(typename C::iterator beg, typename C::iterator end, typename C_bool::iterator it_bool)
                : itr_cont(beg), itr_cont_end(end), itr_bool(it_bool), current_true(*beg)
            {
                while(itr_cont != itr_cont_end) {
                    if(*itr_bool) {
                        current_true = *itr_cont;
                        break;
                    }
                    itr_cont++;
                    itr_bool++;
                }
            }

            auto operator*() const {
                return current_true;
            }
            
            iterator& operator++() {
                itr_cont++;
                itr_bool++;
                while(itr_cont != itr_cont_end) {
                    if(*itr_bool) {
                        current_true = *itr_cont;
                        break;
                    }
                    itr_cont++;
                    itr_bool++;
                }
			    return *this;
    		}
    		
    		const iterator operator++(int) {
    			iterator tmp = *this;
                itr_cont++;
                itr_bool++;
                while(itr_cont != itr_cont_end) {
                    if(*itr_bool) {
                        current_true = *itr_cont;
                        break;
                    }
                    itr_cont++;
                    itr_bool++;
                }
			    return tmp;
    		}

            bool operator==(const iterator& it) const {
			    return itr_cont == it.itr_cont;
		    }

    		bool operator!=(const iterator& it) const {
			    return itr_cont != it.itr_cont;
    		}
    	};  // END OF CLASS ITERATOR


    	iterator begin() {
    		return iterator{cont.begin(), cont.end(), cont_bool.begin()};
    	}

    	iterator end() {
    		return iterator{cont.end(), cont.end(), cont_bool.end()};
    	}
    }; 
}