#pragma once
// lang::CwC

#include <stdlib.h>

class Object {
public:
	size_t hash_;

	Object() { 
		hash_ = 0; 
	}

	virtual ~Object() {}

	size_t hash() {
		if (hash_ == 0)
			hash_ = hash_me_(); ///Compute the hash
		return hash_;
	}

	virtual size_t hash_me_() {
		return reinterpret_cast<size_t>(this);
	}

	virtual bool equals(Object* other) {
		return this == other;
	}

};
