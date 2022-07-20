/*
 * huff_string.hpp
 *
 *  Created on: May 18, 2015
 *      Author: nicola
 *
 *  Huffman-compressed string with access/rank/select. The class is a wrapper on sdsl::wt_huff, with a simpler constructor
 */

#ifndef HUFF_STRING_HPP_
#define HUFF_STRING_HPP_

#include <sdsl/wavelet_trees.hpp>

using namespace sdsl;
using namespace std;

namespace ri{

class huff_string{

public:

	huff_string(){}

	huff_string(string &s){

		s.push_back(0);
		construct_im(wt, s.c_str(), 1);

		assert(wt.size()==s.size()-1);

	}

	inline uchar operator[](ulint i) const{

		assert(i<wt.size());
		return wt[i];

	}

	inline ulint size() const{
		return wt.size();
	}

	inline ulint rank(ulint i, uchar c) const{

		assert(i<=wt.size());
		return wt.rank(i,c);

	}

	/*
	 * position of i-th character c. i starts from 0!
	 */
	inline ulint select(ulint i, uchar c) const{

		return wt.select(i+1,c);

	}

	/* serialize the structure to the ostream
	 * \param out	 the ostream
	 */
	inline ulint serialize(std::ostream& out) const{

		return wt.serialize(out);

	}

	/* load the structure from the istream
	 * \param in the istream
	 */
	void load(std::istream& in) {

		wt.load(in);

	}

private:

	//wt_gmr<> wt;

	wt_huff<> wt;

};

}

#endif /* HUFF_STRING_HPP_ */
