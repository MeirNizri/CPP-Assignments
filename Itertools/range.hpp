/**
 * This class receives as input two integers, and represents all numbers from first to last, 
 * including the first and not the last.
 * 
 * Author: Meir Nizri
 * Fifth assignment in cpp course
 * Date: 2020-06
 */

#pragma once

namespace itertools {

    class range {
        int start;
        int finish;

    public:
        typedef int value_type;
        range(int s, int f) : start(s), finish(f) {}

        // Iterator of class range
        class iterator {
            int current_value;

    	public:
    		iterator(int c) : current_value(c) {}

    		int operator*() const {
    			return current_value;
    		}

		    iterator& operator++() {
			current_value++;
			return *this;
    		}

    		const iterator operator++(int) {
    			iterator tmp = *this;
			    current_value++;
			    return tmp;
    		}

		    bool operator==(const iterator& it) const {
			    return current_value == it.current_value;
		    }

    		bool operator!=(const iterator& it) const {
    			return current_value != it.current_value;
    		}
    	};  // END OF CLASS ITERATOR


    	iterator begin() {
    		return iterator{start};
    	}

    	iterator end() {
    		return iterator{finish};
    	}
    }; 
}